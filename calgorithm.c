#ifndef CAlgo_Params
#error "CAlgo Params is not defined"
#endif

#define CAlgo_T TEMPLATE(CAlgo, CAlgo_Params)
#define CAlgo_Class_T TEMPLATE(CAlgo, CAlgo_Params, Class)
#define T1 T_Param(1, CAlgo_Params)
#define CAlgo_Method(method) TEMPLATE(CAlgo, CAlgo_Params, method)

static int CAlgo_Method(default_compare)(void const * a, void const * b);

int CAlgo_Method(default_compare)(void const * a, void const * b)
{
    return memcmp(a, b, sizeof(T1));
}

T1 * CAlgo_Method(find_first)(T1 * const begin, T1 * const end, T1 const v, CAlgo_Cmp_T compare)
{
    if(NULL == compare)
    {
        compare = CAlgo_Method(default_compare);
    }

    while (begin != end)
    {
        if(0 == compare(begin, &v, sizeof(v)))
        {
            return begin;
        }
        ++begin;
    }
    return end;
}

T1 * CAlgo_Method(maximum)(T1 * const begin, T1 * const end, CAlgo_Cmp_T compare)
{
    T1 * maximum = begin;
    if(NULL == compare)
    {
        compare = CAlgo_Method(default_compare);
    }
    while(begin != end)
    {
        if(1 <= compare(maximum, begin, sizeof(T1)))
        {
            maximum = begin;
        }
        ++begin;
    }

}

T1 * CAlgo_Method(minimum)(T1 * const begin, T1 * const end, T1 const v, CAlgo_Cmp_T compare)
{
    T1 * minimum = begin;

    if(NULL == compare)
    {
        compare = CAlgo_Method(default_compare);
    }
    while(begin != end)
    {
        if(-1 >= compare(maximum, begin, sizeof(T1)))
        {
            minimum = begin;
        }
        ++begin;
    }

}

void CAlgo_Method(erase)(T1 * const begin, T1 * const end, T1 * const pos)
{
    if(begin <= pos && pos < end)
    {
        memmove(pos, pos + 1, end - pos + 1);
        memset(end - 1, 0, sizeof(T1));
    }
}
