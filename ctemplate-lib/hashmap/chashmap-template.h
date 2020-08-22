#if !defined(CHASHMAP_TEMPLATE_H) || defined(CHashMap_Params)
#ifndef CHashMap_Params
#error "CHashMap_Params is not defined"
#endif

#include "cobject/ctemplate.h"

#define CHashMap_T TEMPLATE(CHashMap, CHashMap_Params)
#define CHashMap_T_Class TEMPLATE(CHashMap, CHashMap_Params, Class)
#define Get_CHashMap_T_Class TEMPLATE(Get, CHashMap, CHashMap_Params, Class)
#define CHashMap_T_size TEMPLATE(CHashMap, CHashMap_Params, size)
#define CHashMap_T_clear TEMPLATE(CHashMap, CHashMap_Params, clear)
#define CHashMap_T_begin TEMPLATE(CHashMap, CHashMap_Params, begin)
#define CHashMap_T_end TEMPLATE(CHashMap, CHashMap_Params, end)
#define CHashMap_T_find TEMPLATE(CHashMap, CHashMap_Params, find)
#define CHashMap_T_insert TEMPLATE(CHashMap, CHashMap_Params, insert)
#define CHashMap_T_erase TEMPLATE(CHashMap, CHashMap_Params, erase)
#define CHashMap_T_populate TEMPLATE(CHashMap, CHashMap_Params, populate)

#define HashKey_T T_Param(1, CHashMap_Params)
#define HashValue_T T_Param(2, CHashMap_Params)

#define HashPair_Params CHashMap_Params
#include "hashpair.h"

#define HashPair_T TEMPLATE(HashPair, HashPair_Params)
#define HashPairComparator_T TEMPLATE(HashPairComparator, HashPair_Params)

#define CHashSet_Params HashPair_T
#include "ctemplate-lib/hashset/chashset-template.h"

#define CHashSet_T TEMPLATE(CHashSet, CHashSet_Params)
#define Comparator_T TEMPLATE(Comparator, CHashSet_Params)

#include "chashmap.h"

#undef HashPair_T
#undef HashPairComparator_T
#undef HashPair_Params
#undef CHashSet_T
#undef CHashSet_Params

#undef CHashMap_T
#undef CHashMap_T_Class
#undef Get_CHashMap_T_Class
#undef CHashMap_T_size
#undef CHashMap_T_clear
#undef CHashMap_T_begin
#undef CHashMap_T_end
#undef CHashMap_T_find
#undef CHashMap_T_insert
#undef CHashMap_T_erase
#undef CHashMap_T_populate

#undef HashKey_T
#undef HashValue_T

#endif /* CHASHMAP_TEMPLATE_H */
