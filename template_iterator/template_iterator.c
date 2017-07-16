/*=====================================================================================*/
/**
 * template_iterator.cpp
 * author : puch
 * date : Oct 22 2015
 *
 * description : Any comments
 *
 */
/*=====================================================================================*/
#define OBJECT_TEMPLATE
#define CLASS_IMPLEMENTATION
/*=====================================================================================*
 * Project Includes
 *=====================================================================================*/
#include "template_iterator.h"
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
static void _template_method(ctor_iterator)(_template_obj * const , _template_obj * const) ;
static _template_t(1) * _template_method(access)(_template_obj * const ) ;
static _template_obj * _template_method(iterate)(_template_obj * const ) ;
static _template_obj *  _template_method(at)(_template_obj * const , uint32_t) ;
static _template_t(1) * _template_method(base)(_template_obj * const ) ;
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
   _concat(CLASS_NAME,_Obj).current = NULL;
   _concat(CLASS_NAME,_Vtbl).Object.rtti = &_concat(CLASS_NAME,_Rtti);
   _concat(CLASS_NAME,_Vtbl).Object.destroy = _template_method(Dtor);
   _concat(CLASS_NAME,_Vtbl).ctor_iterator = _template_method(ctor_iterator);
   _concat(CLASS_NAME,_Vtbl).access = _template_method(access);
   _concat(CLASS_NAME,_Vtbl).iterate = _template_method(iterate);
   _concat(CLASS_NAME,_Vtbl).at = _template_method(at);
   _concat(CLASS_NAME,_Vtbl).base = _template_method(base);
}
void _template_method(shut)(void) {}

void _template_method(Dtor)(Object_T * const obj)
{
}
/*=====================================================================================* 
 * Exported Function Definitions
 *=====================================================================================*/
void _template_method(ctor_iterator)(_template_obj * const this, _template_obj * const it)
{
	this->current = it->current;
}

_template_t(1) * _template_method(access)(_template_obj * const this)
{
	return this->current;
}

_template_obj * _template_method(iterate)(_template_obj * const this)
{
	++this->current;
	return this;
}
_template_obj *  _template_method(at)(_template_obj * const this, uint32_t offset)
{
	this->current += offset;
	return  this;
}
_template_t(1) * _template_method(base)(_template_obj * const this)
{
	return this->current;
}
/*=====================================================================================* 
 * template_iterator.cpp
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
