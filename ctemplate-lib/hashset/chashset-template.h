#if !defined(CHASHSET_TEMPLATE_H) || defined(CHashSet_Params)
#ifndef CHashSet_Params
#error "CHashSet_Params is not defined"
#endif

#include "cobject/ctemplate.h"

#define CHashSet_T TEMPLATE(CHashSet, CHashSet_Params)
#define CHashSet_T_Class TEMPLATE(CHashSet, CHashSet_Params, Class)
#define Get_CHashSet_T_Class TEMPLATE(Get, CHashSet, CHashSet_Params, Class)
#define CHashSet_T_size TEMPLATE(CHashSet, CHashSet_Params, size)
#define CHashSet_T_clear TEMPLATE(CHashSet, CHashSet_Params, clear)
#define CHashSet_T_reserve TEMPLATE(CHashSet, CHashSet_Params, reserve)
#define CHashSet_T_begin TEMPLATE(CHashSet, CHashSet_Params, begin)
#define CHashSet_T_end TEMPLATE(CHashSet, CHashSet_Params, end)
#define CHashSet_T_find TEMPLATE(CHashSet, CHashSet_Params, find)
#define CHashSet_T_insert TEMPLATE(CHashSet, CHashSet_Params, insert)
#define CHashSet_T_erase TEMPLATE(CHashSet, CHashSet_Params, erase)
#define CHashSet_T_populate TEMPLATE(CHashSet, CHashSet_Params, populate)

#define T T_Param(1, CHashSet_Params)

#define Bucket_Params CHashSet_Params
#include "bucket.h"

#define Bucket_T TEMPLATE(Bucket, Bucket_Params)
#define Hash_T TEMPLATE(Hash, Bucket_Params)
#define HashComparator_T TEMPLATE(HashComparator, Bucket_Params)

#include "chashset.h"

#undef Bucket_T
#undef Hash_T
#undef HashComparator_T
#undef Bucket_Params

#undef CHashSet_T
#undef CHashSet_T_Class
#undef Get_CHashSet_T_Class
#undef CHashSet_T_size
#undef CHashSet_T_clear
#undef CHashSet_T_reserve
#undef CHashSet_T_begin
#undef CHashSet_T_end
#undef CHashSet_T_find
#undef CHashSet_T_insert
#undef CHashSet_T_erase
#undef CHashSet_T_populate

#undef T

#endif /* CHASHSET_TEMPLATE_H */
