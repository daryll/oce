// Created on: 2001-08-24
// Created by: Alexnder GRIGORIEV
// Copyright (c) 2001-2012 OPEN CASCADE SAS
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


#include <BinMDataStd_CommentDriver.ixx>
#include <TDataStd_Comment.hxx>

//=======================================================================
//function : BinMDataStd_CommentDriver
//purpose  : Constructor
//=======================================================================

BinMDataStd_CommentDriver::BinMDataStd_CommentDriver
                        (const Handle(CDM_MessageDriver)& theMsgDriver)
      : BinMDF_ADriver (theMsgDriver, NULL)
{}

//=======================================================================
//function : NewEmpty
//purpose  : 
//=======================================================================
Handle(TDF_Attribute) BinMDataStd_CommentDriver::NewEmpty() const
{
  return (new TDataStd_Comment());
}

//=======================================================================
//function : Paste
//purpose  : 
//=======================================================================
Standard_Boolean BinMDataStd_CommentDriver::Paste
                                (const BinObjMgt_Persistent&  theSource,
                                 const Handle(TDF_Attribute)& theTarget,
                                 BinObjMgt_RRelocationTable&  ) const
{
  TCollection_ExtendedString aString;
  Standard_Boolean ok = theSource >> aString;
  if (ok)
    Handle(TDataStd_Comment)::DownCast(theTarget) -> Set (aString);
  return ok;
}

//=======================================================================
//function : Paste
//purpose  : 
//=======================================================================
void BinMDataStd_CommentDriver::Paste (const Handle(TDF_Attribute)& theSource,
                                       BinObjMgt_Persistent&        theTarget,
                                       BinObjMgt_SRelocationTable&  ) const
{
  TCollection_ExtendedString aName =
    Handle(TDataStd_Comment)::DownCast(theSource) -> Get();
  theTarget << aName;
}
