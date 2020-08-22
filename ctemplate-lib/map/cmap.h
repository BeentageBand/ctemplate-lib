#include "cobject/cobject.h"

#define Pair_Params CMap_Params
#include "pair.h"

#define Pair_T TEMPLATE(Pair, Pair_Params)
#define PairComparator_T TEMPLATE(PairComparator, Pair_Params)

#define CSet_Params Pair_T
#include "ctemplate-lib/set/cset-template.h"

#define CSet_T TEMPLATE(CSet, CSet_Params)
#define Comparator_T TEMPLATE(Comparator, CSet_Params)

#ifdef CMAP_T_IMPLEMENTATION 
#define cmap_private
#else
#define cmap_private const
#endif 

#ifdef __cplusplus
extern "C" {
#endif

union CMap_T;
union CMap_T_Class
{
  struct
  {
    struct Class Class;
    size_t (* cmap_private size)(union CMap_T * const cmap_t);
    void (* cmap_private clear)(union CMap_T * const cmap_t);
    Pair_T * (* cmap_private begin)(union CMap_T * const cmap_t);
    Pair_T * (* cmap_private end)(union CMap_T * const cmap_t);
    Pair_T * (* cmap_private find)(union CMap_T * const cmap_t, Key_T const index);
    void (* cmap_private insert)(union CMap_T * const cmap_t, Key_T const key, Value_T const value);
    void (* cmap_private erase)(union CMap_T * const cmap_t, Key_T const key);
  };
};

union CMap_T
{
    union CMap_T_Class * vtbl;
    struct
    {
      union Object Object;
      union CSet_T cmap_private set;
      PairComparator_T cmap_private cmp;
    };
};

extern union CMap_T_Class * Get_CMap_T_Class(void);

extern void CMap_T_populate(union CMap_T * const cmap_t, PairComparator_T const cmp);

extern size_t CMap_T_size(union CMap_T * const cmap_t);

extern void CMap_T_clear(union CMap_T * const cmap_t);

extern Pair_T * CMap_T_begin(union CMap_T * const cmap_t);

extern Pair_T * CMap_T_end(union CMap_T * const cmap_t);

extern Pair_T * CMap_T_find(union CMap_T * const cmap_t, Key_T const index);

extern void CMap_T_insert(union CMap_T * const cmap_t, Key_T const key, Value_T const value);

extern void CMap_T_erase(union CMap_T * const cmap_t, Key_T const key);

#ifdef __cplusplus
}
#endif
#undef Pair_T
#undef PairComparator_T
#undef Pair_Params
#undef CSet_T
#undef CSet_Params
