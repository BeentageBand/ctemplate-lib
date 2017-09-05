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
#define CLASS_IMPLEMENTATION
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

/*=====================================================================================* 
 * Local Type Definitions
 *=====================================================================================*/
 
/*=====================================================================================* 
 * Local Function Prototypes
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Object Definitions
 *=====================================================================================*/
static void _template_method(ctor_size)(_template_obj * const this, uint32_t const size);
static void _template_method(ctor_initial)(_template_obj * const this, uint32_t const size,
		_template_t(1) const * initial);
static void _template_method(ctor_vector)(_template_obj * const this, _template_obj const * v);
static void _template_method(Dtor)(Object_T * const obj);

static uint32_t _template_method(capacity)(_template_obj * const this);
static uint32_t _template_method(size)(_template_obj * const this);
static bool_t _template_method(empty)(_template_obj * const this);
static _template_t(1) * const _template_method(begin)(_template_obj * const this);
static _template_t(1) * const _template_method(end)(_template_obj * const this);
static _template_t(1) _template_method(front)(_template_obj * const this);
static _template_t(1) _template_method(back)(_template_obj * const this);
static void _template_method(push_back)(_template_obj * const this, _template_t(1) const * value);
static void _template_method(pop_back)(_template_obj * const this);
static void _template_method(reserve)(_template_obj * const this, uint32_t capacity);
static void _template_method(resize)(_template_obj * const this, uint32_t size);
static _template_t(1) _template_method(at)(_template_obj * const this, uint32_t index);
static _template_obj _template_method(cpy)(_template_obj * const this, _template_obj const * v);
static void _template_method(clear)(_template_obj * const this);


/*=====================================================================================* 
 * Exported Object Definitions
 *=====================================================================================*/
CLASS_DEFINITION
/*=====================================================================================* 
 * Local Inline-Function Like Macros
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Function Definitions
 *=====================================================================================*/
// Your code goes here ...
void _template_method(init)(void)
{
	_concat(CLASS_NAME,_Obj).capacity = 0;
	_concat(CLASS_NAME,_Obj).size = 0;
	_concat(CLASS_NAME,_Obj).buffer = NULL;

	_concat(CLASS_NAME,_Vtbl).object.destroy = _template_method(Dtor);
	_concat(CLASS_NAME,_Vtbl).ctor_size = _template_method(ctor_size);
	_concat(CLASS_NAME,_Vtbl).ctor_initial = _template_method(ctor_initial);
	_concat(CLASS_NAME,_Vtbl).ctor_vector = _template_method(ctor_vector);
	_concat(CLASS_NAME,_Vtbl).capacity = _template_method(capacity);
	_concat(CLASS_NAME,_Vtbl).size = _template_method(size);
	_concat(CLASS_NAME,_Vtbl).empty = _template_method(empty);
	_concat(CLASS_NAME,_Vtbl).begin = _template_method(begin);
	_concat(CLASS_NAME,_Vtbl).end = _template_method(end);
	_concat(CLASS_NAME,_Vtbl).front = _template_method(front);
	_concat(CLASS_NAME,_Vtbl).back = _template_method(back);
	_concat(CLASS_NAME,_Vtbl).push_back = _template_method(push_back);
	_concat(CLASS_NAME,_Vtbl).pop_back = _template_method(pop_back);
	_concat(CLASS_NAME,_Vtbl).reserve = _template_method(reserve);
	_concat(CLASS_NAME,_Vtbl).resize = _template_method(resize);
	_concat(CLASS_NAME,_Vtbl).at = _template_method(at);
	_concat(CLASS_NAME,_Vtbl).cpy = _template_method(cpy);
	_concat(CLASS_NAME,_Vtbl).clear = _template_method(clear);
}

void _template_method(shut)(void)
		{

		}
/*=====================================================================================*
 * Exported Function Definitions
 *=====================================================================================*/




void _template_method(ctor_vector)(_template_obj * const this, _template_obj const * v)
{
    this->size = v->size;
    this->capacity = v->capacity;
    this->buffer = (_template_t(1)*)malloc(sizeof(_template_t(1))*v->size);

    memcpy(this->buffer, v->buffer, this->size);
}

void _template_method(ctor_size)(_template_obj * const this, uint32_t const size)
{
    this->capacity = size;
    this->size = size;
    this->buffer = (_template_t(1)*)malloc(sizeof(_template_t(1))*size);
}

void _template_method(ctor_initial)(_template_obj * const this, uint32_t const size,
		_template_t(1) const * initial)
{
    this->size = size;
    this->capacity = size;
    this->buffer = (_template_t(1)*)malloc(sizeof(_template_t(1))*size);

    for (uint32_t i = 0; i < size; i++)
    {
    	memcpy(&this->buffer[i], initial, sizeof(_template_t(1)));
    }
}

_template_obj _template_method(cpy)(_template_obj * const this, _template_obj const * v)
{
    free(this->buffer);
    this->vtbl->ctor_vector(this, v);
    return *this;
}

_template_t(1) * const _template_method(begin)(_template_obj * const this)
{
    return this->buffer;
}

_template_t(1) * const _template_method(end)(_template_obj * const this)
{
    return this->buffer + this->vtbl->size(this);
}

_template_t(1) _template_method(front)(_template_obj * const this)
{
    return this->buffer[0];
}

_template_t(1) _template_method(back)(_template_obj * const this)
{
    return this->buffer[this->size - 1];
}

void _template_method(push_back)(_template_obj * const this, _template_t(1) const * value)
{
    if (this->size >= this->capacity)
    {
        this->vtbl->reserve(this, this->capacity +5);
    }

    memcpy(&this->buffer[this->size++], value, sizeof(_template_t(1)));
}

void _template_method(pop_back)(_template_obj * const this)
{
    this->size--;
#ifdef IS_TEMPLATE_T_DESTROYABLE
	_delete(&this->buffer[this->size]);
#endif
}

void _template_method(reserve)(_template_obj * const this, uint32_t capacity)
{
    if(NULL == this->buffer)
    {
        this->size = 0;
        this->capacity = 0;
    }
    _template_t(1) * new_buff = (_template_t(1)*) malloc(sizeof(_template_t(1))*capacity);

    uint32_t l_size = capacity < this->size ? capacity : this->size;

    for (uint32_t i = 0; i < l_size; i++)
    	memcpy(&new_buff[i], &this->buffer[i], sizeof(this->buffer[0]));

    this->capacity = capacity;
    free(this->buffer);
    this->buffer = new_buff;
}

uint32_t _template_method(size)(_template_obj * const this)
{
    return this->size;
}

void _template_method(resize)(_template_obj * const this, uint32_t size)
{
    this->vtbl->reserve(this, size);
    this->size = size;
}

_template_t(1) _template_method(at)(_template_obj * const this, uint32_t index)
{
    return this->buffer[index];
}

uint32_t _template_method(capacity)(_template_obj * const this)
{
    return this->capacity;
}

bool_t _template_method(empty)(_template_obj * const this)
{
	return 0 == this->size;
}

void _template_method(Dtor)(Object_T * const obj)
{
	_template_obj * const this = _dynamic_cast(CLASS_NAME, obj);

    free(this->buffer);
}
void _template_method(clear)(_template_obj * const this)
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
