// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Transfer_MultipleBinder_HeaderFile
#define _Transfer_MultipleBinder_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_Transfer_MultipleBinder_HeaderFile
#include <Handle_Transfer_MultipleBinder.hxx>
#endif

#ifndef _Handle_TColStd_HSequenceOfTransient_HeaderFile
#include <Handle_TColStd_HSequenceOfTransient.hxx>
#endif
#ifndef _Transfer_Binder_HeaderFile
#include <Transfer_Binder.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_Standard_Type_HeaderFile
#include <Handle_Standard_Type.hxx>
#endif
#ifndef _Standard_CString_HeaderFile
#include <Standard_CString.hxx>
#endif
#ifndef _Handle_Standard_Transient_HeaderFile
#include <Handle_Standard_Transient.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class TColStd_HSequenceOfTransient;
class Transfer_TransferFailure;
class Standard_OutOfRange;
class Standard_Type;
class Standard_Transient;


//! Allows direct binding between a starting Object and the Result <br>
//!           of its transfer, when it can be made of several Transient <br>
//!           Objects. Compared to a Transcriptor, it has no Transfer Action <br>
//! <br>
//!           Result is a list of Transient Results. Unique Result is not <br>
//!           available : SetResult is redefined to start the list on the <br>
//!           first call, and refuse the other times. <br>
//! <br>
//!           rr <br>
//! <br>
//!           Remark : MultipleBinder itself is intended to be created and <br>
//!           filled by TransferProcess itself (method Bind). In particular, <br>
//!           conflicts between Unique (Standard) result and Multiple result <br>
//!           are avoided through management made by TransferProcess. <br>
//! <br>
//!           Also, a Transcriptor (with an effective Transfer Method) which <br>
//!           can produce a Multiple Result, may be defined as a sub-class <br>
//!           of MultipleBinder by redefining method Transfer. <br>
class Transfer_MultipleBinder : public Transfer_Binder {

public:

  //! normal standard constructor, creates an empty MultipleBinder <br>
  Standard_EXPORT   Transfer_MultipleBinder();
  //! Returns True if a starting object is bound with SEVERAL <br>
//!           results : Here, returns allways True <br>
  Standard_EXPORT   virtual  Standard_Boolean IsMultiple() const;
  //! Returns the Type permitted for Results, i.e. here Transient <br>
  Standard_EXPORT     Handle_Standard_Type ResultType() const;
  //! Returns the Name of the Type which characterizes the Result <br>
//!           Here, returns "(list)" <br>
  Standard_EXPORT     Standard_CString ResultTypeName() const;
  //! Adds a new Item to the Multiple Result <br>
  Standard_EXPORT     void AddResult(const Handle(Standard_Transient)& res) ;
  //! Returns the actual count of recorded (Transient) results <br>
  Standard_EXPORT     Standard_Integer NbResults() const;
  //! Returns the value of the recorded result n0 <num> <br>
  Standard_EXPORT     Handle_Standard_Transient ResultValue(const Standard_Integer num) const;
  //! Returns the Multiple Result, if it is defined (at least one <br>
//!           Item). Else, returns a Null Handle <br>
  Standard_EXPORT     Handle_TColStd_HSequenceOfTransient MultipleResult() const;
  //! Defines a Binding with a Multiple Result, given as a Sequence <br>
//!           Error if a Unique Result has yet been defined <br>
  Standard_EXPORT     void SetMultipleResult(const Handle(TColStd_HSequenceOfTransient)& mulres) ;




  DEFINE_STANDARD_RTTI(Transfer_MultipleBinder)

protected:




private: 


Handle_TColStd_HSequenceOfTransient themulres;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
