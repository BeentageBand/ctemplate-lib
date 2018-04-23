#if !defined(CMAP_H_) || defined(CMap_Params)
#define CMAP_H_

#ifndef CMap_Params
#error "CMap_Params not defined"
#endif

#define CMap_T TEMPLATE(CMap, CMap_Params)
#define CMap_Class_T TEMPLATE(CMap, CMap_Params, Class)
#define CMap_Pair_T TEMPLATE(Pair, CMap_Params, T)
#define KEY_T T_Param(1, CMap_Params)
#define OBJ_T T_Param(2, CMap_Params)

#ifdef __cplusplus
extern "C" {
#endif
typedef struct Member_Name(Pair, CMap_Params)
{
    KEY_T key;
    OBJ_T obj;
}CMap_Pair_T;

#define CSet_Params CMap_Pair
#include "cset.h"

typedef CSet_T CMap_T;
typedef CSet_Cmp_T CMap_Cmp_T;

typedef union CSet_Class_T CMap_Class_T;

#undef CSet_Params

extern CMap_Class_T _private CMap_Class;

extern void Method_Name(Populate, CMap, CMap_Params)(CMap_T * const cmap, CMap_Pair_T * const buff, size_t const buff_size, CMap_Cmp_T const compare);

extern CMap_Pair_T CMap_Method(make_pair)(KEY_T const key, OBJ_T const obj);

#ifdef __cplusplus
}
#endif

#undef CMap_T 
#undef CMap_Class_T 
#undef CMap_Pair_T 
#undef KEY_T
#undef OBJ_T

#endif /*CMAP_H_*/
