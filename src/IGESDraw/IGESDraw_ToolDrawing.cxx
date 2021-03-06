// Created by: CKY / Contract Toubro-Larsen
// Copyright (c) 1993-1999 Matra Datavision
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

//--------------------------------------------------------------------
//--------------------------------------------------------------------

#include <IGESDraw_ToolDrawing.ixx>
#include <IGESData_ParamCursor.hxx>
#include <IGESData_ViewKindEntity.hxx>
#include <IGESData_IGESEntity.hxx>
#include <gp_XY.hxx>
#include <gp_Pnt2d.hxx>
#include <IGESData_ViewKindEntity.hxx>
#include <TColgp_HArray1OfXY.hxx>
#include <IGESDraw_HArray1OfViewKindEntity.hxx>
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <Interface_Macros.hxx>
#include <IGESData_Dump.hxx>
#include <IGESDraw_View.hxx>
#include <IGESDraw_PerspectiveView.hxx>


IGESDraw_ToolDrawing::IGESDraw_ToolDrawing ()    {  }


void IGESDraw_ToolDrawing::ReadOwnParams
  (const Handle(IGESDraw_Drawing)& ent,
   const Handle(IGESData_IGESReaderData)& IR, IGESData_ParamReader& PR) const
{ 
  //Standard_Boolean st; //szv#4:S4163:12Mar99 moved down
  Standard_Integer nbval;

  Handle(IGESDraw_HArray1OfViewKindEntity) views; 
  Handle(TColgp_HArray1OfXY)               viewOrigins; 
  Handle(IGESData_HArray1OfIGESEntity)     annotations; 

  // Reading nbval(No. of View pointers)
  Standard_Boolean st = PR.ReadInteger(PR.Current(), "Count of array of view entities", nbval);
  if (st && nbval > 0)
    {
      views       = new IGESDraw_HArray1OfViewKindEntity(1, nbval);
      viewOrigins = new TColgp_HArray1OfXY(1, nbval);

      Handle(IGESData_ViewKindEntity) tempView;
      gp_XY tempXY;

      for (Standard_Integer i = 1; i <= nbval; i++)
	{
          // Reading views(HArray1OfView)
          //st = PR.ReadEntity (IR, PR.Current(), "View Entity",
				//STANDARD_TYPE(IGESData_ViewKindEntity), tempView,Standard_True); //szv#4:S4163:12Mar99 moved in if
	  if (PR.ReadEntity (IR, PR.Current(), "View Entity",
			     STANDARD_TYPE(IGESData_ViewKindEntity), tempView,Standard_True))
	    views->SetValue(i, tempView);

          // Reading viewOrigins(HArray1OfXY)
          //st = PR.ReadXY(PR.CurrentList(1, 2), "array viewOrigins", tempXY); //szv#4:S4163:12Mar99 moved in if
	  if (PR.ReadXY(PR.CurrentList(1, 2), "array viewOrigins", tempXY))
	    viewOrigins->SetValue(i, tempXY);
	}
    }
  else if (nbval < 0)  PR.AddFail("Count of view entities : Less than zero");

  // Reading nbval(No. of Annotation Entities)
  //st = PR.ReadInteger(PR.Current(),"Count of array of Annotation entities", nbval); //szv#4:S4163:12Mar99 moved in if
  if (PR.ReadInteger(PR.Current(),"Count of array of Annotation entities", nbval)) {
    if ( nbval > 0 )
      PR.ReadEnts (IR,PR.CurrentList(nbval), "Annotation Entities", annotations); //szv#4:S4163:12Mar99 `st=` not needed
/*
      {
	// Reading annotations(HArray1OfIGESEntity)
	annotations = new IGESData_HArray1OfIGESEntity(1, nbval);
	Handle(IGESData_IGESEntity) tempAnnotation;
	for (Standard_Integer i = 1; i <= nbval; i++)
          {
	    st = PR.ReadEntity
	      (IR, PR.Current(), "annotation entity", tempAnnotation,Standard_True);
	    if (st) annotations->SetValue(i, tempAnnotation);
          }
      }
*/
    else if (nbval < 0)  PR.AddFail
      ("Count of Annotation entities : Less than zero");
  }

  DirChecker(ent).CheckTypeAndForm(PR.CCheck(),ent);
  ent->Init(views, viewOrigins, annotations);
}

void IGESDraw_ToolDrawing::WriteOwnParams
  (const Handle(IGESDraw_Drawing)& ent, IGESData_IGESWriter& IW)  const
{
  Standard_Integer Up  = ent->NbViews();
  IW.Send( Up );
  Standard_Integer i; // svv Jan 10 2000 : porting on DEC
  for ( i = 1; i <= Up; i++)
    {
      IW.Send( ent->ViewItem(i) );
      IW.Send( (ent->ViewOrigin(i)).X() );
      IW.Send( (ent->ViewOrigin(i)).Y() );
    }

  Up  = ent->NbAnnotations();
  IW.Send( Up );
  for ( i = 1; i <= Up; i++)
    IW.Send( ent->Annotation(i) );
}

void  IGESDraw_ToolDrawing::OwnShared
  (const Handle(IGESDraw_Drawing)& ent, Interface_EntityIterator& iter) const
{
  Standard_Integer Up  = ent->NbViews();
  Standard_Integer i; // svv Jan 10 2000 : porting on DEC
  for ( i = 1; i <= Up; i++)
    iter.GetOneItem( ent->ViewItem(i) );

  Up  = ent->NbAnnotations();
  for ( i = 1; i <= Up; i++)
    iter.GetOneItem( ent->Annotation(i) );
}

void IGESDraw_ToolDrawing::OwnCopy
  (const Handle(IGESDraw_Drawing)& another,
   const Handle(IGESDraw_Drawing)& ent, Interface_CopyTool& TC) const
{
  Standard_Integer                          nbanot;
  Standard_Integer                          nbval;
  Handle(IGESDraw_HArray1OfViewKindEntity)  views; 
  Handle(TColgp_HArray1OfXY)                viewOrigins; 
  Handle(IGESData_HArray1OfIGESEntity)      annotations; 
 
  nbanot      = another->NbAnnotations();
  nbval       = another->NbViews();
  if (nbval > 0) {
    views       = new IGESDraw_HArray1OfViewKindEntity(1, nbval);
    viewOrigins = new TColgp_HArray1OfXY(1, nbval);
  }
  if ( nbanot > 0 )
    {
      annotations = new IGESData_HArray1OfIGESEntity(1, nbanot);
      for (Standard_Integer i = 1; i <= nbanot; i++)
	{
          DeclareAndCast(IGESData_IGESEntity, tempAnnotation, 
                         TC.Transferred(another->Annotation(i)));
          annotations->SetValue( i, tempAnnotation );
	}
    }
 
  for (Standard_Integer i = 1; i <= nbval; i++)
    {
      DeclareAndCast(IGESData_ViewKindEntity, tempView,
                     TC.Transferred(another->ViewItem(i)) );
      views->SetValue( i, tempView );
 
      viewOrigins->SetValue( i, (another->ViewOrigin(i)).XY() );
    }

  ent->Init(views, viewOrigins, annotations);
}

Standard_Boolean IGESDraw_ToolDrawing::OwnCorrect
  (const Handle(IGESDraw_Drawing)& ent )  const
{
//  Vues vides : les supprimer
  Standard_Integer i, nb = ent->NbViews();
  Standard_Integer nbtrue = nb;
  for (i = 1; i <= nb; i ++) {
    Handle(IGESData_ViewKindEntity) val = ent->ViewItem(i);
    if (val.IsNull()) nbtrue --;
    else if (val->TypeNumber() == 0) nbtrue --;
  }
  if (nbtrue == nb) return Standard_False;
  Handle(IGESDraw_HArray1OfViewKindEntity)  views;
  Handle(TColgp_HArray1OfXY)                viewOrigins; 
  if (nbtrue > 0) {
    views = new IGESDraw_HArray1OfViewKindEntity (1, nbtrue);
    viewOrigins = new TColgp_HArray1OfXY(1, nbtrue);
  }
  nbtrue = 0;
  for (i = 1; i <= nb; i ++) {
    Handle(IGESData_ViewKindEntity) val = ent->ViewItem(i);
    if (val.IsNull()) continue;
    else if (val->TypeNumber() == 0) continue;
    nbtrue ++;
    views->SetValue (nbtrue,val);
    viewOrigins->SetValue(nbtrue, ent->ViewOrigin(i).XY() );
  }

//  Ne pas oublier les annotations ...
  Standard_Integer  nbanot = ent->NbAnnotations();
  Handle(IGESData_HArray1OfIGESEntity)      annotations =
    new IGESData_HArray1OfIGESEntity(1, nbanot);
  for (i = 1; i <= nbanot; i ++)  annotations->SetValue (i,ent->Annotation(i));

  ent->Init(views, viewOrigins, annotations);
  return Standard_True;
}

IGESData_DirChecker IGESDraw_ToolDrawing::DirChecker
  (const Handle(IGESDraw_Drawing)& /*ent*/)  const
{
  IGESData_DirChecker DC (404, 0);
  DC.Structure(IGESData_DefVoid);
  DC.LineFont(IGESData_DefVoid);
  DC.LineWeight(IGESData_DefVoid);
  DC.Color(IGESData_DefVoid);
  DC.BlankStatusIgnored();
  DC.SubordinateStatusRequired(0);
  DC.UseFlagRequired(1);
  DC.HierarchyStatusIgnored();
  return DC;
}

void IGESDraw_ToolDrawing::OwnCheck
  (const Handle(IGESDraw_Drawing)& ent,
   const Interface_ShareTool& , Handle(Interface_Check)& ach)  const
{
  Standard_Boolean ianul = Standard_False;
  Standard_Integer i, nb = ent->NbViews();
  for (i = 1; i <= nb; i ++) {
    Handle(IGESData_ViewKindEntity) tempView = ent->ViewItem(i);
    if (tempView.IsNull()) ianul = Standard_True;
    else if (tempView->TypeNumber() == 0) ianul = Standard_True;
    if (ianul) {
      ach->AddWarning ("At least one View is Null");
      break;
    }
  }
  nb = ent->NbAnnotations();
  for (i = 1; i <= nb; i ++) {
    Handle(IGESData_IGESEntity) ann = ent->Annotation(i);
    if (ann.IsNull()) ianul = Standard_True;
    else if (ann->TypeNumber() == 0) ianul = Standard_True;
    if (ianul) {
      ach->AddWarning ("At least one Annotation is Null");
      break;
    }
  }
}

void IGESDraw_ToolDrawing::OwnDump
  (const Handle(IGESDraw_Drawing)& ent, const IGESData_IGESDumper& dumper,
   const Handle(Message_Messenger)& S, const Standard_Integer level)  const
{
  Standard_Integer sublevel = (level <= 4) ? 0 : 1;

  S << "IGESDraw_Drawing" << endl;

  S << "View Entities            : " << endl
    << "Transformed View Origins : ";
  S << "Count = "      << ent->NbViews();
  switch (level)
    {
    case 4 : S << " [ ask level > 4 for content ]" << endl;
      break; // Nothing to be dumped here
    case 5 :        // Presently level 5 and 6 have the same Dump
      S << endl;
    case 6 :
      {
	Standard_Integer I;
	Standard_Integer up  = ent->NbViews();
	for (I = 1; I <= up; I++)
	  {
	    S << endl << "[" << I << "] ";
	    S << "View Entity : ";
	    dumper.Dump (ent->ViewItem(I),S, sublevel);
	    S << endl;
	    S << "Transformed View Origin : ";
	    IGESData_DumpXY(S, ent->ViewOrigin(I));
	  }
      }
      break;
    }
  S << endl << "Annotation Entities : ";
  IGESData_DumpEntities(S,dumper ,level,1, ent->NbAnnotations(),ent->Annotation);
  S << endl;
}
