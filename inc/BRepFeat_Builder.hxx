// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepFeat_Builder_HeaderFile
#define _BRepFeat_Builder_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _BOPCol_MapOfShape_HeaderFile
#include <BOPCol_MapOfShape.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _BOPAlgo_BOP_HeaderFile
#include <BOPAlgo_BOP.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _BOPCol_ListOfShape_HeaderFile
#include <BOPCol_ListOfShape.hxx>
#endif
#ifndef _BOPCol_DataMapOfShapeListOfShape_HeaderFile
#include <BOPCol_DataMapOfShapeListOfShape.hxx>
#endif
#ifndef _BOPCol_DataMapOfShapeShape_HeaderFile
#include <BOPCol_DataMapOfShapeShape.hxx>
#endif
#ifndef _BOPCol_BaseAllocator_HeaderFile
#include <BOPCol_BaseAllocator.hxx>
#endif
class TopoDS_Shape;
class TopTools_ListOfShape;
class TopoDS_Face;


//! Provides a basic tool to implement features topological <br>
//!          operations. The main goal of the algorithm is to perform <br>
//!          the result of the operation according to the <br>
//!          kept parts of the tool. <br>
//!          Input data: a) DS; <br>
//!                      b) The kept parts of the tool; <br>
//!                         If the map of the kept parts of the tool <br>
//!                         is not filled boolean operation of the <br>
//!                         given type will be performed; <br>
//!                      c) Operation required. <br>
//!          Steps: a) Fill myShapes, myRemoved maps; <br>
//!                 b) Rebuild edges and faces; <br>
//!                 c) Build images of the object; <br>
//!                 d) Build the result of the operation. <br>
//!          Result: Result shape of the operation required. <br>
class BRepFeat_Builder  : public BOPAlgo_BOP {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   BRepFeat_Builder();
Standard_EXPORT virtual ~BRepFeat_Builder();
  //!  Clears internal fields and arguments. <br>
  Standard_EXPORT   virtual  void Clear() ;
  //! Initialyzes the object of local boolean operation. <br>
//! <br>
  Standard_EXPORT     void Init(const TopoDS_Shape& theShape) ;
  //! Initialyzes the arguments of local boolean operation. <br>
//! <br>
  Standard_EXPORT     void Init(const TopoDS_Shape& theShape,const TopoDS_Shape& theTool) ;
  //! Sets the operation of local boolean operation. <br>
//!          If theFuse = 0 than the operation is CUT, otherwise FUSE. <br>
  Standard_EXPORT     void SetOperation(const Standard_Integer theFuse) ;
  //! Sets the operation of local boolean operation. <br>
//!          If theFlag = TRUE it means that no selection of parts <br>
//!          of the tool is needed, t.e. no second part. In that case <br>
//!          if theFuse = 0 than operation is COMMON, otherwise CUT21. <br>
//!          If theFlag = FALSE SetOperation(theFuse) function  is called. <br>
  Standard_EXPORT     void SetOperation(const Standard_Integer theFuse,const Standard_Boolean theFlag) ;
  //! Collects parts of the tool. <br>
  Standard_EXPORT     void PartsOfTool(TopTools_ListOfShape& theLT) ;
  //! Initialyzes parts of the tool for second step of algorithm. <br>
//!          Collects shapes and all sub-shapes into myShapes map. <br>
  Standard_EXPORT     void KeepParts(const TopTools_ListOfShape& theIm) ;
  //! Adds shape theS and all its sub-shapes into myShapes map. <br>
//! <br>
  Standard_EXPORT     void KeepPart(const TopoDS_Shape& theS) ;
  //! Main function to build the result of the <br>
//!          local operation required. <br>
  Standard_EXPORT     void PerformResult() ;
  //! Rebuilds faces in accordance with the kept parts of the tool. <br>
//! <br>
  Standard_EXPORT     void RebuildFaces() ;
  //! Rebuilds edges in accordance with the kept parts of the tool. <br>
//! <br>
  Standard_EXPORT     void RebuildEdge(const TopoDS_Shape& theE,const TopoDS_Face& theF,const BOPCol_MapOfShape& theME,BOPCol_ListOfShape& aLEIm) ;
  //! Collects the images of the object, that contains in <br>
//!          the images of the tool. <br>
  Standard_EXPORT     void CheckSolidImages() ;
  //! Collects the removed parts of the tool into myRemoved map. <br>
//! <br>
  Standard_EXPORT     void FillRemoved() ;
  //! Adds the shape S and its sub-shapes into myRemoved map. <br>
//! <br>
  Standard_EXPORT     void FillRemoved(const TopoDS_Shape& theS,BOPCol_MapOfShape& theM) ;





protected:

  //! Prepares builder of local operation. <br>
//! <br>
  Standard_EXPORT   virtual  void Prepare() ;
  //! Function is redefined to avoid the usage of removed faces. <br>
//! <br>
  Standard_EXPORT   virtual  void FillIn3DParts(BOPCol_DataMapOfShapeListOfShape& theInParts,BOPCol_DataMapOfShapeShape& theDraftSolids,const BOPCol_BaseAllocator& theAllocator) ;


BOPCol_MapOfShape myShapes;
BOPCol_MapOfShape myRemoved;
Standard_Integer myFuse;


private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif
