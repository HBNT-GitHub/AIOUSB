#ifndef _AIOUSB_CTR_H
#define _AIOUSB_CTR_H

#ifndef PUBLIC_EXTERN
#define PUBLIC_EXTERN extern
#endif
#include "AIOTypes.h"
#include "AIOUSB_Core.h"


#ifdef __aiousb_cplusplus
namespace AIOUSB {
#endif



PUBLIC_EXTERN AIORET_TYPE CTR_8254Mode(
                                         unsigned long DeviceIndex,
                                         unsigned long BlockIndex,
                                         unsigned long CounterIndex,
                                         unsigned long Mode );

PUBLIC_EXTERN AIORET_TYPE CTR_8254Load(
                                         unsigned long DeviceIndex,
                                         unsigned long BlockIndex,
                                         unsigned long CounterIndex,
                                         unsigned short LoadValue );

PUBLIC_EXTERN AIORET_TYPE CTR_8254ModeLoad(
                                             unsigned long DeviceIndex,
                                             unsigned long BlockIndex,
                                             unsigned long CounterIndex,
                                             unsigned long Mode,
                                             unsigned short LoadValue );

PUBLIC_EXTERN AIORET_TYPE CTR_8254ReadModeLoad(
                                                 unsigned long DeviceIndex,
                                                 unsigned long BlockIndex,
                                                 unsigned long CounterIndex,
                                                 unsigned long Mode,
                                                 unsigned short LoadValue,
                                                 unsigned short *pReadValue );

PUBLIC_EXTERN AIORET_TYPE CTR_8254Read( unsigned long DeviceIndex,
                                        unsigned long BlockIndex,
                                        unsigned long CounterIndex,
                                        unsigned short *pReadValue );

PUBLIC_EXTERN AIORET_TYPE CTR_8254ReadAll( unsigned long DeviceIndex,
                                           unsigned short *pData );

PUBLIC_EXTERN AIORET_TYPE CTR_8254ReadStatus( unsigned long DeviceIndex,
                                              unsigned long BlockIndex,
                                              unsigned long CounterIndex,
                                              unsigned short *pReadValue,
                                              unsigned char *pStatus );

PUBLIC_EXTERN AIORET_TYPE CTR_StartOutputFreq( unsigned long DeviceIndex,
                                               unsigned long BlockIndex,
                                               double *pHz );

PUBLIC_EXTERN AIORET_TYPE CTR_8254SelectGate( unsigned long DeviceIndex,
                                              unsigned long GateIndex );

PUBLIC_EXTERN AIORET_TYPE CTR_8254ReadLatched( unsigned long DeviceIndex,
                                               unsigned short *pData );

#ifdef __aiousb_cplusplus
}
#endif

#endif