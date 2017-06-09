/*=====================================================================================*/
/**
 * template_vector.cpp
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
#include "template_vector.h"
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
/*class methods*/
static void _template_method(ctor_size)( _template_obj * const this, size_t const size, _template_t(1) const * val);
static void _template_method(ctor_vector)( _template_obj * const this, _template_obj * const vector) ;
static size_t _template_method(size)( _template_obj * const this) ;
static size_t _template_method(max_size)( _template_obj * const this) ;
static void _template_method(resize)( _template_obj * const this, size_t const size, _template_t(1) const * val) ;
static size_t _template_method(capacity)( _template_obj * const this) ;
static bool_t _template_method(empty)( _template_obj * const this) ;
static void _template_method(reserve)( _template_obj * const this, size_t const size) ;
static _template_t(1) _template_method(at)( _template_obj * const this, uint32_t i) ;
static _template_t(1) _template_method(back)( _template_obj * const this) ;
static _template_t(1) _template_method(front)( _template_obj * const this) ;
static _template_t(1) const * _template_method(data)( _template_obj * const this) ;
static void _template_method(push_back)( _template_obj * const this, _template_t(1) const * val) ;
static void _template_method(pop_back)( _template_obj * const this) ;
static void _template_method(clear)( _template_obj * const this) ;
static void _template_method(swap)( _template_obj * const this, _template_obj * const vector) ;

/* class private method */
static void _template_method(fill)(_template_obj * const this, _template_t(1) const * val);
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
void _template_method(init)(void)
{
   printf("%s \n", __FUNCTION__);
   _concat(CLASS_NAME,_Obj).CLASS_INHERITS = _template_1(Vector_Base)();
   _concat(CLASS_NAME,_Vtbl)._template_1(Vector_Base).Object.rtti = &_concat(CLASS_NAME,_Rtti);
   _concat(CLASS_NAME,_Vtbl)._template_1(Vector_Base).Object.destroy = _template_method(Dtor);
   _concat(CLASS_NAME,_Vtbl).ctor_size = _template_method(ctor_size);
   _concat(CLASS_NAME,_Vtbl).ctor_vector = _template_method(ctor_vector);
   _concat(CLASS_NAME,_Vtbl).size = _template_method(size);
   _concat(CLASS_NAME,_Vtbl).max_size = _template_method(max_size);
   _concat(CLASS_NAME,_Vtbl).resize = _template_method(resize);
   _concat(CLASS_NAME,_Vtbl).capacity = _template_method(capacity);
   _concat(CLASS_NAME,_Vtbl).empty = _template_method(empty);
   _concat(CLASS_NAME,_Vtbl).reserve = _template_method(reserve);
   _concat(CLASS_NAME,_Vtbl).at = _template_method(at);
   _concat(CLASS_NAME,_Vtbl).back = _template_method(back);
   _concat(CLASS_NAME,_Vtbl).front = _template_method(front);
   _concat(CLASS_NAME,_Vtbl).data = _template_method(data);
   _concat(CLASS_NAME,_Vtbl).push_back = _template_method(push_back);
   _concat(CLASS_NAME,_Vtbl).pop_back = _template_method(pop_back);
   _concat(CLASS_NAME,_Vtbl).clear = _template_method(clear);
   _concat(CLASS_NAME,_Vtbl).swap = _template_method(swap);

   _concat(CLASS_NAME,_Obj).vtbl = &_concat(CLASS_NAME,_Vtbl);


}
void _template_method(shut)(void) {}

void _template_method(Dtor)(Object_T * const obj)
{
}

/* class */
void _template_method(fill)(_template_obj * const this, _template_t(1) const * val)
{
	_template_t(1) * filler = this->CLASS_INHERITS.vector_impl.start;
	while(filler != this->CLASS_INHERITS.vector_impl.finish)
	{
		memcpy(filler, val, sizeof(_template_t(1) ) );
		++filler;
	}
}
/*=====================================================================================* 
 * Exported Function Definitions
 *=====================================================================================*/
void _template_method(ctor_size)( _template_obj * const this, size_t const size, _template_t(1) const * val)
{
	this->vtbl->CLASS_INHERITS.ctor_size(&this->CLASS_INHERITS, size * sizeof(_template_obj));
	_template_method(fill)(this, val);
}
void _template_method(ctor_vector)( _template_obj * const this, _template_obj * const vector)
{ /*TODO*/}

size_t _template_method(size)( _template_obj * const this)
{ /*TODO*/ return 0;}

size_t _template_method(max_size)( _template_obj * const this)
{ /*TODO*/ return 0;}

void _template_method(resize)( _template_obj * const this, size_t const size, _template_t(1) const * val)
{ /*TODO*/}

size_t _template_method(capacity)( _template_obj * const this)
{ /*TODO*/ return 0;}

bool_t _template_method(empty)( _template_obj * const this)
{ /*TODO*/ return false;}

void _template_method(reserve)( _template_obj * const this, size_t const size)
{ /*TODO*/}

_template_t(1) _template_method(at)( _template_obj * const this, uint32_t i)
      { /*TODO*/ return this->CLASS_INHERITS.vector_impl.start[i];}

_template_t(1) _template_method(back)( _template_obj * const this)
      { /*TODO*/ return *this->CLASS_INHERITS.vector_impl.finish;}

_template_t(1) _template_method(front)( _template_obj * const this)
{ /*TODO*/ return *this->CLASS_INHERITS.vector_impl.start;}

_template_t(1) const * _template_method(data)( _template_obj * const this)
      { /*TODO*/ return 0;}

void _template_method(push_back)( _template_obj * const this, _template_t(1) const * val)
      { /*TODO*/}

void _template_method(pop_back)( _template_obj * const this)
      { /*TODO*/}

void _template_method(clear)( _template_obj * const this)
      { /*TODO*/}

void _template_method(swap)( _template_obj * const this, _template_obj * const vector)
      { /*TODO*/}
/*=====================================================================================* 
 * template_vector.cpp
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
