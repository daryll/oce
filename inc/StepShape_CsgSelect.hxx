// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepShape_CsgSelect_HeaderFile
#define _StepShape_CsgSelect_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Handle_StepShape_BooleanResult_HeaderFile
#include <Handle_StepShape_BooleanResult.hxx>
#endif
#ifndef _StepShape_CsgPrimitive_HeaderFile
#include <StepShape_CsgPrimitive.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class StepShape_BooleanResult;
class StepShape_CsgPrimitive;



class StepShape_CsgSelect  {
public:

  DEFINE_STANDARD_ALLOC

  //! Returns a CsgSelect SelectType <br>
  Standard_EXPORT   StepShape_CsgSelect();
  
  Standard_EXPORT     void SetTypeOfContent(const Standard_Integer aTypeOfContent) ;
  
  Standard_EXPORT     Standard_Integer TypeOfContent() const;
  //! returns Value as a BooleanResult (Null if another type) <br>
  Standard_EXPORT     Handle_StepShape_BooleanResult BooleanResult() const;
  
  Standard_EXPORT     void SetBooleanResult(const Handle(StepShape_BooleanResult)& aBooleanResult) ;
  //! returns Value as a CsgPrimitive (Null if another type) <br>
  Standard_EXPORT     StepShape_CsgPrimitive CsgPrimitive() const;
  
  Standard_EXPORT     void SetCsgPrimitive(const StepShape_CsgPrimitive& aCsgPrimitive) ;





protected:





private:



Handle_StepShape_BooleanResult theBooleanResult;
StepShape_CsgPrimitive theCsgPrimitive;
Standard_Integer theTypeOfContent;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
