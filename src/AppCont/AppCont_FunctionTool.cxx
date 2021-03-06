// Copyright (c) 1995-1999 Matra Datavision
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

#include <AppCont_FunctionTool.ixx>

#include <AppCont_Function.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>


Standard_Real AppCont_FunctionTool::FirstParameter
  (const AppCont_Function& F) 
{
  return F.FirstParameter();
}

Standard_Real AppCont_FunctionTool::LastParameter
  (const AppCont_Function& F) 
{
  return F.LastParameter();
}

Standard_Integer AppCont_FunctionTool::NbP2d
  (const AppCont_Function&)
{
  return (0);
}


Standard_Integer AppCont_FunctionTool::NbP3d
  (const AppCont_Function&)
{
  return (1);
}

void AppCont_FunctionTool::Value(const AppCont_Function& F,
			      const Standard_Real U, 
			      TColgp_Array1OfPnt& tabPt)
{
  tabPt(tabPt.Lower()) = F.Value(U);
}




Standard_Boolean AppCont_FunctionTool::D1
  (const AppCont_Function& F,
   const Standard_Real U,
   TColgp_Array1OfVec& tabV)
{
  gp_Pnt P;
  gp_Vec V;
  Standard_Boolean Ok = F.D1(U, P, V);
  tabV(tabV.Lower()) = V;
  return Ok;
}






void AppCont_FunctionTool::Value(const AppCont_Function&,
			      const Standard_Real, 
			      TColgp_Array1OfPnt2d&)
{
}


void AppCont_FunctionTool::Value(const AppCont_Function&,
			      const Standard_Real, 
			      TColgp_Array1OfPnt&,
			      TColgp_Array1OfPnt2d&)
{
}



Standard_Boolean AppCont_FunctionTool::D1
  (const AppCont_Function&,
   const Standard_Real,
   TColgp_Array1OfVec2d&)
{
  return (Standard_True);
}


Standard_Boolean AppCont_FunctionTool::D1
  (const AppCont_Function&,
   const Standard_Real,
   TColgp_Array1OfVec&,
   TColgp_Array1OfVec2d&)
{
  return (Standard_True);
}

