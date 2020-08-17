#ifndef GTEST_TEMPLATE_UTILS_H_
#define GTEST_TEMPLATE_UTILS_H_
 
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
 
typedef uint8_t Uint8_T;

#define CVector_Params Uint8 
#define CQueue_Params Uint8 

#include "ctemplate-lib/vector/cvector-template.h"
#include "ctemplate-lib/queue/cqueue-template.h"

#undef CVector_Params
#undef CQueue_Params

#ifdef __cplusplus
}
#endif

#endif /*GTEST_TEMPLATE_UTILS_H_*/
