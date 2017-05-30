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
#include "template_vector_base.h"
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
static void _template_method(ctor_size)(_template_obj * const this, size_t const size);
static _template_t(1) * _template_method(allocate)(_template_obj * const this, size_t const size);
static void _template_method(deallocate)(_template_obj * const this, _template_t(1) * const pointer, size_t const size);
static void _template_method(create_storage)(_template_obj * const this, size_t const size);

/* Vector Impl */
static struct _template_1(Vector_Impl) _template_1(Vector_Impl)(void);
static void _concat(_template_1(Vector_Impl),_Dtor)(struct _template_1(Vector_Impl) * const this);
static void _concat(_template_1(Vector_Impl),_swap)(struct _template_1(Vector_Impl) * const this, struct _template_1(Vector_Impl) * const swap);
/*=====================================================================================* 
 * Local Object Definitions
 *=====================================================================================*/

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
void _template_method(init)(void)
{
   printf("%s \n", __FUNCTION__);
   _concat(CLASS_NAME,_Vtbl).Object.rtti = &_concat(CLASS_NAME,_Rtti);
   _concat(CLASS_NAME,_Vtbl).Object.destroy = _template_method(Dtor);
   _concat(CLASS_NAME,_Vtbl).ctor_size = _template_method(ctor_size);
   _concat(CLASS_NAME,_Vtbl).allocate = _template_method(allocate);
   _concat(CLASS_NAME,_Vtbl).deallocate = _template_method(deallocate);
   _concat(CLASS_NAME,_Obj).vector_impl = _template_1(Vector_Impl)();

}
void _template_method(shut)(void) {}

void _template_method(Dtor)(Object_T * const obj)
{
	_template_obj * this = _dynamic_cast(CLASS_NAME, obj);
	if(NULL==this) return;
	this->vtbl->deallocate(this->vector_impl.start,
			this->vector_impl.end_of_storage - this->vector_impl.start);
}

void _template_method(create_storage)(_template_obj * const this, size_t const size)
{
	this->vector_impl.start = this->vtbl->allocate(this, size);
	this->vector_impl.finish = this->vector_impl.start;
	this->vector_impl.end_of_storage = this->vector_impl.start + size;
}

struct _template_1(Vector_Impl) _template_1(Vector_Impl)(void)
{
	struct _template_1(Vector_Impl) _template_1(Vector_Impl);
	_template_1(Vector_Impl).start = NULL;
	_template_1(Vector_Impl).finish = NULL;
	_template_1(Vector_Impl).end_of_storage = NULL;

	return _template_1(Vector_Impl);
}

void _concat(_template_1(Vector_Impl),_Dtor)(struct _template_1(Vector_Impl) * const this)
{
	this->start = NULL;
	this->finish = NULL;
	this->end_of_storage = NULL;
}

void _concat(_template_1(Vector_Impl),_swap)(struct _template_1(Vector_Impl) * const this, struct _template_1(Vector_Impl) * const swap)
{
	this->start += swap->start;
	this->finish += swap->finish;
	this->end_of_storage += swap->end_of_storage;

	swap->start = this->start - swap->start;
	swap->finish = this->finish - swap->finish;
	swap->end_of_storage = this->end_of_storage - swap->end_of_storage;

	this->start -= swap->start;
	this->finish -= swap->finish;
	this->end_of_storage -= swap->end_of_storage;
}
/*=====================================================================================*
 * Exported Function Definitions
 *=====================================================================================*/
void _template_method(ctor_size)(_template_obj * const this, size_t const size)
{
	_template_method(create_storage)(&this, size);
}

_template_t(1) * _template_method(allocate)(_template_obj * const this, size_t const size)
{
   printf("%s instance\n", __FUNCTION__);
   return malloc(size);
}

void _template_method(deallocate)(_template_obj * const this, _template_t(1) * const pointer,
	size_t const size)
{
	printf("%s instance\n", __FUNCTION__);
	if(NULL != pointer)
	{
	   free(this->vector_impl.start);
	   _concat(_template_1(Vector_Impl),_Dtor)(&this->vector_impl);
	}
}
/*=====================================================================================* 
 * template_vector.cpp
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
