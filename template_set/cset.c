#define COBJECT_IMPLEMENTATION
 
#ifndef CSet_Params
#error "CSet Params is not defined"
#endif

#define CSet_T TEMPLATE(CSet, CSet_Params)
#define CSet_Class_T TEMPLATE(CSet, CSet_Params, Class)
#define T1 CAT(T_Params(1, CSet_Params), _T)
#define CSet_Method(method) TEMPLATE(CSet, CSet_Params, method)

static int CSet_Method(compare)(void *, void *);
static void CSet_Method(delete)(union CSet_T * const);
static uint32_t CSet_Method(size)(struct Object * const obj);
static void CSet_Method(clear)(union CSet_T * const);
static t1 * CSet_Method(begin)(union CSet_T * const);
static t1 * CSet_Method(end)(union CSet_T * const);
static t1 * CSet_Method(at)(union CSet_T * const, uint32_t const);
static t1 CSet_Method(access)(union CSet_T * const, uint32_t const);
static void CSet_Method(insert)(union CSet_T * const, t1 const);
static t1 * CSet_Method(find)(union CSet_T * const, t1 const * const);
static t1 * CSet_Method(erase)(union CSet_T * const, t1 const * const);

void CSet_Method(Init)(void)
{
	Member_Name(CSet_T,_Obj).capacity = 0;
	Member_Name(CSet_T,_Obj).size = 0;
	Member_Name(CSet_T,_Obj).buffer = NULL;
	Member_Name(CSet_T,_Obj).cmp = CSet_Method(default_cmp);
}

void CSet_Method(delete)(struct Object * const obj)
{
	union CSet_T * const this = Object_Cast(&CSet_Class_T.Class, obj);
	Isnt_Nullptr(this, );
	this->vtbl->clear(this);
}

int CSet_Method(compare)(void const * a, void const * b)
{
	return memcmp(a,b, sizeof(T1));
}
 
void Method_Name(Populate, CSet, CSet_Params)(union CSet_T const * s)
{
	if(NULL == CSet_T.vtbl)
	{
		CSet_T.vtbl = &CSet_Class_T;
		CSet_T.i = 0;
		CSet_T.buff = NULL;
    this->size = s->size;
    this->capacity = s->capacity;
    this->buffer = (T1*)malloc(sizeof(T1)*s->size);

    memcpy(this->buffer, s->buffer, this->size);
   return this;
}

union CSet_T * CSet_Method(Set_New)(union CSet_T const * s)
{
    Constructor_New_Impl(CSet_T, Set, s)
}

union CSet_T CSet_Method(Cmp)( * const this, Member_Name(CSet_T,Cmp_T) const cmp)
{

   union CSet_T this = CSet_Method(Populate)();
    this->cmp = cmp;
   return this;
}

union CSet_T * CSet_Method(Cmp_New)( * const this, Member_Name(CSet_T,_Cmp_T) const cmp)
{
    Constructor_New_Impl(CSet_T, Cmp_New, cmp)
}

T1 * const CSet_Method(begin)(union CSet_T * const this)
{
    return this->buffer;
}

T1 * const CSet_Method(end)(union CSet_T * const this)
{
    return this->buffer + this->vtbl->size(this);
}

uint32_t CSet_Method(capacity)(union CSet_T * const this)
{
    return this->capacity;
}

uint32_t CSet_Method(size)(union CSet_T * const this)
{
    return this->size;
}

void CSet_Method(clear)(union CSet_T * const this)
{
    this->capacity = 0;
    this->size = 0;
    this->buffer = NULL;
}

void CSet_Method(insert)(union CSet_T * const this, T1 const * value)
{
    if (this->size >= this->capacity)
    {
        this->vtbl->reserve(this, this->capacity +5);
    }

    memcpy(&this->buffer[this->size++], value, sizeof(T1));
    qsort(this->buffer, this->size, sizeof(T1), this->cmp);
}

void CSet_Method(erase)(union CSet_T * const this,
      T1 * const begin, T1 * const end)
{
   for( T1 * it = begin; it != end; ++it)
   {
      _delete(it);
   }

   this->size = end - this->vtbl->begin(this);
   memcpy(begin, end, this->size);

}

T1 * const CSet_Method(find)(union CSet_T * const this, T1 const * key)
{
   return (T1 * const) bsearch(key, this->buffer, this->size, sizeof(T1), this->cmp);
}

uint32_t CSet_Method(count)(union CSet_T * const this, T1 const * key)
{
	return 0;
}

T1 CSet_Method(at)(union CSet_T * const this, uint32_t index)
{
    return this->buffer[index];
}
