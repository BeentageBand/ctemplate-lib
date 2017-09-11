/*=====================================================================================*/
/**
 * cset.c
 * author : puch
 * date : Oct 22 2015
 *
 * description : Any comments
 *
 */
/*=====================================================================================*/
#define CLASS_IMPLEMENTATION Set
/*=====================================================================================*
 * Project Includes
 *=====================================================================================*/
#include "cset.h"
/*=====================================================================================* 
 * Standard Includes
 *=====================================================================================*/

/*=====================================================================================* 
 * Local X-Macros
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Define Macros
 *=====================================================================================*/
#ifndef Set_Params
#error "Set Params is not defined"
#endif

#define _t1 CAT(T_Param(1, Set_Params), _T)
/*=====================================================================================* 
 * Local Type Definitions
 *=====================================================================================*/
 
/*=====================================================================================* 
 * Local Function Prototypes
 *=====================================================================================*/
static int Method_Name(Set, Set_Params, default_cmp)(void const * a, void const * b);
/*=====================================================================================* 
 * Local Object Definitions
 *=====================================================================================*/
CLASS_DEF(Set, Set_Params)
/*=====================================================================================* 
 * Exported Object Definitions
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Inline-Function Like Macros
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Function Definitions
 *=====================================================================================*/
// Your code goes here ...
void Method_Name(Set, Set_Params, Init)(void)
{
	Member_Name(t_Set(Set_Params),_Obj).capacity = 0;
	Member_Name(t_Set(Set_Params),_Obj).size = 0;
	Member_Name(t_Set(Set_Params),_Obj).buffer = NULL;
	Member_Name(t_Set(Set_Params),_Obj).cmp = Method_Name(Set, Set_Params, default_cmp);
}

void Method_Name(Set, Set_Params, Delete)(struct Object * const obj)
{
	union t_Set(Set_Params) * const this = _dynamic_cast(t_Set(Set_Params), obj);

    free(this->buffer);
}

int Method_Name(Set, Set_Params, default_cmp)(void const * a, void const * b)
{
	return memcmp(a,b, sizeof(_t1));
}
/*=====================================================================================* 
 * Exported Function Definitions
 *=====================================================================================*/
union t_Set(Set_Params) Method_Name(Set, Set_Params, Set)(union t_Set(Set_Params) const * s)
{
   union t_Set(Set_Params) this = Method_Name(Set, Set_Params, Populate)();
    this->size = s->size;
    this->capacity = s->capacity;
    this->buffer = (_t1*)malloc(sizeof(_template_t(1))*s->size);

    memcpy(this->buffer, s->buffer, this->size);
   return this;
}

union t_Set(Set_Params) * Method_Name(Set, Set_Params, Set_New)(union t_Set(Set_Params) const * s)
{
    Constructor_New_Impl(t_Set(Set_Params), Set, s)
}

union t_Set(Set_Params) Method_Name(Set, Set_Params, Cmp)( * const this, Member_Name(t_Set(Set_Params),Cmp_T) const cmp)
{

   union t_Set(Set_Params) this = Method_Name(Set, Set_Params, Populate)();
    this->cmp = cmp;
   return this;
}

union t_Set(Set_Params) * Method_Name(Set, Set_Params, Cmp_New)( * const this, Member_Name(t_Set(Set_Params),_Cmp_T) const cmp)
{
    Constructor_New_Impl(t_Set(Set_Params), Cmp_New, cmp)
}

_t1 * const Method_Name(Set, Set_Params, begin)(union t_Set(Set_Params) * const this)
{
    return this->buffer;
}

_t1 * const Method_Name(Set, Set_Params, end)(union t_Set(Set_Params) * const this)
{
    return this->buffer + this->vtbl->size(this);
}

uint32_t Method_Name(Set, Set_Params, capacity)(union t_Set(Set_Params) * const this)
{
    return this->capacity;
}

uint32_t Method_Name(Set, Set_Params, size)(union t_Set(Set_Params) * const this)
{
    return this->size;
}

bool_t Method_Name(Set, Set_Params, empty)(union t_Set(Set_Params) * const this)
{
	return 0 == this->size;
}

void Method_Name(Set, Set_Params, reserve)(union t_Set(Set_Params) * const this, uint32_t capacity)
{
    if(NULL == this->buffer)
    {
        this->size = 0;
        this->capacity = 0;
    }
    _t1 * new_buff = (_template_t(1)*) malloc(sizeof(_template_t(1))*capacity);

    uint32_t l_size = capacity < this->size ? capacity : this->size;

    for (uint32_t i = 0; i < l_size; i++)
    	memcpy(&new_buff[i], &this->buffer[i], sizeof(this->buffer[0]));

    this->capacity = capacity;

    if(NULL != this->buffer)
    {
       free(this->buffer);
    }

    this->buffer = new_buff;
}


void Method_Name(Set, Set_Params, resize)(union t_Set(Set_Params) * const this, uint32_t size)
{
    this->vtbl->reserve(this, size);
    this->size = size;
}

void Method_Name(Set, Set_Params, clear)(union t_Set(Set_Params) * const this)
{
    this->capacity = 0;
    this->size = 0;
    this->buffer = NULL;
}

void Method_Name(Set, Set_Params, insert)(union t_Set(Set_Params) * const this, _t1 const * value)
{
    if (this->size >= this->capacity)
    {
        this->vtbl->reserve(this, this->capacity +5);
    }

    memcpy(&this->buffer[this->size++], value, sizeof(_t1));
    qsort(this->buffer, this->size, sizeof(_t1), this->cmp);
}

void Method_Name(Set, Set_Params, erase)(union t_Set(Set_Params) * const this,
      _t1 * const begin, _template_t(1) * const end)
{
#ifdef IS_TEMPLATE_T_DESTROYABLE
   for( _t1 * it = begin; it != end; ++it)
   {
      _delete(it);
   }
#endif

   this->size = end - this->vtbl->begin(this);
   memcpy(begin, end, this->size);

}

_t1 * const Method_Name(Set, Set_Params, find)(union t_Set(Set_Params) * const this, _template_t(1) const * key)
{
   return (_t1 * const) bsearch(key, this->buffer, this->size, sizeof(_template_t(1)), this->cmp);
}

uint32_t Method_Name(Set, Set_Params, count)(union t_Set(Set_Params) * const this, _t1 const * key)
{
	return 0;
}

_t1 Method_Name(Set, Set_Params, at)(union t_Set(Set_Params) * const this, uint32_t index)
{
    return this->buffer[index];
}

/*=====================================================================================* 
 * cset.c
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
