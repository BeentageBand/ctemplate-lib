#define CVECTOR_T_IMPLEMENTATION
#define CQUEUE_T_IMPLEMENTATION
#include "gtest-template.h"

#define CVector_Params Uint8 
#define CQueue_Params Uint8 
#include "ctemplate-lib/vector/cvector-int-template.h"
#include "ctemplate-lib/queue/cqueue-int-template.h"
#undef CVector_Params 
#undef CQueue_Params
