#ifndef CHashMap_Params
#error "CHashMap_Params is not defined"
#endif

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
#define chashmap_t_size TEMPLATE(chashmap, CHashMap_Params, size)
#define chashmap_t_clear TEMPLATE(chashmap, CHashMap_Params, clear)
#define chashmap_t_begin TEMPLATE(chashmap, CHashMap_Params, begin)
#define chashmap_t_end TEMPLATE(chashmap, CHashMap_Params, end)
#define chashmap_t_find TEMPLATE(chashmap, CHashMap_Params, find)
#define chashmap_t_insert TEMPLATE(chashmap, CHashMap_Params, insert)
#define chashmap_t_erase TEMPLATE(chashmap, CHashMap_Params, erase)
#define chashmap_t_delete TEMPLATE(chashmap, CHashMap_Params, delete)
#define CHashMap_T_populate TEMPLATE(CHashMap, CHashMap_Params, populate)

#define HashKey_T T_Param(1, CHashMap_Params)
#define HashValue_T T_Param(2, CHashMap_Params)

#define HashPair_Params CHashMap_Params
#include "hashpair.c"

#define HashPair_T TEMPLATE(HashPair, HashPair_Params)
#define HashPair_T_compare TEMPLATE(HashPair, HashPair_Params, compare)
#define HashPairComparator_T TEMPLATE(HashPairComparator, HashPair_Params)
#define HashPair_T_hash TEMPLATE(HashPair, HashPair_Params, hash)
#define HashPairHash_T TEMPLATE(HashPairHash, HashPair_Params)

#define CHashSet_Params HashPair_T
#include "ctemplate-lib/hashset/chashset-int-template.h"

#define CHashSet_T TEMPLATE(CHashSet, CHashSet_Params)
#define HashComparator_T TEMPLATE(HashComparator, HashPair_T)
#define Hash_T TEMPLATE(Hash, HashPair_T)
#define CHashSet_T_size TEMPLATE(CHashSet, CHashSet_Params, size)
#define CHashSet_T_clear TEMPLATE(CHashSet, CHashSet_Params, clear)
#define CHashSet_T_begin TEMPLATE(CHashSet, CHashSet_Params, begin)
#define CHashSet_T_end TEMPLATE(CHashSet, CHashSet_Params, end)
#define CHashSet_T_find TEMPLATE(CHashSet, CHashSet_Params, find)
#define CHashSet_T_insert TEMPLATE(CHashSet, CHashSet_Params, insert)
#define CHashSet_T_erase TEMPLATE(CHashSet, CHashSet_Params, erase)
#define CHashSet_T_populate TEMPLATE(CHashSet, CHashSet_Params, populate)

#include "chashmap.c"

#undef HashPair_T
#undef HashPair_T_compare
#undef HashPairComparator_T 
#undef HashPair_T_hash
#undef HashPairHash_T 
#undef HashPair_Params
#undef CHashSet_T
#undef HashComparator_T
#undef Hash_T
#undef CHashSet_T_size
#undef CHashSet_T_clear
#undef CHashSet_T_begin
#undef CHashSet_T_end
#undef CHashSet_T_find
#undef CHashSet_T_insert
#undef CHashSet_T_erase
#undef CHashSet_T_populate
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
#undef chashmap_t_size
#undef chashmap_t_clear
#undef chashmap_t_begin
#undef chashmap_t_end
#undef chashmap_t_find
#undef chashmap_t_insert
#undef chashmap_t_erase
#undef chashmap_t_delete
#undef CHashMap_T_populate

#undef HashKey_T
#undef HashValue_T
