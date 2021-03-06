// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _ShapeUpgrade_HeaderFile
#define _ShapeUpgrade_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_Geom_BSplineCurve_HeaderFile
#include <Handle_Geom_BSplineCurve.hxx>
#endif
#ifndef _Handle_TColGeom_HSequenceOfBoundedCurve_HeaderFile
#include <Handle_TColGeom_HSequenceOfBoundedCurve.hxx>
#endif
#ifndef _Handle_Geom2d_BSplineCurve_HeaderFile
#include <Handle_Geom2d_BSplineCurve.hxx>
#endif
#ifndef _Handle_TColGeom2d_HSequenceOfBoundedCurve_HeaderFile
#include <Handle_TColGeom2d_HSequenceOfBoundedCurve.hxx>
#endif
class Geom_BSplineCurve;
class TColGeom_HSequenceOfBoundedCurve;
class Geom2d_BSplineCurve;
class TColGeom2d_HSequenceOfBoundedCurve;
class ShapeUpgrade_Tool;
class ShapeUpgrade_EdgeDivide;
class ShapeUpgrade_ClosedEdgeDivide;
class ShapeUpgrade_WireDivide;
class ShapeUpgrade_FaceDivide;
class ShapeUpgrade_ClosedFaceDivide;
class ShapeUpgrade_FaceDivideArea;
class ShapeUpgrade_ShapeDivide;
class ShapeUpgrade_ShapeDivideArea;
class ShapeUpgrade_ShapeDivideContinuity;
class ShapeUpgrade_ShapeDivideAngle;
class ShapeUpgrade_ShapeConvertToBezier;
class ShapeUpgrade_ShapeDivideClosed;
class ShapeUpgrade_ShapeDivideClosedEdges;
class ShapeUpgrade_SplitCurve;
class ShapeUpgrade_SplitCurve2d;
class ShapeUpgrade_SplitCurve2dContinuity;
class ShapeUpgrade_ConvertCurve2dToBezier;
class ShapeUpgrade_SplitCurve3d;
class ShapeUpgrade_SplitCurve3dContinuity;
class ShapeUpgrade_ConvertCurve3dToBezier;
class ShapeUpgrade_SplitSurface;
class ShapeUpgrade_SplitSurfaceContinuity;
class ShapeUpgrade_SplitSurfaceAngle;
class ShapeUpgrade_ConvertSurfaceToBezierBasis;
class ShapeUpgrade_SplitSurfaceArea;
class ShapeUpgrade_ShellSewing;
class ShapeUpgrade_FixSmallCurves;
class ShapeUpgrade_FixSmallBezierCurves;
class ShapeUpgrade_RemoveLocations;
class ShapeUpgrade_RemoveInternalWires;
class ShapeUpgrade_UnifySameDomain;


//!  This package provides tools <br>
//! for splitting and converting shapes by some criteria. It <br>
//! provides modifications of the kind when one topological <br>
//! object can be converted or splitted to several ones. In <br>
//! particular this package contains high level API classes which perform: <br>
//!      converting geometry of shapes up to given continuity, <br>
//!      splitting revolutions by U to segments less than given value, <br>
//!      converting to beziers, <br>
//!      splitting closed faces. <br>
class ShapeUpgrade  {
public:

  DEFINE_STANDARD_ALLOC

  //! Unifies same domain faces and edges of specified shape <br>
  Standard_EXPORT   static  Standard_Boolean C0BSplineToSequenceOfC1BSplineCurve(const Handle(Geom_BSplineCurve)& BS,Handle(TColGeom_HSequenceOfBoundedCurve)& seqBS) ;
  //! Converts C0 B-Spline curve into sequence of C1 B-Spline curves. <br>
//!           This method splits B-Spline at the knots with multiplicities <br>
//!           equal to degree, i.e. unlike method <br>
//!           GeomConvert::C0BSplineToArrayOfC1BSplineCurve this one does not <br>
//!           use any tolerance and therefore does not change the geometry of <br>
//!           B-Spline. <br>
//!           Returns True if C0 B-Spline was successfully splitted, else <br>
//!           returns False (if BS is C1 B-Spline). <br>
  Standard_EXPORT   static  Standard_Boolean C0BSplineToSequenceOfC1BSplineCurve(const Handle(Geom2d_BSplineCurve)& BS,Handle(TColGeom2d_HSequenceOfBoundedCurve)& seqBS) ;





protected:





private:




friend class ShapeUpgrade_Tool;
friend class ShapeUpgrade_EdgeDivide;
friend class ShapeUpgrade_ClosedEdgeDivide;
friend class ShapeUpgrade_WireDivide;
friend class ShapeUpgrade_FaceDivide;
friend class ShapeUpgrade_ClosedFaceDivide;
friend class ShapeUpgrade_FaceDivideArea;
friend class ShapeUpgrade_ShapeDivide;
friend class ShapeUpgrade_ShapeDivideArea;
friend class ShapeUpgrade_ShapeDivideContinuity;
friend class ShapeUpgrade_ShapeDivideAngle;
friend class ShapeUpgrade_ShapeConvertToBezier;
friend class ShapeUpgrade_ShapeDivideClosed;
friend class ShapeUpgrade_ShapeDivideClosedEdges;
friend class ShapeUpgrade_SplitCurve;
friend class ShapeUpgrade_SplitCurve2d;
friend class ShapeUpgrade_SplitCurve2dContinuity;
friend class ShapeUpgrade_ConvertCurve2dToBezier;
friend class ShapeUpgrade_SplitCurve3d;
friend class ShapeUpgrade_SplitCurve3dContinuity;
friend class ShapeUpgrade_ConvertCurve3dToBezier;
friend class ShapeUpgrade_SplitSurface;
friend class ShapeUpgrade_SplitSurfaceContinuity;
friend class ShapeUpgrade_SplitSurfaceAngle;
friend class ShapeUpgrade_ConvertSurfaceToBezierBasis;
friend class ShapeUpgrade_SplitSurfaceArea;
friend class ShapeUpgrade_ShellSewing;
friend class ShapeUpgrade_FixSmallCurves;
friend class ShapeUpgrade_FixSmallBezierCurves;
friend class ShapeUpgrade_RemoveLocations;
friend class ShapeUpgrade_RemoveInternalWires;
friend class ShapeUpgrade_UnifySameDomain;

};





// other Inline functions and methods (like "C++: function call" methods)


#endif
