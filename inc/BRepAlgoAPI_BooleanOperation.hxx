// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepAlgoAPI_BooleanOperation_HeaderFile
#define _BRepAlgoAPI_BooleanOperation_HeaderFile

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
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _BOPAlgo_Operation_HeaderFile
#include <BOPAlgo_Operation.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _BOPAlgo_PPaveFiller_HeaderFile
#include <BOPAlgo_PPaveFiller.hxx>
#endif
#ifndef _BOPAlgo_PBOP_HeaderFile
#include <BOPAlgo_PBOP.hxx>
#endif
#ifndef _TopTools_DataMapOfShapeShape_HeaderFile
#include <TopTools_DataMapOfShapeShape.hxx>
#endif
#ifndef _BRepBuilderAPI_MakeShape_HeaderFile
#include <BRepBuilderAPI_MakeShape.hxx>
#endif
class TopoDS_Shape;
class BOPAlgo_PaveFiller;
class TopTools_ListOfShape;


//! The abstract class BooleanOperation is the root <br>
//! class of Boolean Operations (see Overview). <br>
//! Boolean Operations algorithm is divided onto two parts. <br>
//! -      The first one is computing interference between arguments. <br>
//! -      The second one is building the result of operation. <br>
//! The BooleanOperation class provides execution of both parts <br>
//! of the Boolean Operations algorithm. The second part <br>
//! (building the result) depends on given type of the Boolean <br>
//! Operation (see Constructor). <br>
class BRepAlgoAPI_BooleanOperation  : public BRepBuilderAPI_MakeShape {
public:

  DEFINE_STANDARD_ALLOC

  //!  Sets the type of Boolean operation to perform <br>
//!          It can be BOPAlgo_SECTION <br>
//!                    BOPAlgo_COMMON <br>
//!                    BOPAlgo_FUSE <br>
//!                    BOPAlgo_CUT <br>
//!                    BOPAlgo_CUT21 <br>
//! <br>
  Standard_EXPORT     void SetOperation(const BOPAlgo_Operation anOp) ;
  //! Provides the algorithm of Boolean Operations <br>
//! -      Filling interference Data Structure (if it is necessary) <br>
//! -      Building the result of the operation. <br>
  Standard_EXPORT   virtual  void Build() ;
  //! Returns the first shape involved in this Boolean operation. <br>
  Standard_EXPORT    const TopoDS_Shape& Shape1() const;
  //! Returns the second shape involved in this Boolean operation. <br>
  Standard_EXPORT    const TopoDS_Shape& Shape2() const;
  //! Returns the type of Boolean Operation that has been performed. <br>
  Standard_EXPORT     BOPAlgo_Operation Operation() const;
  //! Returns the flag of edge refining <br>
  Standard_EXPORT     Standard_Boolean FuseEdges() const;
  //! Fuse C1 edges <br>
  Standard_EXPORT     void RefineEdges() ;
  
  Standard_EXPORT     Standard_Boolean BuilderCanWork() const;
  //!  Returns the error status of operation. <br>
//! 0 - Ok <br>
//! 1 - The Object is created but Nothing is Done <br>
//! 2 - Null source shapes is not allowed <br>
//! 3 - Check types of the arguments <br>
//! 4 - Can not allocate memory for the DSFiller <br>
//! 5 - The Builder can not work with such types of arguments <br>
//! 6 - Unknown operation is not allowed <br>
//! 7 - Can not allocate memory for the Builder <br>
//!  > 100 - See the Builder's  ErrorStatus <br>
  Standard_EXPORT     Standard_Integer ErrorStatus() const;
  //! Returns the list  of shapes modified from the shape <S>. <br>
  Standard_EXPORT   virtual const TopTools_ListOfShape& Modified(const TopoDS_Shape& aS) ;
  //! Returns true if the shape S has been deleted. The <br>
//! result shape of the operation does not contain the shape S. <br>
  Standard_EXPORT   virtual  Standard_Boolean IsDeleted(const TopoDS_Shape& aS) ;
  //! Returns the list  of shapes modified from the shape <S>. <br>
//!         For use in BRepNaming. <br>
  Standard_EXPORT   virtual const TopTools_ListOfShape& Modified2(const TopoDS_Shape& aS) ;
  //! Returns the list  of shapes generated from the shape <S>. <br>
//!         For use in BRepNaming. <br>
  Standard_EXPORT   virtual const TopTools_ListOfShape& Generated(const TopoDS_Shape& S) ;
  //! Returns true if there is at least one modified shape. <br>
//!         For use in BRepNaming. <br>
  Standard_EXPORT   virtual  Standard_Boolean HasModified() const;
  //! Returns true if there is at least one generated shape. <br>
//!         For use in BRepNaming. <br>
  Standard_EXPORT   virtual  Standard_Boolean HasGenerated() const;
  //! Returns true if there is at least one deleted shape. <br>
//!         For use in BRepNaming. <br>
  Standard_EXPORT   virtual  Standard_Boolean HasDeleted() const;
  
  Standard_EXPORT     void Destroy() ;
Standard_EXPORT virtual ~BRepAlgoAPI_BooleanOperation(){Destroy();}
  //! Returns a list of section edges. <br>
//! The edges represent the result of intersection between arguments of <br>
//! Boolean Operation. They are computed during operation execution. <br>
  Standard_EXPORT    const TopTools_ListOfShape& SectionEdges() ;





protected:

  //! Prepares the operations for S1 and S2. <br>
  Standard_EXPORT   BRepAlgoAPI_BooleanOperation(const TopoDS_Shape& S1,const TopoDS_Shape& S2,const BOPAlgo_Operation anOperation);
  //! Prepares the operations for S1 and S2. <br>
  Standard_EXPORT   BRepAlgoAPI_BooleanOperation(const TopoDS_Shape& S1,const TopoDS_Shape& S2,const BOPAlgo_PaveFiller& aDSF,const BOPAlgo_Operation anOperation);
  
  Standard_EXPORT     Standard_Boolean PrepareFiller() ;


TopoDS_Shape myS1;
TopoDS_Shape myS2;
Standard_Boolean myBuilderCanWork;
BOPAlgo_Operation myOperation;
Standard_Integer myErrorStatus;
BOPAlgo_PPaveFiller myDSFiller;
BOPAlgo_PBOP myBuilder;


private:

  //! Returns the list  of shapes generated from the shape <S>. <br>
//!         For use in BRepNaming. <br>
  Standard_EXPORT    const TopTools_ListOfShape& RefinedList(const TopTools_ListOfShape& theL) ;


Standard_Integer myEntryType;
Standard_Boolean myFuseEdges;
TopTools_DataMapOfShapeShape myModifFaces;
TopTools_DataMapOfShapeShape myEdgeMap;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
