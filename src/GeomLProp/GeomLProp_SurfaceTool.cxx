// Created on: 1992-08-18
// Created by: Herve LEGRAND
// Copyright (c) 1992-1999 Matra Datavision
// Copyright (c) 1999-2012 OPEN CASCADE SAS
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


#include <GeomLProp_SurfaceTool.ixx>
#include <Geom_Surface.hxx>
#include <GeomAbs_Shape.hxx>


void  GeomLProp_SurfaceTool::Value(const Handle_Geom_Surface& S,
	    const Standard_Real U, const Standard_Real V, gp_Pnt& P)
{
  P = S->Value(U, V);
}

void  GeomLProp_SurfaceTool::D1(const Handle_Geom_Surface& S, 
	 const Standard_Real U, const Standard_Real V, 
	 gp_Pnt& P, gp_Vec& D1U, gp_Vec& D1V)
{
  S->D1(U, V, P, D1U, D1V);
}

void  GeomLProp_SurfaceTool::D2(const Handle_Geom_Surface& S, 
	 const Standard_Real U, const Standard_Real V, 
	 gp_Pnt& P, gp_Vec& D1U, gp_Vec& D1V, gp_Vec& D2U, gp_Vec& D2V, gp_Vec& DUV)
{
  S->D2(U, V, P, D1U, D1V, D2U, D2V, DUV);
}

//=======================================================================
//function : DN
//purpose  : 
//=======================================================================
gp_Vec GeomLProp_SurfaceTool::DN(const Handle_Geom_Surface& S, 
				 const Standard_Real U, 
				 const Standard_Real V,
				 const Standard_Integer IU,
				 const Standard_Integer IV)
{
  return S->DN(U, V, IU, IV);
} 

Standard_Integer  GeomLProp_SurfaceTool::Continuity(const Handle_Geom_Surface& S)
{
  GeomAbs_Shape s = S->Continuity();
  switch (s) {
  case GeomAbs_C0:
    return 0;
  case GeomAbs_C1:
    return 1;
  case GeomAbs_C2:
    return 2;
  case GeomAbs_C3:
    return 3;
  case GeomAbs_G1:
    return 0;
  case GeomAbs_G2:
    return 0;
  case GeomAbs_CN:
    return 3;
  };
  return 0;
}

void  GeomLProp_SurfaceTool::Bounds(const Handle_Geom_Surface& S, 
				    Standard_Real& U1, Standard_Real& V1, 
				    Standard_Real& U2, Standard_Real& V2)
{
  S->Bounds(U1, U2, V1, V2);
}





