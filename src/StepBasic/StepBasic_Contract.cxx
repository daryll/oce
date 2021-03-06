// Created on: 1999-11-26
// Created by: Andrey BETENEV
// Copyright (c) 1999 Matra Datavision
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

// Generator:	ExpToCas (EXPRESS -> CASCADE/XSTEP Translator) V1.0

#include <StepBasic_Contract.ixx>

//=======================================================================
//function : StepBasic_Contract
//purpose  : 
//=======================================================================

StepBasic_Contract::StepBasic_Contract ()
{
}

//=======================================================================
//function : Init
//purpose  : 
//=======================================================================

void StepBasic_Contract::Init (const Handle(TCollection_HAsciiString) &aName,
                               const Handle(TCollection_HAsciiString) &aPurpose,
                               const Handle(StepBasic_ContractType) &aKind)
{

  theName = aName;

  thePurpose = aPurpose;

  theKind = aKind;
}

//=======================================================================
//function : Name
//purpose  : 
//=======================================================================

Handle(TCollection_HAsciiString) StepBasic_Contract::Name () const
{
  return theName;
}

//=======================================================================
//function : SetName
//purpose  : 
//=======================================================================

void StepBasic_Contract::SetName (const Handle(TCollection_HAsciiString) &aName)
{
  theName = aName;
}

//=======================================================================
//function : Purpose
//purpose  : 
//=======================================================================

Handle(TCollection_HAsciiString) StepBasic_Contract::Purpose () const
{
  return thePurpose;
}

//=======================================================================
//function : SetPurpose
//purpose  : 
//=======================================================================

void StepBasic_Contract::SetPurpose (const Handle(TCollection_HAsciiString) &aPurpose)
{
  thePurpose = aPurpose;
}

//=======================================================================
//function : Kind
//purpose  : 
//=======================================================================

Handle(StepBasic_ContractType) StepBasic_Contract::Kind () const
{
  return theKind;
}

//=======================================================================
//function : SetKind
//purpose  : 
//=======================================================================

void StepBasic_Contract::SetKind (const Handle(StepBasic_ContractType) &aKind)
{
  theKind = aKind;
}
