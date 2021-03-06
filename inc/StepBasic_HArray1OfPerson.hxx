// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepBasic_HArray1OfPerson_HeaderFile
#define _StepBasic_HArray1OfPerson_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_StepBasic_HArray1OfPerson_HeaderFile
#include <Handle_StepBasic_HArray1OfPerson.hxx>
#endif

#ifndef _StepBasic_Array1OfPerson_HeaderFile
#include <StepBasic_Array1OfPerson.hxx>
#endif
#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif
#ifndef _Handle_StepBasic_Person_HeaderFile
#include <Handle_StepBasic_Person.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class Standard_RangeError;
class Standard_DimensionMismatch;
class Standard_OutOfRange;
class Standard_OutOfMemory;
class StepBasic_Person;
class StepBasic_Array1OfPerson;



class StepBasic_HArray1OfPerson : public MMgt_TShared {

public:

  
  Standard_EXPORT   StepBasic_HArray1OfPerson(const Standard_Integer Low,const Standard_Integer Up);
  
  Standard_EXPORT   StepBasic_HArray1OfPerson(const Standard_Integer Low,const Standard_Integer Up,const Handle(StepBasic_Person)& V);
  
  Standard_EXPORT     void Init(const Handle(StepBasic_Person)& V) ;
  
        Standard_Integer Length() const;
  
        Standard_Integer Lower() const;
  
        Standard_Integer Upper() const;
  
        void SetValue(const Standard_Integer Index,const Handle(StepBasic_Person)& Value) ;
  
       const Handle_StepBasic_Person& Value(const Standard_Integer Index) const;
  
        Handle_StepBasic_Person& ChangeValue(const Standard_Integer Index) ;
  
       const StepBasic_Array1OfPerson& Array1() const;
  
        StepBasic_Array1OfPerson& ChangeArray1() ;




  DEFINE_STANDARD_RTTI(StepBasic_HArray1OfPerson)

protected:




private: 


StepBasic_Array1OfPerson myArray;


};

#define ItemHArray1 Handle_StepBasic_Person
#define ItemHArray1_hxx <StepBasic_Person.hxx>
#define TheArray1 StepBasic_Array1OfPerson
#define TheArray1_hxx <StepBasic_Array1OfPerson.hxx>
#define TCollection_HArray1 StepBasic_HArray1OfPerson
#define TCollection_HArray1_hxx <StepBasic_HArray1OfPerson.hxx>
#define Handle_TCollection_HArray1 Handle_StepBasic_HArray1OfPerson
#define TCollection_HArray1_Type_() StepBasic_HArray1OfPerson_Type_()

#include <TCollection_HArray1.lxx>

#undef ItemHArray1
#undef ItemHArray1_hxx
#undef TheArray1
#undef TheArray1_hxx
#undef TCollection_HArray1
#undef TCollection_HArray1_hxx
#undef Handle_TCollection_HArray1
#undef TCollection_HArray1_Type_


// other Inline functions and methods (like "C++: function call" methods)


#endif
