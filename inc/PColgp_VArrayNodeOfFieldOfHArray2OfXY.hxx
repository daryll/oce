// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _PColgp_VArrayNodeOfFieldOfHArray2OfXY_HeaderFile
#define _PColgp_VArrayNodeOfFieldOfHArray2OfXY_HeaderFile

#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Handle_PColgp_VArrayNodeOfFieldOfHArray2OfXY_HeaderFile
#include <Handle_PColgp_VArrayNodeOfFieldOfHArray2OfXY.hxx>
#endif

#ifndef _Standard_Address_HeaderFile
#include <Standard_Address.hxx>
#endif
#ifndef _gp_XY_HeaderFile
#include <gp_XY.hxx>
#endif
#ifndef _PStandard_ArrayNode_HeaderFile
#include <PStandard_ArrayNode.hxx>
#endif
class gp_XY;
class PColgp_FieldOfHArray2OfXY;
class PColgp_VArrayTNodeOfFieldOfHArray2OfXY;


class PColgp_VArrayNodeOfFieldOfHArray2OfXY : public PStandard_ArrayNode {

public:

  
  Standard_EXPORT   PColgp_VArrayNodeOfFieldOfHArray2OfXY();
  
  Standard_EXPORT   PColgp_VArrayNodeOfFieldOfHArray2OfXY(const gp_XY& aValue);
  
  Standard_EXPORT     void SetValue(const gp_XY& aValue) ;
  
  Standard_EXPORT     Standard_Address Value() const;

PColgp_VArrayNodeOfFieldOfHArray2OfXY(const Storage_stCONSTclCOM& a) : PStandard_ArrayNode(a)
{
  
}
    const gp_XY& _CSFDB_GetPColgp_VArrayNodeOfFieldOfHArray2OfXYmyValue() const { return myValue; }



  DEFINE_STANDARD_RTTI(PColgp_VArrayNodeOfFieldOfHArray2OfXY)

protected:




private: 


gp_XY myValue;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
