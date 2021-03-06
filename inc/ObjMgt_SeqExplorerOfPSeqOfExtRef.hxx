// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _ObjMgt_SeqExplorerOfPSeqOfExtRef_HeaderFile
#define _ObjMgt_SeqExplorerOfPSeqOfExtRef_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Handle_ObjMgt_SeqNodeOfPSeqOfExtRef_HeaderFile
#include <Handle_ObjMgt_SeqNodeOfPSeqOfExtRef.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_ObjMgt_PSeqOfExtRef_HeaderFile
#include <Handle_ObjMgt_PSeqOfExtRef.hxx>
#endif
#ifndef _Handle_ObjMgt_ExternRef_HeaderFile
#include <Handle_ObjMgt_ExternRef.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
class ObjMgt_SeqNodeOfPSeqOfExtRef;
class ObjMgt_PSeqOfExtRef;
class Standard_NoSuchObject;
class Standard_OutOfRange;
class ObjMgt_ExternRef;



class ObjMgt_SeqExplorerOfPSeqOfExtRef  {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   ObjMgt_SeqExplorerOfPSeqOfExtRef(const Handle(ObjMgt_PSeqOfExtRef)& S);
  
  Standard_EXPORT     Handle_ObjMgt_ExternRef Value(const Standard_Integer Index) ;
  
  Standard_EXPORT     Standard_Boolean Contains(const Handle(ObjMgt_ExternRef)& T) ;
  
  Standard_EXPORT     Standard_Integer Location(const Standard_Integer N,const Handle(ObjMgt_ExternRef)& T,const Standard_Integer FromIndex,const Standard_Integer ToIndex) ;
  
  Standard_EXPORT     Standard_Integer Location(const Standard_Integer N,const Handle(ObjMgt_ExternRef)& T) ;





protected:





private:



Handle_ObjMgt_SeqNodeOfPSeqOfExtRef CurrentItem;
Standard_Integer CurrentIndex;
Handle_ObjMgt_PSeqOfExtRef TheSequence;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
