#ifndef CVector_Params
#error "Define Vector params"
#endif

#define CVector_T TEMPLATE(CVector, CVector_Params)
#define CVector_Class_T TEMPLATE(CVector, CVector_Params, Class)
#define T1 T_Param(1, CVector_Params)
#define CVector_Method(method) TEMPLATE(CVector, CVector_Params, method)

void CVector_Method(delete)(struct Object * const);
uint32_t CVector_Method(size)(union CVector_T * const);
void CVector_Method(clear)(union CVector_T * const);
T1 * CVector_Method(begin)(union CVector_T * const);
T1 * CVector_Method(end)(union CVector_T * const);
T1 * CVector_Method(at)(union CVector_T * const, uint32_t const);
T1 CVector_Method(access)(union CVector_T * const, uint32_t const);
void CVector_Method(push_back)(union CVector_T * const, T1 const);
T1 CVector_Method(back)(union CVector_T * const);
void CVector_Method(pop_back)(union CVector_T * const);

union CVector_Class_T CVector_Class_T = 
{
   {{CVector_Method(delete), NULL},
   CVector_Method(size),
   CVector_Method(clear),
   CVector_Method(begin),
   CVector_Method(end),
   CVector_Method(at),
   CVector_Method(access),
   CVector_Method(push_back),
   CVector_Method(back),
   CVector_Method(pop_back)}
};

static union CVector_T CVector_T = {NULL};


void CVector_Method(delete)(struct Object * const obj)
{
   union CVector_T * const this = (union CVector_T *) Object_Cast(&CVector_Class_T.Class, obj);
   Isnt_Nullptr(this, );

   this->vtbl->clear(this);
}
 
void  Method_Name(Populate, CVector, CVector_Params)(union CVector_T * const this,
      T1 * const buff, size_t const buff_size)
{
   if(NULL == CVector_T.vtbl)
   {
      CVector_T.vtbl = &CVector_Class_T;
      CVector_T.capacity = 0;
      CVector_T.i = 0;
      CVector_T.buffer = NULL;
   }

   memcpy(this, &CVector_T, sizeof(CVector_T));

    this->capacity = buff_size;
    this->buffer = buff;
}

T1 * CVector_Method(begin)(union CVector_T * const this)
{
    return this->buffer;
}

T1 * CVector_Method(end)(union CVector_T * const this)
{
    return this->buffer + this->vtbl->size(this);
}

T1 CVector_Method(back)(union CVector_T * const this)
{
    return this->buffer[this->i - 1];
}

void CVector_Method(push_back)(union CVector_T * const this, T1 const value)
{
    if (this->i >= this->capacity) return;
   this->buffer[this->i] = value;
   ++this->i;
}

void CVector_Method(pop_back)(union CVector_T * const this)
{
   if(this->i)
   {
      --this->i;
#ifdef CVECTOR_DELETABLE
      Object_Delete((struct Object *)(this->buffer+this->i));
#else
      memset(this->buffer + this->i, 0, sizeof(this->buffer[this->i]));
#endif
   }
}

uint32_t CVector_Method(size)(union CVector_T * const this)
{
    return (size_t)this->i;
}

T1 * CVector_Method(at)(union CVector_T * const this, uint32_t index)
{
    return this->buffer+index;
}

T1 CVector_Method(access)(union CVector_T * const this, uint32_t index)
{
    return this->buffer[index];
}

uint32_t CVector_Method(capacity)(union CVector_T * const this)
{
    return this->capacity;
}

void CVector_Method(clear)(union CVector_T * const this)
{
    while(this->i)
   {
      this->vtbl->pop_back(this);
   }
}

#undef CVector_T
#undef CVector_Class_T
#undef T1
#undef CVector_Method
