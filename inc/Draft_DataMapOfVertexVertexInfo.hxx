// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Draft_DataMapOfVertexVertexInfo_HeaderFile
#define _Draft_DataMapOfVertexVertexInfo_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TCollection_BasicMap_HeaderFile
#include <TCollection_BasicMap.hxx>
#endif
#ifndef _Handle_Draft_DataMapNodeOfDataMapOfVertexVertexInfo_HeaderFile
#include <Handle_Draft_DataMapNodeOfDataMapOfVertexVertexInfo.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_Address_HeaderFile
#include <Standard_Address.hxx>
#endif
class Standard_DomainError;
class Standard_NoSuchObject;
class TopoDS_Vertex;
class Draft_VertexInfo;
class TopTools_ShapeMapHasher;
class Draft_DataMapNodeOfDataMapOfVertexVertexInfo;
class Draft_DataMapIteratorOfDataMapOfVertexVertexInfo;



class Draft_DataMapOfVertexVertexInfo  : public TCollection_BasicMap {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   Draft_DataMapOfVertexVertexInfo(const Standard_Integer NbBuckets = 1);
  
  Standard_EXPORT     Draft_DataMapOfVertexVertexInfo& Assign(const Draft_DataMapOfVertexVertexInfo& Other) ;
    Draft_DataMapOfVertexVertexInfo& operator =(const Draft_DataMapOfVertexVertexInfo& Other) 
{
  return Assign(Other);
}
  
  Standard_EXPORT     void ReSize(const Standard_Integer NbBuckets) ;
  
  Standard_EXPORT     void Clear() ;
~Draft_DataMapOfVertexVertexInfo()
{
  Clear();
}
  
  Standard_EXPORT     Standard_Boolean Bind(const TopoDS_Vertex& K,const Draft_VertexInfo& I) ;
  
  Standard_EXPORT     Standard_Boolean IsBound(const TopoDS_Vertex& K) const;
  
  Standard_EXPORT     Standard_Boolean UnBind(const TopoDS_Vertex& K) ;
  
  Standard_EXPORT    const Draft_VertexInfo& Find(const TopoDS_Vertex& K) const;
   const Draft_VertexInfo& operator()(const TopoDS_Vertex& K) const
{
  return Find(K);
}
  
  Standard_EXPORT     Draft_VertexInfo& ChangeFind(const TopoDS_Vertex& K) ;
    Draft_VertexInfo& operator()(const TopoDS_Vertex& K) 
{
  return ChangeFind(K);
}
  
  Standard_EXPORT     Standard_Address Find1(const TopoDS_Vertex& K) const;
  
  Standard_EXPORT     Standard_Address ChangeFind1(const TopoDS_Vertex& K) ;





protected:





private:

  
  Standard_EXPORT   Draft_DataMapOfVertexVertexInfo(const Draft_DataMapOfVertexVertexInfo& Other);




};





// other Inline functions and methods (like "C++: function call" methods)


#endif
