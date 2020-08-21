#ifndef CHASHSET_T_H
#define CHASHSET_T_H
#include "cobject/cobject.h"

#define Bucket_Params CHashSet_Params
#include "bucket.h"
#define Bucket_T TEMPLATE(Bucket, Bucket_Params)
#define Hash_T TEMPLATE(Hash, Bucket_Params)
#define HashCompare_T TEMPLATE(HashCompare, Bucket_Params)

#ifdef CHASHSET_T_IMPLEMENTATION 
#define chashset_private
#else
#define chashset_private const
#endif 

#ifdef __cplusplus
extern "C" {
#endif

union CHashSet_T;
union CHashSet_T_Class
{
    
    struct
    {
    struct Class Class;
    size_t (* chashset_private size)(union CHashSet_T * const chashset_t);
void (* chashset_private clear)(union CHashSet_T * const chashset_t);
T * (* chashset_private begin)(union CHashSet_T * const chashset_t);
T * (* chashset_private end)(union CHashSet_T * const chashset_t);
T * (* chashset_private find)(union CHashSet_T * const chashset_t, T const index);
void (* chashset_private insert)(union CHashSet_T * const chashset_t, T const value);
void (* chashset_private erase)(union CHashSet_T * const chashset_t, T const value);

    };
};

union CHashSet_T
{
    union CHashSet_T_Class * vtbl;
        struct
    {
      union Object Object;
      struct Bucket_T* chashset_private buckets;
size_t chashset_private size;
size_t chashset_private count;
Hash_T chashset_private hash;
HashCompare_T chashset_private cmp;

    };
};

extern union CHashSet_T_Class * Get_CHashSet_T_Class(void);

extern void CHashSet_T_populate(union CHashSet_T * const chashset_t, struct Bucket_T* const buckets, size_t const size, 
    size_t const count, Hash_T const hash, HashCompare_T const cmp);

extern size_t CHashSet_T_size(union CHashSet_T * const chashset_t);

extern void CHashSet_T_clear(union CHashSet_T * const chashset_t);

extern T * CHashSet_T_begin(union CHashSet_T * const chashset_t);

extern T * CHashSet_T_end(union CHashSet_T * const chashset_t);

extern T * CHashSet_T_find(union CHashSet_T * const chashset_t, T const index);

extern void CHashSet_T_insert(union CHashSet_T * const chashset_t, T const value);

extern void CHashSet_T_erase(union CHashSet_T * const chashset_t, T const value);

#ifdef __cplusplus
}
#endif
#undef Bucket_T
#undef Hash_T
#undef HashCompare_T
#undef Bucket_Params
#endif /*CHASHSET_TNone_H*/
