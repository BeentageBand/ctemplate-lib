/*=====================================================================================*/
/**
 * cqueue.c
 * author : puch
 * date : Oct 22 2015
 *
 * description : Any comments
 *
 */
/*=====================================================================================*/
#define CLASS_IMPLEMENTATION Queue
/*=====================================================================================*
 * Project Includes
 *=====================================================================================*/
#include "cqueue.h"
/*=====================================================================================* 
 * Standard Includes
 *=====================================================================================*/

/*=====================================================================================* 
 * Local X-Macros
 *=====================================================================================*/
#ifndef Queue_Params
#error "define queue params"
#endif

#define _t1 CAT(T_Param(1, Queue_Params))
/*=====================================================================================* 
 * Local Define Macros
 *=====================================================================================*/

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
CLASS_DEF(Queue, Queue_Params)
/*=====================================================================================* 
 * Local Inline-Function Like Macros
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Function Definitions
 *=====================================================================================*/
// Your code goes here ...
void Method_Name(Queue, Queue_Params, Init)(void)
{
	_concat(CLASS_NAME,_Obj).capacity = 0;
	_concat(CLASS_NAME,_Obj).size = 0;
	_concat(CLASS_NAME,_Obj).buffer = NULL;
}

/*=====================================================================================*
 * Exported Function Definitions
 *=====================================================================================*/
union t_Queue(Queue_Params) Method_Name(Queue, Queue_Params, Queue)(union t_Queue(Queue_Params) const * v)
{
   union t_Queue(Queue_Params) this = Method_Name(Queue, Queue_Params, Populate)();
    this->size = v->size;
    this->capacity = v->capacity;
    this->buffer = (_t1*)malloc(sizeof(_template_t(1))*v->size);

    memcpy(this->buffer, v->buffer, this->size);
   return this;
}

union t_Queue(Queue_Params) * Method_Name(Queue, Queue_Params, Queue_New)(union t_Queue(Queue_Params) const * v)
{
   Constructor_New_Impl(t_Queue(Queue_Params), Queue, v);
}

union t_Queue(Queue_Params) Method_Name(Queue, Queue_Params, Size)(uint32_t const size)
{
   union t_Queue(Queue_Params) this = Method_Name(Queue, Queue_Params, Populate)();
    this->capacity = size;
    this->size = size;
    this->buffer = (_t1*)malloc(sizeof(_t1)*size);
   return this;
}

union t_Queue(Queue_Params) Method_Name(Queue, Queue_Params, Size)(uint32_t const size)
{
   Constructor_New_Impl(t_Queue(Queue_Params), Size, size);
}

union t_Queue(Queue_Params) Method_Name(Queue, Queue_Params, Initial)(uint32_t const size,
		_t1 const * initial)
{
   union t_Queue(Queue_Params) this = Method_Name(Queue, Queue_Params, Populate)();
    this->size = size;
    this->capacity = size;
    this->buffer = (_t1*)malloc(sizeof(_template_t(1))*size);

    for (uint32_t i = 0; i < size; i++)
    {
    	memcpy(&this->buffer[i], initial, sizeof(_t1));
    }
   return this;
}

union t_Queue(Queue_Params) Method_Name(Queue, Queue_Params, Initial)(uint32_t const size,
		_t1 const * initial)
{
   Constructor_New_Impl(t_Queue(Queue_Params), Initial, size, initial);
}

_t1 * const Method_Name(Queue, Queue_Params, begin)(union t_Queue(Queue_Params) * const this)
{
    return this->buffer;
}

_t1 * const Method_Name(Queue, Queue_Params, end)(union t_Queue(Queue_Params) * const this)
{
    return this->buffer + this->vtbl->size(this);
}

_t1 Method_Name(Queue, Queue_Params, front)(union t_Queue(Queue_Params) * const this)
{
    return this->buffer[0];
}

_t1 Method_Name(Queue, Queue_Params, back)(union t_Queue(Queue_Params) * const this)
{
    return this->buffer[this->size - 1];
}

void Method_Name(Queue, Queue_Params, push_back)(union t_Queue(Queue_Params) * const this, _t1 const * value)
{
    if (this->size >= this->capacity)
    {
        this->vtbl->reserve(this, this->capacity +5);
    }

    memcpy(&this->buffer[this->size++], value, sizeof(_t1));
}

void Method_Name(Queue, Queue_Params, pop_back)(union t_Queue(Queue_Params) * const this)
{
    this->size--;
#ifdef IS_TEMPLATE_T_DESTROYABLE
	_delete(&this->buffer[this->size])
#endif
}

void Method_Name(Queue, Queue_Params, push_front)(union t_Queue(Queue_Params) * const this, _t1 const * value)
{
    if (this->size >= this->capacity)
    {
        this->vtbl->reserve(this, this->capacity +5);
    }

    ++this->size;
    memcpy(this->buffer, &this->buffer[1], sizeof(_t1)* this->size);
    memcpy(this->buffer, value, sizeof(_t1));
}

void Method_Name(Queue, Queue_Params, pop_front)(union t_Queue(Queue_Params) * const this)
{
#ifdef IS_TEMPLATE_T_DESTROYABLE
	_delete(this->buffer)
#endif
    this->size--;
	memcpy(&this->buffer[1], this->buffer, sizeof(_t1)* this->size);
}


void Method_Name(Queue, Queue_Params, erase)(union t_Queue(Queue_Params) * const this,
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
void Method_Name(Queue, Queue_Params, reserve)(union t_Queue(Queue_Params) * const this, uint32_t capacity)
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

uint32_t Method_Name(Queue, Queue_Params, size)(union t_Queue(Queue_Params) * const this)
{
    return this->size;
}

void Method_Name(Queue, Queue_Params, resize)(union t_Queue(Queue_Params) * const this, uint32_t size)
{
    this->vtbl->reserve(this, size);
    this->size = size;
}

_t1 Method_Name(Queue, Queue_Params, at)(union t_Queue(Queue_Params) * const this, uint32_t index)
{
    return this->buffer[index];
}

uint32_t Method_Name(Queue, Queue_Params, capacity)(union t_Queue(Queue_Params) * const this)
{
    return this->capacity;
}

bool_t Method_Name(Queue, Queue_Params, empty)(union t_Queue(Queue_Params) * const this)
{
	return 0 == this->size;
}

void Method_Name(Queue, Queue_Params, Delete)(struct Object * const obj)
{
	union t_Queue(Queue_Params) * const this = _dynamic_cast(CLASS_NAME, obj);

    free(this->buffer);
}
void Method_Name(Queue, Queue_Params, clear)(union t_Queue(Queue_Params) * const this)
{
    this->capacity = 0;
    this->size = 0;
    this->buffer = 0;
}
/*=====================================================================================* 
 * cqueue.c
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
