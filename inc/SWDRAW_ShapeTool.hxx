// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _SWDRAW_ShapeTool_HeaderFile
#define _SWDRAW_ShapeTool_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

class Draw_Interpretor;


//! Defines functions to control shapes (in way useful for XSTEP), <br>
//!           additional features which should be basic, or call tools which <br>
//!           are bound with transfer needs. <br>
//!           But these functions work on shapes, geometry, nothing else <br>
//!           (no file, no model, no entity) <br>
class SWDRAW_ShapeTool  {
public:

  DEFINE_STANDARD_ALLOC

  //! Defines and loads all basic functions for SWDRAW on Shapes <br>
  Standard_EXPORT   static  void InitCommands(Draw_Interpretor& theCommands) ;





protected:





private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif
