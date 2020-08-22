#include "cobject/cobject.h"

#ifdef CSET_T_IMPLEMENTATION 
#define cset_private
#else
#define cset_private const
#endif 

#ifdef __cplusplus
extern "C" {
#endif

union CSet_T;
union CSet_T_Class
{
    
    struct
    {
    struct Class Class;
    size_t (* cset_private size)(union CSet_T * const cset_t);
    void (* cset_private clear)(union CSet_T * const cset_t);
    T * (* cset_private begin)(union CSet_T * const cset_t);
    T * (* cset_private end)(union CSet_T * const cset_t);
    T * (* cset_private find)(union CSet_T * const cset_t, T const index);
    void (* cset_private insert)(union CSet_T * const cset_t, T const value);
    void (* cset_private erase)(union CSet_T * const cset_t, T const value);

    };
};

union CSet_T
{
    union CSet_T_Class * vtbl;
    struct
    {
      union Object Object;
      struct TreeNode_T * cset_private head;
      size_t cset_private size;
      Comparator_T cset_private cmp;

    };
};

extern union CSet_T_Class * Get_CSet_T_Class(void);

extern void CSet_T_populate(union CSet_T * const cset_t, struct TreeNode_T * const head, size_t const size, Comparator_T const cmp);

extern size_t CSet_T_size(union CSet_T * const cset_t);

extern void CSet_T_clear(union CSet_T * const cset_t);

extern T * CSet_T_begin(union CSet_T * const cset_t);

extern T * CSet_T_end(union CSet_T * const cset_t);

extern T * CSet_T_find(union CSet_T * const cset_t, T const index);

extern void CSet_T_insert(union CSet_T * const cset_t, T const value);

extern void CSet_T_erase(union CSet_T * const cset_t, T const value);

#ifdef __cplusplus
}
#endif

