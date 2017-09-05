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
#define CLASS_IMPLEMENTATION
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

/*=====================================================================================* 
 * Local Type Definitions
 *=====================================================================================*/
 
/*=====================================================================================* 
 * Local Function Prototypes
 *=====================================================================================*/
static void _template_method(ctor_cmp)(_template_obj * const this, _concat(CLASS_NAME,_Cmp_T) const cmp);
static void _template_method(ctor_set)(_template_obj * const this, _template_obj const * s);
static void _template_method(Dtor)(Object_T * const obj);

static _template_t(1) * const _template_method(begin)(_template_obj * const this);
static _template_t(1) * const _template_method(end)(_template_obj * const this);

static uint32_t _template_method(capacity)(_template_obj * const this);
static uint32_t _template_method(size)(_template_obj * const this);
static bool_t _template_method(empty)(_template_obj * const this);
static void _template_method(reserve)(_template_obj * const this, uint32_t capacity);
static void _template_method(resize)(_template_obj * const this, uint32_t size);

static void _template_method(clear)(_template_obj * const this);
static void _template_method(insert)(_template_obj * const this, _template_t(1) const * value);
static void _template_method(erase)(_template_obj * const this,
       _template_t(1) * const begin, _template_t(1) * const end);

static _template_t(1) * const _template_method(find)(_template_obj * const this, _template_t(1) const * value);
static uint32_t _template_method(count)(_template_obj * const this, _template_t(1) const * value);
static _template_t(1) _template_method(at)(_template_obj * const this, uint32_t index);
static _template_obj _template_method(cpy)(_template_obj * const this, _template_obj const * s);
static int _template_method(default_cmp)(void const * a, void const * b);
/*=====================================================================================* 
 * Local Object Definitions
 *=====================================================================================*/
CLASS_DEFINITION
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
void _template_method(init)(void)
{
	_concat(CLASS_NAME,_Obj).capacity = 0;
	_concat(CLASS_NAME,_Obj).size = 0;
	_concat(CLASS_NAME,_Obj).buffer = NULL;
	_concat(CLASS_NAME,_Obj).cmp = _template_method(default_cmp);

	_concat(CLASS_NAME,_Vtbl).object.destroy = _template_method(Dtor);
	_concat(CLASS_NAME,_Vtbl).ctor_cmp = _template_method(ctor_cmp);
	_concat(CLASS_NAME,_Vtbl).ctor_set = _template_method(ctor_set);

	_concat(CLASS_NAME,_Vtbl).capacity = _template_method(capacity);
	_concat(CLASS_NAME,_Vtbl).size = _template_method(size);
	_concat(CLASS_NAME,_Vtbl).empty = _template_method(empty);
	_concat(CLASS_NAME,_Vtbl).reserve = _template_method(reserve);
	_concat(CLASS_NAME,_Vtbl).resize = _template_method(resize);

	_concat(CLASS_NAME,_Vtbl).begin = _template_method(begin);
	_concat(CLASS_NAME,_Vtbl).end = _template_method(end);

	_concat(CLASS_NAME,_Vtbl).clear = _template_method(clear);
	_concat(CLASS_NAME,_Vtbl).insert = _template_method(insert);
   _concat(CLASS_NAME,_Vtbl).erase = _template_method(erase);

	_concat(CLASS_NAME,_Vtbl).find = _template_method(find);
    _concat(CLASS_NAME,_Vtbl).count = _template_method(count);
	_concat(CLASS_NAME,_Vtbl).at = _template_method(at);
	_concat(CLASS_NAME,_Vtbl).cpy = _template_method(cpy);
}

void _template_method(shut)(void)
		{

		}

void _template_method(Dtor)(Object_T * const obj)
{
	_template_obj * const this = _dynamic_cast(CLASS_NAME, obj);

    free(this->buffer);
}

int _template_method(default_cmp)(void const * a, void const * b)
{
	return memcmp(a,b, sizeof(_template_t(1)));
}
/*=====================================================================================* 
 * Exported Function Definitions
 *=====================================================================================*/
void _template_method(ctor_set)(_template_obj * const this, _template_obj const * s)
{
    this->size = s->size;
    this->capacity = s->capacity;
    this->buffer = (_template_t(1)*)malloc(sizeof(_template_t(1))*s->size);

    memcpy(this->buffer, s->buffer, this->size);
}

void _template_method(ctor_cmp)(_template_obj * const this, _concat(CLASS_NAME,_Cmp_T) const cmp)
{
    this->cmp = cmp;
}

_template_t(1) * const _template_method(begin)(_template_obj * const this)
{
    return this->buffer;
}

_template_t(1) * const _template_method(end)(_template_obj * const this)
{
    return this->buffer + this->vtbl->size(this);
}

uint32_t _template_method(capacity)(_template_obj * const this)
{
    return this->capacity;
}

uint32_t _template_method(size)(_template_obj * const this)
{
    return this->size;
}

bool_t _template_method(empty)(_template_obj * const this)
{
	return 0 == this->size;
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

    if(NULL != this->buffer)
    {
       free(this->buffer);
    }

    this->buffer = new_buff;
}


void _template_method(resize)(_template_obj * const this, uint32_t size)
{
    this->vtbl->reserve(this, size);
    this->size = size;
}

void _template_method(clear)(_template_obj * const this)
{
    this->capacity = 0;
    this->size = 0;
    this->buffer = NULL;
}

void _template_method(insert)(_template_obj * const this, _template_t(1) const * value)
{
    if (this->size >= this->capacity)
    {
        this->vtbl->reserve(this, this->capacity +5);
    }

    memcpy(&this->buffer[this->size++], value, sizeof(_template_t(1)));
    qsort(this->buffer, this->size, sizeof(_template_t(1)), this->cmp);
}

void _template_method(erase)(_template_obj * const this,
      _template_t(1) * const begin, _template_t(1) * const end)
{
#ifdef IS_TEMPLATE_T_DESTROYABLE
   for( _template_t(1) * it = begin; it != end; ++it)
   {
      _delete(it);
   }
#endif

   this->size = end - this->vtbl->begin(this);
   memcpy(begin, end, this->size);

}

_template_t(1) * const _template_method(find)(_template_obj * const this, _template_t(1) const * key)
{
   return (_template_t(1) * const) bsearch(key, this->buffer, this->size, sizeof(_template_t(1)), this->cmp);
}

uint32_t _template_method(count)(_template_obj * const this, _template_t(1) const * key)
{
	return 0;
}

_template_t(1) _template_method(at)(_template_obj * const this, uint32_t index)
{
    return this->buffer[index];
}

_template_obj _template_method(cpy)(_template_obj * const this, _template_obj const * s)
{
    free(this->buffer);
    this->vtbl->ctor_set(this, s);
    return *this;
}
/*=====================================================================================* 
 * cset.c
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
