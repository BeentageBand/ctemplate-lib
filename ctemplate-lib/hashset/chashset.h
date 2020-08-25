#include "cobject/cobject.h"

#ifdef CHASHSET_T_IMPLEMENTATION 
#define _private
#else
#define _private const
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
    size_t (* _private size)(union CHashSet_T * const chashset_t);
void (* _private clear)(union CHashSet_T * const chashset_t);
void (* _private reserve)(union CHashSet_T * const chashset_t, size_t const capacity);
T * (* _private begin)(union CHashSet_T * const chashset_t);
T * (* _private end)(union CHashSet_T * const chashset_t);
T * (* _private find)(union CHashSet_T * const chashset_t, T const index);
void (* _private insert)(union CHashSet_T * const chashset_t, T const value);
void (* _private erase)(union CHashSet_T * const chashset_t, T const value);

    };
};

union CHashSet_T
{
    union CHashSet_T_Class * vtbl;
        struct
    {
      union Object Object;
      struct Bucket_T* _private buckets;
size_t _private size;
size_t _private count;
Hash_T _private hash;
HashComparator_T _private cmp;

    };
};

extern union CHashSet_T_Class * Get_CHashSet_T_Class(void);

extern void CHashSet_T_populate(union CHashSet_T * const chashset_t, Hash_T const hash, HashComparator_T const cmp);

extern void CHashSet_T_populate_reserved(union CHashSet_T * const chashset_t, size_t const elems, Hash_T const hash, HashComparator_T const cmp);

extern size_t CHashSet_T_size(union CHashSet_T * const chashset_t);

extern void CHashSet_T_clear(union CHashSet_T * const chashset_t);

extern void CHashSet_T_reserve(union CHashSet_T * const chashset_t, size_t const capacity);

extern T * CHashSet_T_begin(union CHashSet_T * const chashset_t);

extern T * CHashSet_T_end(union CHashSet_T * const chashset_t);

extern T * CHashSet_T_find(union CHashSet_T * const chashset_t, T const index);

extern void CHashSet_T_insert(union CHashSet_T * const chashset_t, T const value);

extern void CHashSet_T_erase(union CHashSet_T * const chashset_t, T const value);

#ifdef __cplusplus
}
#endif
#undef _private
