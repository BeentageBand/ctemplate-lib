#define CVector_Params int 
#define CVECTOR_T_IMPLEMENTATION
#include "ctemplate-lib/vector/cvector-template.h"
#include "ctemplate-lib/vector/cvector-int-template.h"
#undef CVector_Params 

#define CQueue_Params int 
#define CQUEUE_T_IMPLEMENTATION
#include "ctemplate-lib/queue/cqueue-template.h"
#include "ctemplate-lib/queue/cqueue-int-template.h"
#undef CQueue_Params

#define CSet_Params int 
#define CSET_T_IMPLEMENTATION
#include "ctemplate-lib/set/cset-template.h"
#include "ctemplate-lib/set/cset-int-template.h"
#undef CSet_Params 

#define CHashSet_Params int 
#define CHASHSET_T_IMPLEMENTATION
#include "ctemplate-lib/hashset/chashset-template.h"
#include "ctemplate-lib/hashset/chashset-int-template.h"
#undef CHashSet_Params

#define CMap_Params int, int
#define CMAP_T_IMPLEMENTATION
#include "ctemplate-lib/map/cmap-template.h"
#include "ctemplate-lib/map/cmap-int-template.h"
#undef CMap_Params

#define CHashMap_Params int, int
#define CHASHMAP_T_IMPLEMENTATION
#include "ctemplate-lib/hashmap/chashmap-template.h"
#include "ctemplate-lib/hashmap/chashmap-int-template.h"
#undef CHashMap_Params

#define CPtr_Params int
#define CPTR_T_IMPLEMENTATION
#include "ctemplate-lib/ptr/cptr-template.h"
#include "ctemplate-lib/ptr/cptr-int-template.h"
#undef CPtr_Params
/*
#define CSet_Params Tuple_Ptr
#include "ctemplate-lib/set/cset-int-template.h"
#undef CSet_Params
*/

