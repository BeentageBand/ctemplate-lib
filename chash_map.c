#ifndef CHash_Map_Params
#error "CHash_Map Params not defined"
#endif

#define CHash_Map_T TEMPLATE(CHash_Map, CHash_Map_Params, T)
#define CHash_Map_Class_T TEMPLATE(CHash_Map, CHash_Map_Params, Class_T)
#define CHash_Map_Pair_T TEMPLATE(Pair, CHash_Map_Params, T)
#define CHash_Map_Cmp_T TEMPLATE(CHash_Map, CHash_Map_Params, Cmp_T)
#define KEY_T T_Param(1, CHash_Map_Params)
#define OBJ_T T_Param(2, CHash_Map_Params)
#define CHash_Map_Method(method) TEMPLATE(CHash_Map, CHash_Map_Params, method)
#define CHash_Map_Member(member) TEMPLATE(CHash_Map, CHash_Map_Params, member)

#define CHash_Set_Params Member_Name(Pair,CHash_Map_Params)
#include "chash_set.c"
#undef CHash_Set_Params

static void CHash_Map_Method(delete)(struct Object * const obj);
static int CHash_Map_Method(cmp)(CHash_Map_Pair_T const * hash, CHash_Map_Pair_T const * b);
static CHash_Map_Pair_T * CHash_Map_Method(find)(CHash_Map_T * const hash, KEY_T const k);
static void CHash_Map_Method(insert)(CHash_Map_T * const hash, KEY_T const k, OBJ_T const obj);

CHash_Map_Class_T CHash_Map_Member(Class) = 
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

static CHash_Map_T TEMPLATE(CHash_Map, CHash_Map_Params) = {NULL};

void CHash_Map_Method(delete)(struct Object * const obj)
{
}

int CHash_Map_Method(cmp)(CHash_Map_Pair_T const * a, CHash_Map_Pair_T const * b)
{
    return a->key - b->key;
}

CHash_Map_Pair_T * CHash_Map_Method(find)(CHash_Map_T * const hash, KEY_T const k)
{
    CHash_Map_Pair_T pair = {0};
    pair.key = k;
    return hash->TEMPLATE(CHash_Set, Member_Name(Pair,CHash_Map_Params)).vtbl->find(
            &hash->TEMPLATE(CHash_Set, Member_Name(Pair,CHash_Map_Params)),
            pair);
}

void CHash_Map_Method(insert)(CHash_Map_T * const hash, KEY_T const k, OBJ_T const obj)
{
    CHash_Map_Pair_T pair = CHash_Map_Method(make_pair)(k, obj);
    return hash->TEMPLATE(CHash_Set, Member_Name(Pair,CHash_Map_Params)).vtbl->insert(
            &hash->TEMPLATE(CHash_Set, Member_Name(Pair,CHash_Map_Params)),
            pair);
}

void TEMPLATE(Populate, CHash_Map, CHash_Map_Params)(CHash_Map_T * const this, CHash_Map_Pair_T * const buff, size_t buff_size,
                 CHash_Map_Cmp_T const cmp)
{
    if(NULL == TEMPLATE(CHash_Map, CHash_Map_Params).vtbl)
    {
        this->vtbl = &CHash_Map_Member(Class);
    }
    TEMPLATE(Populate, CHash_Set, Member_Name(Pair,CHash_Map_Params))(&this->TEMPLATE(CHash_Set, Member_Name(Pair,CHash_Map_Params)),
                buff,
                buff_size, 
                NULL,
                (NULL != cmp)? cmp : CHash_Map_Method(cmp));
}

CHash_Map_Pair_T CHash_Map_Method(make_pair)(KEY_T const key, OBJ_T const obj)
{
    CHash_Map_Pair_T pair = {key, obj};
    return pair;
}

#undef CHash_Map_T 
#undef CHash_Map_Class_T 
#undef CHash_Map_Pair_T 
#undef CHash_Map_Cmp_T
#undef KEY_T
#undef OBJ_T
#undef CHash_Map_Method
#undef CHash_Map_Member
