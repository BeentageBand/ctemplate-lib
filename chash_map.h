#if !defined(CHASH_MAP_H_) || defined(CHash_Map_Params)
#define CHASH_MAP_H_

#ifndef CHash_Map_Params
#error "CHash_Map_Params not defined"
#endif

#define CHash_Map_T TEMPLATE(CHash_Map, CHash_Map_Params, T)
#define CHash_Map_Class_T TEMPLATE(CHash_Map, CHash_Map_Params, Class_T)
#define CHash_Map_Pair_T TEMPLATE(Pair, CHash_Map_Params, T)
#define KEY_T T_Param(1, CHash_Map_Params)
#define OBJ_T T_Param(2, CHash_Map_Params)
#define CHash_Map_Method(method) TEMPLATE(CHash_Map, CHash_Map_Params, method)

#ifdef __cplusplus
extern "C" {
#endif
typedef struct Member_Name(Pair, CHash_Map_Params)
{
    KEY_T key;
    OBJ_T obj;
}CHash_Map_Pair_T;

#define CHash_Set_Params Member_Name(Pair,CHash_Map_Params)
#include "chash_set.h"

typedef TEMPLATE(CHash_Set, CHash_Set_Params, T) CHash_Map_T;
typedef TEMPLATE(CHash_Set, CHash_Set_Params, Cmp_T) CHash_Map_Cmp_T;
typedef TEMPLATE(CHash_Set, CHash_Set_Params, Class_T) CHash_Map_Class_T;

#undef CHash_Set_Params

extern CHash_Map_Class_T _private CHash_Map_Class;

extern void Method_Name(Populate, CHash_Map, CHash_Map_Params)(CHash_Map_T * const cmap, CHash_Map_Pair_T * const buff, size_t const buff_size, CHash_Map_Cmp_T const compare);

extern CHash_Map_Pair_T CHash_Map_Method(make_pair)(KEY_T const key, OBJ_T const obj);

#ifdef __cplusplus
}
#endif

#undef CHash_Map_T 
#undef CHash_Map_Class_T 
#undef CHash_Map_Pair_T 
#undef KEY_T
#undef OBJ_T

#endif /*CHASH_MAP_H_*/
