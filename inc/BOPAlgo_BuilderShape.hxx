// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BOPAlgo_BuilderShape_HeaderFile
#define _BOPAlgo_BuilderShape_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TopoDS_Shape_HeaderFile
#include <TopoDS_Shape.hxx>
#endif
#ifndef _TopTools_ListOfShape_HeaderFile
#include <TopTools_ListOfShape.hxx>
#endif
#ifndef _BOPCol_MapOfShape_HeaderFile
#include <BOPCol_MapOfShape.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _BOPCol_IndexedDataMapOfShapeListOfShape_HeaderFile
#include <BOPCol_IndexedDataMapOfShapeListOfShape.hxx>
#endif
#ifndef _BOPAlgo_Algo_HeaderFile
#include <BOPAlgo_Algo.hxx>
#endif
#ifndef _BOPCol_BaseAllocator_HeaderFile
#include <BOPCol_BaseAllocator.hxx>
#endif
class TopoDS_Shape;
class TopTools_ListOfShape;


//! Root class for algorithms that has shape as result <br>
class BOPAlgo_BuilderShape  : public BOPAlgo_Algo {
public:

  DEFINE_STANDARD_ALLOC

  //!  Returns the result of algorithm <br>
  Standard_EXPORT    const TopoDS_Shape& Shape() const;
  //! Returns the list of shapes generated from the <br>
//!          shape theS. <br>
  Standard_EXPORT   virtual const TopTools_ListOfShape& Generated(const TopoDS_Shape& theS) ;
  //! Returns the list of shapes modified from the <br>
//!          shape theS. <br>
  Standard_EXPORT   virtual const TopTools_ListOfShape& Modified(const TopoDS_Shape& theS) ;
  //! Returns true if the shape theS has been deleted. <br>
  Standard_EXPORT   virtual  Standard_Boolean IsDeleted(const TopoDS_Shape& theS) ;
  //! Returns true if the at least one shape(or subshape) <br>
//!          of arguments has been deleted. <br>
  Standard_EXPORT     Standard_Boolean HasDeleted() const;
  //! Returns true if the at least one shape(or subshape) <br>
//!          of arguments has generated shapes. <br>
  Standard_EXPORT     Standard_Boolean HasGenerated() const;
  //! Returns true if the at least one shape(or subshape) <br>
//!          of arguments has modified shapes. <br>
  Standard_EXPORT     Standard_Boolean HasModified() const;
  
  Standard_EXPORT    const BOPCol_IndexedDataMapOfShapeListOfShape& ImagesResult() const;





protected:

  
  Standard_EXPORT   BOPAlgo_BuilderShape();
Standard_EXPORT virtual ~BOPAlgo_BuilderShape();
  
  Standard_EXPORT   BOPAlgo_BuilderShape(const BOPCol_BaseAllocator& theAllocator);
  //!  Prepare information for history support <br>
  Standard_EXPORT   virtual  void PrepareHistory() ;


TopoDS_Shape myShape;
TopTools_ListOfShape myHistShapes;
BOPCol_MapOfShape myMapShape;
Standard_Boolean myHasDeleted;
Standard_Boolean myHasGenerated;
Standard_Boolean myHasModified;
BOPCol_IndexedDataMapOfShapeListOfShape myImagesResult;
Standard_Boolean myFlagHistory;


private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif
