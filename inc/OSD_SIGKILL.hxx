// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _OSD_SIGKILL_HeaderFile
#define _OSD_SIGKILL_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Standard_DefineException_HeaderFile
#include <Standard_DefineException.hxx>
#endif
#ifndef _Standard_SStream_HeaderFile
#include <Standard_SStream.hxx>
#endif

#ifndef _OSD_Signal_HeaderFile
#include <OSD_Signal.hxx>
#endif
#ifndef _Handle_OSD_SIGKILL_HeaderFile
#include <Handle_OSD_SIGKILL.hxx>
#endif

#if !defined No_Exception && !defined No_OSD_SIGKILL
#define OSD_SIGKILL_Raise_if(CONDITION,MESSAGE) \
  if (CONDITION) OSD_SIGKILL::Raise(MESSAGE);
#else
#define OSD_SIGKILL_Raise_if(CONDITION,MESSAGE)
#endif

DEFINE_STANDARD_EXCEPTION(OSD_SIGKILL,OSD_Signal)

#endif
