#define COBJECT_IMPLEMENTATION
 
#include "dbg_log.h"


#ifndef CMap_Params
#error "CMap Params not defined"
#endif

#define CMap_T TEMPLATE(CMap, CMap_Params)
#define CMap_Class_T TEMPLATE(CMap, CMap_Params, Class)
#define CMap_Pair_T TEMPLATE(Pair, CMap_Params, T)
#define KEY_T T_Param(1, CMap_Params)
#define OBJ_T T_Param(2, CMap_Params)
#define CMap_Method(method) TEMPLATE(CMap, CMap_Params, method)

#define CSet_Params CMap_Pair
#include "cset.c"
typedef CSet_T CMap_T;

static void CMap_Method(delete)(struct Object * const obj);
static int CMap_Method(cmp)(CMap_Pair_T * a, CMap_Pair_T * b);

CMap_Class_T CMap_Class = 
{
    {CMap_Method(delete), NULL},
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

static CMap_T CMap = {NULL};

void CMap_Method(delete)(struct Object * const obj)
{
}

int CMap_Method(cmp)(CMap_Pair_T * a, CMap_Pair_T * b)
{
    return a->key - b->key;
}

void Method_Name(Populate, CMap, CMap_Params)(CMap_T * const this, CMap_Pair_T * const buff, size_t buff_size,
                 CMap_Cmp_T cmp)
{
    if(NULL == Method_Name(CMap, CMap_Params).vtbl)
    {
        Method_Name(Populate, CSet, CSet_Params)(&this->Method_Name(CSet, CSet_Params), buff, buff_size, CMap_Method(cmp));
        Object_Init(&Member_Name(CMap, CMap_Params).Object, &Member_Name(CMap, CMap_Params, Class).Class,
                    sizeof(Member_Name(CMap, CMap_Params,Class).CSet));
    }
    Method_Name(Populate, CSet, CSet_Params)(&this->Method_Name(CSet, CSet_Params), buff,
                buff_size, (cmp)? cmp : CMap_Method(cmp));
    this->vtbl = &Member_Name(CMap, CMap_Params, Class);
}

CMap_Pair_T CMap_Method(make_pair)(KEY_T const key, OBJ_T const obj)
{
    CMap_Pair_T pair = {key, obj};
    return pair;
}