// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _ShapeCustom_ConvertToBSpline_HeaderFile
#define _ShapeCustom_ConvertToBSpline_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_ShapeCustom_ConvertToBSpline_HeaderFile
#include <Handle_ShapeCustom_ConvertToBSpline.hxx>
#endif

#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _BRepTools_Modification_HeaderFile
#include <BRepTools_Modification.hxx>
#endif
#ifndef _Handle_Geom_Surface_HeaderFile
#include <Handle_Geom_Surface.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Handle_Geom_Curve_HeaderFile
#include <Handle_Geom_Curve.hxx>
#endif
#ifndef _Handle_Geom2d_Curve_HeaderFile
#include <Handle_Geom2d_Curve.hxx>
#endif
#ifndef _GeomAbs_Shape_HeaderFile
#include <GeomAbs_Shape.hxx>
#endif
class TopoDS_Face;
class Geom_Surface;
class TopLoc_Location;
class TopoDS_Edge;
class Geom_Curve;
class TopoDS_Vertex;
class gp_Pnt;
class Geom2d_Curve;


//! implement a modification for BRepTools <br>
//!          Modifier algortihm. Converts Surface of <br>
//!          Linear Exctrusion, Revolution and Offset <br>
//!          surfaces into BSpline Surface according to <br>
//!          flags. <br>
class ShapeCustom_ConvertToBSpline : public BRepTools_Modification {

public:

  
  Standard_EXPORT   ShapeCustom_ConvertToBSpline();
  //! Sets mode for convertion of Surfaces of Linear <br>
//!          extrusion. <br>
  Standard_EXPORT     void SetExtrusionMode(const Standard_Boolean extrMode) ;
  //! Sets mode for convertion of Surfaces of Revolution. <br>
  Standard_EXPORT     void SetRevolutionMode(const Standard_Boolean revolMode) ;
  //! Sets mode for convertion of Offset surfaces. <br>
  Standard_EXPORT     void SetOffsetMode(const Standard_Boolean offsetMode) ;
  //! Sets mode for convertion of Plane surfaces. <br>
  Standard_EXPORT     void SetPlaneMode(const Standard_Boolean planeMode) ;
  //! Returns Standard_True if the face <F> has  been <br>
//!          modified. In this case, <S> is the new geometric <br>
//!          support of the face, <L> the new location,  <Tol> <br>
//!          the new tolerance.  Otherwise, returns <br>
//!          Standard_False, and <S>, <L>, <Tol> are  not <br>
//!          significant. <br>
  Standard_EXPORT     Standard_Boolean NewSurface(const TopoDS_Face& F,Handle(Geom_Surface)& S,TopLoc_Location& L,Standard_Real& Tol,Standard_Boolean& RevWires,Standard_Boolean& RevFace) ;
  //! Returns Standard_True  if  the edge  <E> has  been <br>
//!          modified.  In this case,  <C> is the new geometric <br>
//!          support of the  edge, <L> the  new location, <Tol> <br>
//!          the         new    tolerance.   Otherwise, returns <br>
//!          Standard_False,    and  <C>,  <L>,   <Tol> are not <br>
//!          significant. <br>
  Standard_EXPORT     Standard_Boolean NewCurve(const TopoDS_Edge& E,Handle(Geom_Curve)& C,TopLoc_Location& L,Standard_Real& Tol) ;
  //! Returns  Standard_True if the  vertex <V> has been <br>
//!          modified.  In this  case, <P> is the new geometric <br>
//!          support of the vertex,   <Tol> the new  tolerance. <br>
//!          Otherwise, returns Standard_False, and <P>,  <Tol> <br>
//!          are not significant. <br>
  Standard_EXPORT     Standard_Boolean NewPoint(const TopoDS_Vertex& V,gp_Pnt& P,Standard_Real& Tol) ;
  //! Returns Standard_True if  the edge  <E> has a  new <br>
//!          curve on surface on the face <F>.In this case, <C> <br>
//!          is the new geometric support of  the edge, <L> the <br>
//!          new location, <Tol> the new tolerance. <br>
//! <br>
//!          Otherwise, returns  Standard_False, and <C>,  <L>, <br>
//!          <Tol> are not significant. <br>
//! <br>
//!          <NewE> is the new  edge created from  <E>.  <NewF> <br>
//!          is the new face created from <F>. They may be usefull. <br>
  Standard_EXPORT     Standard_Boolean NewCurve2d(const TopoDS_Edge& E,const TopoDS_Face& F,const TopoDS_Edge& NewE,const TopoDS_Face& NewF,Handle(Geom2d_Curve)& C,Standard_Real& Tol) ;
  //! Returns Standard_True if the Vertex  <V> has a new <br>
//!          parameter on the  edge <E>. In  this case,  <P> is <br>
//!          the parameter,    <Tol>  the     new    tolerance. <br>
//!          Otherwise, returns Standard_False, and <P>,  <Tol> <br>
//!          are not significant. <br>
  Standard_EXPORT     Standard_Boolean NewParameter(const TopoDS_Vertex& V,const TopoDS_Edge& E,Standard_Real& P,Standard_Real& Tol) ;
  //! Returns the  continuity of  <NewE> between <NewF1> <br>
//!          and <NewF2>. <br>
//! <br>
//!          <NewE> is the new  edge created from <E>.  <NewF1> <br>
//!          (resp. <NewF2>) is the new  face created from <F1> <br>
//!          (resp. <F2>). <br>
  Standard_EXPORT     GeomAbs_Shape Continuity(const TopoDS_Edge& E,const TopoDS_Face& F1,const TopoDS_Face& F2,const TopoDS_Edge& NewE,const TopoDS_Face& NewF1,const TopoDS_Face& NewF2) ;




  DEFINE_STANDARD_RTTI(ShapeCustom_ConvertToBSpline)

protected:




private: 

  
  Standard_EXPORT     Standard_Boolean IsToConvert(const Handle(Geom_Surface)& S,Handle(Geom_Surface)& SS) const;

Standard_Boolean myExtrMode;
Standard_Boolean myRevolMode;
Standard_Boolean myOffsetMode;
Standard_Boolean myPlaneMode;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
