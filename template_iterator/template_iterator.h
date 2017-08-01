/*=====================================================================================*/
/**
 * template_iterator.h
 * author : puch
 * date : Oct 22 2015
 *
 * description : Any comments
 *
 */
/*=====================================================================================*/
#ifndef TEMPLATE_ITERATOR_H_
#define TEMPLATE_ITERATOR_H_
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
#undef CLASS_CONSTRUCTORS

typedef int Int_T;
typedef int * Array_T;

#define _template_t1 Int
#define _template_t2  Array

#define CLASS_NAME _template_2(Iterator)

#define CLASS_INHERITS Object

#define CLASS_MEMBERS(_member) \
_member(_template_t(1) * _private, current) \

#define CLASS_METHODS(_method, _void_method) \
_method(void, ctor_iterator, _template_obj * const) \
_void_method(_template_t(1) *, access) \
_void_method(_template_obj *, iterate) \
_method(_template_obj *, at, uint32_t) \
_void_method(_template_t(1) *, base) \

#define CLASS_CONSTRUCTORS(_ctor)

#ifdef __cplusplus
extern "C" {
#endif
/*=====================================================================================* 
 * Exported Type Declarations
 *=====================================================================================*/
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
 * template_iterator.h
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
#endif /*TEMPLATE_ITERATOR_H_*/
