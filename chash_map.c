#define COBJECT_IMPLEMENTATION
#include "dbg_log.h"


#ifndef CHash_Map_Params
#error "CHash_Map Params not defined"
#endif

#define CHash_Map_T TEMPLATE(CHash_Map, CHash_Map_Params, T)
#define CHash_Map_Class_T TEMPLATE(CHash_Map, CHash_Map_Params, Class_T)
#define CHash_Map_Pair_T TEMPLATE(Pair, CHash_Map_Params, T)
#define KEY_T T_Param(1, CHash_Map_Params)
#define OBJ_T T_Param(2, CHash_Map_Params)
#define CHash_Map_Method(method) TEMPLATE(CHash_Map, CHash_Map_Params, method)

#define CHash_Set_Params Member_Name(Pair,CHash_Map_Params)
#include "chash_set.c"
#undef CHash_Set_Params

static void CHash_Map_Method(delete)(struct Object * const obj);
static int CHash_Map_Method(cmp)(CHash_Map_Pair_T * a, CHash_Map_Pair_T * b);

CHash_Map_Class_T CHash_Map_Class = 
{
    {CHash_Map_Method(delete), NULL},
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

static CHash_Map_T CHash_Map = {NULL};

void CHash_Map_Method(delete)(struct Object * const obj)
{
}

int CHash_Map_Method(cmp)(CHash_Map_Pair_T * a, CHash_Map_Pair_T * b)
{
    return a->key - b->key;
}

void Method_Name(Populate, CHash_Map, CHash_Map_Params)(CHash_Map_T * const this, CHash_Map_Pair_T * const buff, size_t buff_size,
                 CHash_Map_Cmp_T cmp)
{
    if(NULL == Method_Name(CHash_Map, CHash_Map_Params).vtbl)
    {
        Method_Name(Populate, CHash_Set, CHash_Set_Params)(&this->Method_Name(CHash_Set, CHash_Set_Params), buff, buff_size, CHash_Map_Method(cmp));
        Object_Init(&Member_Name(CHash_Map, CHash_Map_Params).Object, &Member_Name(CHash_Map, CHash_Map_Params, Class).Class,
                    sizeof(Member_Name(CHash_Map, CHash_Map_Params,Class).CHash_Set));
    }
    Method_Name(Populate, CHash_Set, CHash_Set_Params)(&this->Method_Name(CHash_Set, CHash_Set_Params), buff,
                buff_size, (cmp)? cmp : CHash_Map_Method(cmp));
    this->vtbl = &Member_Name(CHash_Map, CHash_Map_Params, Class);
}

CHash_Map_Pair_T CHash_Map_Method(make_pair)(KEY_T const key, OBJ_T const obj)
{
    CHash_Map_Pair_T pair = {key, obj};
    return pair;
}

#undef CHash_Map_T 
#undef CHash_Map_Class_T 
#undef CHash_Map_Pair_T 
#undef KEY_T
#undef OBJ_T
#undef CHash_Map_Method
