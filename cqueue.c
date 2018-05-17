#ifndef CQueue_Params
#error "define queue params"
#endif

#define CQueue(...) TEMPLATE(CQueue, __VA_ARGS__)
#define CQueue_T TEMPLATE(CQueue, CQueue_Params)
#define CQueue_Class_T TEMPLATE(CQueue, CQueue_Params, Class)
#define T1 T_Param(1, CQueue_Params)
#define CQueue_Method(method) Method_Name(CQueue, CQueue_Params, method)

static void CQueue_Method(delete)(struct Object * const obj);
static uint32_t CQueue_Method(size)(union CQueue_T * const);
static void CQueue_Method(clear)(union CQueue_T * const);
static T1 * CQueue_Method(begin)(union CQueue_T * const);
static T1 * CQueue_Method(end)(union CQueue_T * const);
static T1 * CQueue_Method(at)(union CQueue_T * const, uint32_t const);
static T1 CQueue_Method(access)(union CQueue_T * const, uint32_t const);
static void CQueue_Method(push_back)(union CQueue_T * const, T1 const);
static void CQueue_Method(push_front)(union CQueue_T * const, T1 const);
static T1 CQueue_Method(back)(union CQueue_T * const);
static T1 CQueue_Method(front)(union CQueue_T * const);
static void CQueue_Method(pop_back)(union CQueue_T * const);
static void CQueue_Method(pop_front)(union CQueue_T * const);

union CQueue_Class_T CQueue_Class_T =
{
   {{CQueue_Method(delete)},
   CQueue_Method(size),
   CQueue_Method(clear),
   CQueue_Method(begin),
   CQueue_Method(end),
   CQueue_Method(at),
   CQueue_Method(access),
   CQueue_Method(push_back),
   CQueue_Method(push_front),
   CQueue_Method(back),
   CQueue_Method(front),
   CQueue_Method(pop_back),
   CQueue_Method(pop_front)}
};

static union CQueue_T CQueue_T = {NULL};

void CQueue_Method(delete)(struct Object * const obj)
{
   union CQueue_T * const this = (union CQueue_T *) Object_Cast(&CQueue_Class_T.Class, obj);
   Isnt_Nullptr(this, );

   this->i = 0;
}
 
void Method_Name(Populate, CQueue, CQueue_Params)(union CQueue_T * const this, 
      T1 * const buff, size_t const buff_size)
{
   if(NULL == CQueue_T.vtbl)
   {
      CQueue_T.vtbl = &CQueue_Class_T;
      CQueue_T.capacity = 0;
      CQueue_T.i = 0;
      CQueue_T.buffer = NULL;
   }

   memcpy(this, &CQueue_T, sizeof(CQueue_T));

    this->capacity = buff_size;
    this->buffer = buff;
}

T1 * CQueue_Method(begin)(union CQueue_T * const this)
{
    return this->buffer;
}

T1 * CQueue_Method(end)(union CQueue_T * const this)
{
    return this->buffer + this->i;
}

T1 CQueue_Method(front)(union CQueue_T * const this)
{
    return this->buffer[0];
}

T1 CQueue_Method(back)(union CQueue_T * const this)
{
    return this->buffer[this->i - 1];
}

void CQueue_Method(push_back)(union CQueue_T * const this, T1 const value)
{
    if (this->i >= this->capacity) return;
   this->buffer[this->i] = value;
   ++this->i;
}

void CQueue_Method(pop_back)(union CQueue_T * const this)
{
    if(this->i)
    {
        this->i--;
#ifdef CQUEUE_DELETABLE
        Object_Delete((struct Object *)(this->buffer + this->i));
#else
        memset(this->buffer + this->i, 0, sizeof(this->buffer[this->i]));
#endif
    }
}

void CQueue_Method(push_front)(union CQueue_T * const this, T1 const value)
{
    if (this->i >= this->capacity) return;

   memcpy(this->buffer + 1, this->buffer, this->i * sizeof(this->buffer[0]));

   this->buffer[0] = value;
   ++this->i;
}

void CQueue_Method(pop_front)(union CQueue_T * const this)
{
    if(this->i)
    {
        --this->i;
#ifdef CQUEUE_DELETABLE
        Object_Delete((struct Object *)(this->buffer));
#endif
        memmove(this->buffer, this->buffer + 1, sizeof(this->buffer[0]) * this->i);
        memset(this->buffer + this->i, 0, sizeof(this->buffer[this->i]));
    }
}

uint32_t CQueue_Method(size)(union CQueue_T * const this)
{
    return (size_t)this->i;
}


T1 * CQueue_Method(at)(union CQueue_T * const this, uint32_t const index)
{
    return this->buffer + index;
}

T1 CQueue_Method(access)(union CQueue_T * const this, uint32_t const index)
{
   return this->buffer[index];
}

uint32_t CQueue_Method(capacity)(union CQueue_T * const this)
{
    return this->capacity;
}

void CQueue_Method(clear)(union CQueue_T * const this)
{
   while(this->i)
   {
      this->vtbl->pop_back(this);
   }
}

#undef CQueue
#undef CQueue_T 
#undef CQueue_Class_T 
#undef T1 
