/*=====================================================================================*/
/**
 * cvector.c
 * author : puch
 * date : Oct 22 2015
 *
 * description : Any comments
 *
 */
/*=====================================================================================*/
#define OBJECT_IMPLEMENTATION Vector
/*=====================================================================================*
 * Project Includes
 *=====================================================================================*/
#include "cvector.h"
/*=====================================================================================* 
 * Standard Includes
 *=====================================================================================*/

/*=====================================================================================* 
 * Local X-Macros
 *=====================================================================================*/
/*=====================================================================================* 
 * Local Define Macros
 *=====================================================================================*/
#ifndef Vector_Params
#error "Define Vector params"
#endif

#define _t1 CAT( T_Param(1, Vector_Params), _T)
/*=====================================================================================* 
 * Local Type Definitions
 *=====================================================================================*/
 
/*=====================================================================================* 
 * Local Function Prototypes
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Object Definitions
 *=====================================================================================*/

/*=====================================================================================* 
 * Exported Object Definitions
 *=====================================================================================*/
CLASS_DEF(Vector, Vector_Params)
/*=====================================================================================* 
 * Local Inline-Function Like Macros
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Function Definitions
 *=====================================================================================*/
// Your code goes here ...
void Method_Name(Vector, Vector_Params, Init)(void)
{
	_concat(Vector, Vector_Params,_Obj).capacity = 0;
	_concat(Vector, Vector_Params,_Obj).size = 0;
	_concat(Vector, Vector_Params,_Obj).buffer = NULL;
}

/*=====================================================================================*
 * Exported Function Definitions
 *=====================================================================================*/
union t_Vector(Vector_Params) Method_Name(Vector, Vector_Params, Vector)(union t_Vector(Vector_Params) const * v)
{
	union t_Vector(Vector_Params) this = Method_Name(Vector, Vector_Params, Populate)();
    this.size = v->size;
    this.capacity = v->capacity;
    this.buffer = (_t1*)malloc(sizeof(_t1)*v->size);

    memcpy(this->buffer, v->buffer, this->size);
    return this;
}

union t_Vector(Vector_Params) Method_Name(Vector, Vector_Params, Vector_New )(union t_Vector(Vector_Params) const * v)
{
   Constructor_New_Impl(t_Vector(Vector_Params), Vector, v)
}

union t_Vector(Vector_Params) Method_Name(Vector, Vector_Params, Size)(uint32_t const size)
{
   union t_Vector(Vector_Params) this = Method_Name(Vector, Vector_Params, Populate)();
    this->capacity = size;
    this->size = size;
    this->buffer = (_t1*)malloc(sizeof(_t1)*size);
    return this;
}

union t_Vector(Vector_Params) Method_Name(Vector, Vector_Params, Size)(uint32_t const size)
{
   Constructor_New_Impl(t_Vector(Vector_Params), Size, size)
}

union t_Vector(Vector_Params) Method_Name(Vector, Vector_Params, Initial)(uint32_t const size,
		_t1 const * initial)
{
   union t_Vector(Vector_Params) this = Method_Name(Vector, Vector_Params, Populate();
    this->size = size;
    this->capacity = size;
    this->buffer = (_t1*)malloc(sizeof(_t1)*size);

    for (uint32_t i = 0; i < size; i++)
    {
    	memcpy(&this->buffer[i], initial, sizeof(_t1));
    }
}

union t_Vector(Vector_Params) Method_Name(Vector, Vector_Params, Initial)(uint32_t const size,
		_t1 const * initial)
{
   Constructor_New_Impl(t_Vector(Vector_Params), Initial, size, initial)
}

_t1 * const Method_Name(Vector, Vector_Params, begin)(union t_Vector(Vector_Params) * const this)
{
    return this->buffer;
}

_t1 * const Method_Name(Vector, Vector_Params, end)(union t_Vector(Vector_Params) * const this)
{
    return this->buffer + this->vtbl->size(this);
}

_t1 Method_Name(Vector, Vector_Params, front)(union t_Vector(Vector_Params) * const this)
{
    return this->buffer[0];
}

_t1 Method_Name(Vector, Vector_Params, back)(union t_Vector(Vector_Params) * const this)
{
    return this->buffer[this->size - 1];
}

void Method_Name(Vector, Vector_Params, push_back)(union t_Vector(Vector_Params) * const this, _t1 const * value)
{
    if (this->size >= this->capacity)
    {
        this->vtbl->reserve(this, this->capacity +5);
    }

    memcpy(&this->buffer[this->size++], value, sizeof(_t1));
}

void Method_Name(Vector, Vector_Params, pop_back)(union t_Vector(Vector_Params) * const this)
{
    this->size--;
#ifdef IS_TEMPLATE_T_DESTROYABLE
	_delete(&this->buffer[this->size]);
#endif
}

void Method_Name(Vector, Vector_Params, reserve)(union t_Vector(Vector_Params) * const this, uint32_t capacity)
{
    if(NULL == this->buffer)
    {
        this->size = 0;
        this->capacity = 0;
    }
    _t1 * new_buff = (_t1*) malloc(sizeof(_t1)*capacity);

    uint32_t l_size = capacity < this->size ? capacity : this->size;

    for (uint32_t i = 0; i < l_size; i++)
    	memcpy(&new_buff[i], &this->buffer[i], sizeof(this->buffer[0]));

    this->capacity = capacity;
    free(this->buffer);
    this->buffer = new_buff;
}

uint32_t Method_Name(Vector, Vector_Params, size)(union t_Vector(Vector_Params) * const this)
{
    return this->size;
}

void Method_Name(Vector, Vector_Params, resize)(union t_Vector(Vector_Params) * const this, uint32_t size)
{
    this->vtbl->reserve(this, size);
    this->size = size;
}

_t1 Method_Name(Vector, Vector_Params, at)(union t_Vector(Vector_Params) * const this, uint32_t index)
{
    return this->buffer[index];
}

uint32_t Method_Name(Vector, Vector_Params, capacity)(union t_Vector(Vector_Params) * const this)
{
    return this->capacity;
}

bool_t Method_Name(Vector, Vector_Params, empty)(union t_Vector(Vector_Params) * const this)
{
	return 0 == this->size;
}

void Method_Name(Vector, Vector_Params, Dtor)(Object_T * const obj)
{
	union t_Vector(Vector_Params) * const this = _dynamic_cast(Vector, Vector_Params, obj);

    free(this->buffer);
}
void Method_Name(Vector, Vector_Params, clear)(union t_Vector(Vector_Params) * const this)
{
    this->capacity = 0;
    this->size = 0;
    this->buffer = 0;
}
/*=====================================================================================* 
 * cvector.c
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
