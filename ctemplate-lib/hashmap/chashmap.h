#include "cobject/cobject.h"

#ifdef CHASHMAP_T_IMPLEMENTATION 
#define chashmap_private
#else
#define chashmap_private const
#endif 

#ifdef __cplusplus
extern "C" {
#endif

union CHashMap_T;
union CHashMap_T_Class
{
    
    struct
    {
    struct Class Class;
    size_t (* chashmap_private size)(union CHashMap_T * const chashmap_t);
void (* chashmap_private clear)(union CHashMap_T * const chashmap_t);
HashPair_T * (* chashmap_private begin)(union CHashMap_T * const chashmap_t);
HashPair_T * (* chashmap_private end)(union CHashMap_T * const chashmap_t);
HashPair_T * (* chashmap_private find)(union CHashMap_T * const chashmap_t, HashKey_T const index);
void (* chashmap_private insert)(union CHashMap_T * const chashmap_t, HashKey_T const key, HashValue_T const value);
void (* chashmap_private erase)(union CHashMap_T * const chashmap_t, HashKey_T const key);

    };
};

union CHashMap_T
{
    union CHashMap_T_Class * vtbl;
        struct
    {
      union Object Object;
      union CHashSet_T chashmap_private set;
      HashPairComparator_T chashmap_private cmp;
      HashPairHash_T chashmap_private hash;
    };
};

extern union CHashMap_T_Class * Get_CHashMap_T_Class(void);

extern void CHashMap_T_populate(union CHashMap_T * const chashmap_t, HashPairHash_T const hash, HashPairComparator_T const cmp);

extern size_t CHashMap_T_size(union CHashMap_T * const chashmap_t);

extern void CHashMap_T_clear(union CHashMap_T * const chashmap_t);

extern HashPair_T * CHashMap_T_begin(union CHashMap_T * const chashmap_t);

extern HashPair_T * CHashMap_T_end(union CHashMap_T * const chashmap_t);

extern HashPair_T * CHashMap_T_find(union CHashMap_T * const chashmap_t, HashKey_T const index);

extern void CHashMap_T_insert(union CHashMap_T * const chashmap_t, HashKey_T const key, HashValue_T const value);

extern void CHashMap_T_erase(union CHashMap_T * const chashmap_t, HashKey_T const key);

#ifdef __cplusplus
}
#endif
