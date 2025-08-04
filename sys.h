#ifndef __SYS_H__
#define __SYS_H__

#ifdef __cplusplus
extern "C" {
#endif

#define SYS_ERROR_BASE      0x00001000
#define SYS_SUCCESS         0
#define SYS_Error_Check(x)  if(( SYS_ERROR_NUM = (x)) != 0) SYS_Fatal_Error(SYS_ERROR_NUM)

extern volatile uint64_t SYS_TICK;

extern int32_t SYS_ERROR_NUM;
extern void SYS_Fatal_Error(int32_t err);
extern uint32_t SYS_Init(void);

#ifdef __cplusplus
}
#endif

#endif