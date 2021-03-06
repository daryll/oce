// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepFill_IndexedDataMapOfOrientedShapeListOfShape_HeaderFile
#define _BRepFill_IndexedDataMapOfOrientedShapeListOfShape_HeaderFile

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
#ifndef _Handle_BRepFill_IndexedDataMapNodeOfIndexedDataMapOfOrientedShapeListOfShape_HeaderFile
#include <Handle_BRepFill_IndexedDataMapNodeOfIndexedDataMapOfOrientedShapeListOfShape.hxx>
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
class Standard_OutOfRange;
class Standard_NoSuchObject;
class TopoDS_Shape;
class TopTools_ListOfShape;
class TopTools_OrientedShapeMapHasher;
class BRepFill_IndexedDataMapNodeOfIndexedDataMapOfOrientedShapeListOfShape;



class BRepFill_IndexedDataMapOfOrientedShapeListOfShape  : public TCollection_BasicMap {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   BRepFill_IndexedDataMapOfOrientedShapeListOfShape(const Standard_Integer NbBuckets = 1);
  
  Standard_EXPORT     BRepFill_IndexedDataMapOfOrientedShapeListOfShape& Assign(const BRepFill_IndexedDataMapOfOrientedShapeListOfShape& Other) ;
    BRepFill_IndexedDataMapOfOrientedShapeListOfShape& operator =(const BRepFill_IndexedDataMapOfOrientedShapeListOfShape& Other) 
{
  return Assign(Other);
}
  
  Standard_EXPORT     void ReSize(const Standard_Integer NbBuckets) ;
  
  Standard_EXPORT     void Clear() ;
~BRepFill_IndexedDataMapOfOrientedShapeListOfShape()
{
  Clear();
}
  
  Standard_EXPORT     Standard_Integer Add(const TopoDS_Shape& K,const TopTools_ListOfShape& I) ;
  
  Standard_EXPORT     void Substitute(const Standard_Integer I,const TopoDS_Shape& K,const TopTools_ListOfShape& T) ;
  
  Standard_EXPORT     void RemoveLast() ;
  
  Standard_EXPORT     Standard_Boolean Contains(const TopoDS_Shape& K) const;
  
  Standard_EXPORT    const TopoDS_Shape& FindKey(const Standard_Integer I) const;
  
  Standard_EXPORT    const TopTools_ListOfShape& FindFromIndex(const Standard_Integer I) const;
   const TopTools_ListOfShape& operator ()(const Standard_Integer I) const
{
  return FindFromIndex(I);
}
  
  Standard_EXPORT     TopTools_ListOfShape& ChangeFromIndex(const Standard_Integer I) ;
    TopTools_ListOfShape& operator ()(const Standard_Integer I) 
{
  return ChangeFromIndex(I);
}
  
  Standard_EXPORT     Standard_Integer FindIndex(const TopoDS_Shape& K) const;
  
  Standard_EXPORT    const TopTools_ListOfShape& FindFromKey(const TopoDS_Shape& K) const;
  
  Standard_EXPORT     TopTools_ListOfShape& ChangeFromKey(const TopoDS_Shape& K) ;
  
  Standard_EXPORT     Standard_Address FindFromKey1(const TopoDS_Shape& K) const;
  
  Standard_EXPORT     Standard_Address ChangeFromKey1(const TopoDS_Shape& K) ;





protected:





private:

  
  Standard_EXPORT   BRepFill_IndexedDataMapOfOrientedShapeListOfShape(const BRepFill_IndexedDataMapOfOrientedShapeListOfShape& Other);




};





// other Inline functions and methods (like "C++: function call" methods)


#endif
