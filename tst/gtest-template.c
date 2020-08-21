#include <stdint.h>

typedef uint8_t Uint8_T;
#define CVector_Params Uint8 
#define CQueue_Params Uint8 
#define CSet_Params Uint8 
#define CHashSet_Params Uint8 

#include "ctemplate-lib/vector/cvector-int-template.h"
#include "ctemplate-lib/queue/cqueue-int-template.h"
#include "ctemplate-lib/set/cset-int-template.h"
#include "ctemplate-lib/hashset/chashset-int-template.h"

#undef CVector_Params 
#undef CQueue_Params
#undef CSet_Params 
#undef CHashSet_Params

/*
#define CSet_Params Tuple_Ptr
#include "ctemplate-lib/set/cset-int-template.h"
#undef CSet_Params
*/

