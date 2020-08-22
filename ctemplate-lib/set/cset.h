#include "cobject/cobject.h"

#define TreeNode_Params CSet_Params
#include "treenode.h"

#define TreeNode_T TEMPLATE(TreeNode, TreeNode_Params)
#define Comparator_T TEMPLATE(Comparator, TreeNode_Params)

#ifdef CSET_T_IMPLEMENTATION 
#define _private
#else
#define _private const
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
    size_t (* _private size)(union CSet_T * const cset_t);
    void (* _private clear)(union CSet_T * const cset_t);
    T * (* _private begin)(union CSet_T * const cset_t);
    T * (* _private end)(union CSet_T * const cset_t);
    T * (* _private find)(union CSet_T * const cset_t, T const index);
    void (* _private insert)(union CSet_T * const cset_t, T const value);
    void (* _private erase)(union CSet_T * const cset_t, T const value);

    };
};

union CSet_T
{
    union CSet_T_Class * vtbl;
    struct
    {
      union Object Object;
      struct TreeNode_T * _private head;
      size_t _private size;
      Comparator_T _private cmp;

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

#undef TreeNode_T 
#undef Comparator_T 
#undef TreeNode_Params
