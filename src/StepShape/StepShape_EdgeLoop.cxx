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

#include <StepShape_EdgeLoop.ixx>


StepShape_EdgeLoop::StepShape_EdgeLoop ()  {}

void StepShape_EdgeLoop::Init(const Handle(TCollection_HAsciiString)& aName)
{
  StepRepr_RepresentationItem::Init(aName);
}

void StepShape_EdgeLoop::Init
(const Handle(TCollection_HAsciiString)& aName,
 const Handle(StepShape_HArray1OfOrientedEdge)& aEdgeList)
{
  // --- class inherited fields ---
  StepRepr_RepresentationItem::Init(aName);
  // --- class own fields ---
  edgeList = aEdgeList;
}


void StepShape_EdgeLoop::SetEdgeList(const Handle(StepShape_HArray1OfOrientedEdge)& aEdgeList)
{
	edgeList = aEdgeList;
}

Handle(StepShape_HArray1OfOrientedEdge) StepShape_EdgeLoop::EdgeList() const
{
	return edgeList;
}

Handle(StepShape_OrientedEdge) StepShape_EdgeLoop::EdgeListValue(const Standard_Integer num) const
{
	return edgeList->Value(num);
}

Standard_Integer StepShape_EdgeLoop::NbEdgeList () const
{
	if (edgeList.IsNull()) return 0;
	return edgeList->Length();
}
