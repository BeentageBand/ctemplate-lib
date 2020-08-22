#include <stdint.h>

typedef uint8_t Uint8;

#define CVector_Params Uint8 
#define CVECTOR_T_IMPLEMENTATION
#include "ctemplate-lib/vector/cvector-template.h"
#include "ctemplate-lib/vector/cvector-int-template.h"
#undef CVector_Params 

#define CQueue_Params Uint8 
#define CQUEUE_T_IMPLEMENTATION
#include "ctemplate-lib/queue/cqueue-template.h"
#include "ctemplate-lib/queue/cqueue-int-template.h"
#undef CQueue_Params

#define CSet_Params Uint8 
#define CSET_T_IMPLEMENTATION
#include "ctemplate-lib/set/cset-template.h"
#include "ctemplate-lib/set/cset-int-template.h"
#undef CSet_Params 

#define CHashSet_Params Uint8 
#define CHASHSET_T_IMPLEMENTATION
#include "ctemplate-lib/hashset/chashset-template.h"
#include "ctemplate-lib/hashset/chashset-int-template.h"
#undef CHashSet_Params

#define CMap_Params Uint8, Uint8
#define CMAP_T_IMPLEMENTATION
#include "ctemplate-lib/map/cmap-template.h"
#include "ctemplate-lib/map/cmap-int-template.h"
#undef CMap_Params

/*
#define CSet_Params Tuple_Ptr
#include "ctemplate-lib/set/cset-int-template.h"
#undef CSet_Params
*/

