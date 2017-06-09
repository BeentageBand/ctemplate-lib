/*=====================================================================================*/
/**
 * template_vector_types.h
 * author : puch
 * date : Oct 22 2015
 *
 * description : Any comments
 *
 */
/*=====================================================================================*/
#if !defined(TEMPLATE_VECTOR_BASE_H_) || defined(OBJECT_TEMPLATE)
#define TEMPLATE_VECTOR_BASE_H_
/*=====================================================================================*
 * Project Includes
 *=====================================================================================*/
#include "object_template.h"
/*=====================================================================================* 
 * Standard Includes
 *=====================================================================================*/

/*=====================================================================================* 
 * Exported Define Macros
 *=====================================================================================*/
#undef CLASS_NAME
#undef CLASS_INHERITS
#undef CLASS_MEMBERS
#undef CLASS_METHODS
/*FIXME rm this define */

#define CLASS_NAME _template_1(Vector_Base)

#define CLASS_INHERITS Object

#define CLASS_MEMBERS(_member) \
_member(struct _template_1(Vector_Impl)  _private, vector_impl)

#define CLASS_METHODS(_method, _void_method) \
void _method(ctor_size, size_t const) \
_template_t(1) * _method(allocate, size_t const) \
void _method(deallocate, _template_t(1) *, size_t const) \

#ifdef __cplusplus
extern "C" {
#endif
/*=====================================================================================* 
 * Exported Type Declarations
 *=====================================================================================*/
struct _template_1(Vector_Impl)
{
	_template_t(1) * _private start;
	_template_t(1) * _private finish;
	_template_t(1) * _private end_of_storage;
};

CLASS_DECLARATION
/*=====================================================================================* 
 * Exported Object Declarations
 *=====================================================================================*/

/*=====================================================================================* 
 * Exported Function Prototypes
 *=====================================================================================*/

/*=====================================================================================* 
 * Exported Function Like Macros
 *=====================================================================================*/
#ifdef __cplusplus
}
#endif
/*=====================================================================================* 
 * template_vector_types.h
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
#endif /*TEMPLATE_VECTOR_BASE_H_*/
