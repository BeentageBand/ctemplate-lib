#ifndef CHashSet_Params
#error "CHashSet_Params is not defined"
#endif

#define CHashSet_T TEMPLATE(CHashSet, CHashSet_Params)
#define CHashSet_T_Class TEMPLATE(CHashSet, CHashSet_Params, Class)
#define Get_CHashSet_T_Class TEMPLATE(Get, CHashSet, CHashSet_Params, Class)
#define CHashSet_T_size TEMPLATE(CHashSet, CHashSet_Params, size)
#define CHashSet_T_clear TEMPLATE(CHashSet, CHashSet_Params, clear)
#define CHashSet_T_begin TEMPLATE(CHashSet, CHashSet_Params, begin)
#define CHashSet_T_end TEMPLATE(CHashSet, CHashSet_Params, end)
#define CHashSet_T_find TEMPLATE(CHashSet, CHashSet_Params, find)
#define CHashSet_T_insert TEMPLATE(CHashSet, CHashSet_Params, insert)
#define CHashSet_T_erase TEMPLATE(CHashSet, CHashSet_Params, erase)
#define chashset_t_size TEMPLATE(chashset, CHashSet_Params, size)
#define chashset_t_clear TEMPLATE(chashset, CHashSet_Params, clear)
#define chashset_t_begin TEMPLATE(chashset, CHashSet_Params, begin)
#define chashset_t_end TEMPLATE(chashset, CHashSet_Params, end)
#define chashset_t_find TEMPLATE(chashset, CHashSet_Params, find)
#define chashset_t_insert TEMPLATE(chashset, CHashSet_Params, insert)
#define chashset_t_erase TEMPLATE(chashset, CHashSet_Params, erase)
#define chashset_t_override TEMPLATE(chashset, CHashSet_Params, override)
#define CHashSet_T_populate TEMPLATE(CHashSet, CHashSet_Params, populate)

#define T T_Param(1, CHashSet_Params)

#define Bucket_Params CHashSet_Params
#include "bucket.c"

#define Bucket_T TEMPLATE(Bucket, Bucket_Params)
#define Hash_T TEMPLATE(Hash, Bucket_Params)
#define HashComparator_T TEMPLATE(HashComparator, Bucket_Params)
#define Bucket_T_access TEMPLATE(Bucket, Bucket_Params, access)
#define Bucket_T_available TEMPLATE(Bucket, Bucket_Params, available)
#define Bucket_T_is_empty TEMPLATE(Bucket, Bucket_Params, is_empty)
#define Bucket_T_hash TEMPLATE(Bucket, Bucket_Params, hash)

#include "chashset.c"

#undef Bucket_T
#undef Hash_T
#undef HashComparator_T
#undef Bucket_T_access
#undef Bucket_T_available
#undef Bucket_T_is_empty
#undef Bucket_T_hash 

#undef CHashSet_T
#undef CHashSet_T_Class
#undef Get_CHashSet_T_Class
#undef CHashSet_T_size
#undef CHashSet_T_clear
#undef CHashSet_T_begin
#undef CHashSet_T_end
#undef CHashSet_T_find
#undef CHashSet_T_insert
#undef CHashSet_T_erase
#undef chashset_t_size
#undef chashset_t_clear
#undef chashset_t_begin
#undef chashset_t_end
#undef chashset_t_find
#undef chashset_t_insert
#undef chashset_t_erase
#undef chashset_t_override
#undef CHashSet_T_populate

#undef T
