#ifndef GTEST_TEMPLATE_UTILS_H_
#define GTEST_TEMPLATE_UTILS_H_
 
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
 
typedef uint8_t Uint8_T;

#define CVector_Params Uint8 

#include "ctemplate-lib/cvector-template.h"

#undef CVector_Params

#ifdef __cplusplus
}
#endif

#endif /*GTEST_TEMPLATE_UTILS_H_*/
