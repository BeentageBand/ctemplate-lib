#ifndef GTEST_TEMPLATE_UTILS_H_
#define GTEST_TEMPLATE_UTILS_H_
 
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
 
typedef uint8_t Uint8;

#define CVector_Params Uint8 
#include "ctemplate-lib/vector/cvector-template.h"
#undef CVector_Params

#define CQueue_Params Uint8 
#include "ctemplate-lib/queue/cqueue-template.h"
#undef CQueue_Params

#define CSet_Params Uint8 
#include "ctemplate-lib/set/cset-template.h"
#undef CSet_Params

#define CHashSet_Params Uint8 
#include "ctemplate-lib/hashset/chashset-template.h"
#undef CHashSet_Params

#define CMap_Params Uint8, Uint8
#include "ctemplate-lib/map/cmap-template.h"
#undef CMap_Params

typedef struct {
  int id;
  char const * obj;
}Tuple_T;

typedef Tuple_T * Tuple_Ptr_T;

/*
#define CSet_Params Tuple_Ptr
#include "ctemplate-lib/set/cset-template.h"
#undef CSet_Params
*/

#ifdef __cplusplus
}
#endif

#endif /*GTEST_TEMPLATE_UTILS_H_*/
