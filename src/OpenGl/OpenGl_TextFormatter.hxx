// Created on: 2013-01-29
// Created by: Kirill GAVRILOV
// Copyright (c) 2013 OPEN CASCADE SAS
//
// The content of this file is subject to the Open CASCADE Technology Public
// License Version 6.5 (the "License"). You may not use the content of this file
// except in compliance with the License. Please obtain a copy of the License
// at http://www.opencascade.org and read it completely before using this file.
//
// The Initial Developer of the Original Code is Open CASCADE S.A.S., having its
// main offices at: 1, place des Freres Montgolfier, 78280 Guyancourt, France.
//
// The Original Code and all software distributed under the License is
// distributed on an "AS IS" basis, without warranty of any kind, and the
// Initial Developer hereby disclaims all such warranties, including without
// limitation, any warranties of merchantability, fitness for a particular
// purpose or non-infringement. Please see the License for the specific terms
// and conditions governing the rights and limitations under the License.

#ifndef _OpenGl_TextFormatter_H__
#define _OpenGl_TextFormatter_H__

#include <OpenGl_Font.hxx>
#include <OpenGl_VertexBufferEditor.hxx>

#include <Graphic3d_HorizontalTextAlignment.hxx>
#include <Graphic3d_VerticalTextAlignment.hxx>

#include <NCollection_String.hxx>

typedef NCollection_Array1<OpenGl_Vec2> OpenGl_Vec2Array;
typedef NCollection_Handle<OpenGl_Vec2Array> Handle(OpenGl_Vec2Array);

//! This class intended to prepare formatted text.
class OpenGl_TextFormatter : public Standard_Transient
{

public:

  //! Default constructor.
  Standard_EXPORT OpenGl_TextFormatter();

  //! Setup alignment style.
  Standard_EXPORT void SetupAlignment (const Graphic3d_HorizontalTextAlignment theAlignX,
                                       const Graphic3d_VerticalTextAlignment   theAlignY);

  //! Reset current progress.
  Standard_EXPORT void Reset();

  //! Render specified text to inner buffer.
  Standard_EXPORT void Append (const Handle(OpenGl_Context)& theCtx,
                               const NCollection_String&     theString,
                               OpenGl_Font&                  theFont);

  //! Perform formatting on the buffered text.
  //! Should not be called more than once after initialization!
  Standard_EXPORT void Format();

  //! Retrieve formatting results.
  Standard_EXPORT void Result (NCollection_Vector<GLuint>& theTextures,
                               NCollection_Vector< NCollection_Handle <NCollection_Vector <OpenGl_Vec2> > >& theVertsPerTexture,
                               NCollection_Vector< NCollection_Handle <NCollection_Vector <OpenGl_Vec2> > >& theTCrdsPerTexture) const;

  //! Retrieve formatting results.
  Standard_EXPORT void Result (const Handle(OpenGl_Context)&                    theCtx,
                               NCollection_Vector<GLuint>&                      theTextures,
                               NCollection_Vector<Handle(OpenGl_VertexBuffer)>& theVertsPerTexture,
                               NCollection_Vector<Handle(OpenGl_VertexBuffer)>& theTCrdsPerTexture) const;

  //! Retrieve formatting results.
  Standard_EXPORT void Result (const Handle(OpenGl_Context)&                 theCtx,
                               NCollection_Vector<GLuint>&                   theTextures,
                               NCollection_Vector<Handle(OpenGl_Vec2Array)>& theVertsPerTexture,
                               NCollection_Vector<Handle(OpenGl_Vec2Array)>& theTCrdsPerTexture) const;

  //! @return width of formatted text.
  inline Standard_ShortReal ResultWidth() const
  {
    return myBndWidth;
  }

  //! @return height of formatted text.
  inline Standard_ShortReal ResultHeight() const
  {
    return myLineSpacing * Standard_ShortReal(myLinesNb);
  }

  //! @param bounding box.
  inline void BndBox (Font_FTFont::Rect& theBndBox) const
  {
    theBndBox.Left = 0.0f;
    switch (myAlignX)
    {
      default:
      case Graphic3d_HTA_LEFT:  theBndBox.Right  =  myBndWidth; break;
      case Graphic3d_HTA_RIGHT: theBndBox.Right  = -myBndWidth; break;
      case Graphic3d_HTA_CENTER:
      {
        theBndBox.Left  = -0.5f * myBndWidth;
        theBndBox.Right =  0.5f * myBndWidth;
        break;
      }
    }
    theBndBox.Top    = myBndTop;
    theBndBox.Bottom = theBndBox.Top - myLineSpacing * Standard_ShortReal(myLinesNb);
  }

protected: //! @name class auxiliary methods

  //! Move glyphs on the current line to correct position.
  Standard_EXPORT void newLine (const Standard_Integer theLastRect);

protected: //! @name configuration

  Graphic3d_HorizontalTextAlignment myAlignX;  //!< horizontal alignment style
  Graphic3d_VerticalTextAlignment   myAlignY;  //!< vertical   alignment style
  Standard_Integer                  myTabSize; //!< horizontal tabulation width (number of space symbols)

protected: //! @name input data

  NCollection_String myString;        //!< currently rendered text
  OpenGl_Vec2        myPen;           //!< current pen position
  NCollection_Vector<OpenGl_Font::Tile>
                     myRects;         //!< glyphs rectangles
  Standard_Integer   myRectsNb;       //!< rectangles number
  NCollection_Vector<Standard_ShortReal>
                     myNewLines;      //!< position at LF
  Standard_ShortReal myLineSpacing;   //!< line spacing (computed as maximum of all fonts involved in text formatting)
  Standard_ShortReal myAscender;      //!<
  bool               myIsFormatted;   //!< formatting state

protected:

  mutable OpenGl_VertexBufferEditor<OpenGl_Vec2> myVboEditor;

protected: //! @name temporary variables for formatting routines

  Standard_Integer   myLinesNb;       //!< overall (new)lines number (including splitting by width limit)
  Standard_Integer   myRectLineStart; //!< id of first rectangle on the current line
  Standard_Integer   myRectWordStart; //!< id of first rectangle in the current word
  Standard_Integer   myNewLineNb;

  Standard_ShortReal myPenCurrLine;   //!< current baseline position
  Standard_ShortReal myLineLeft;      //!< left x position of first glyph on line before formatting applied
  Standard_ShortReal myLineTail;
  Standard_ShortReal myBndTop;
  Standard_ShortReal myBndWidth;
  OpenGl_Vec2        myMoveVec;       //!< local variable

public:

  DEFINE_STANDARD_RTTI(OpenGl_TextFormatter) // Type definition

};

DEFINE_STANDARD_HANDLE(OpenGl_TextFormatter, Standard_Transient)

#endif // _OpenGl_TextFormatter_H__
