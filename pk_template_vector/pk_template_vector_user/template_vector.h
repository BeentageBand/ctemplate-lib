/*=====================================================================================*/
/**
 * template_vector.h
 * author : puch
 * date : Oct 22 2015
 *
 * description : Any comments
 *
 */
/*=====================================================================================*/
#if !defined(TEMPLATE_VECTOR_H_) || defined(OBJECT_TEMPLATE)
#define TEMPLATE_VECTOR_H_
/*=====================================================================================*
 * Project Includes
 *=====================================================================================*/

/*=====================================================================================* 
 * Standard Includes
 *=====================================================================================*/
#include "template_vector_base.h"
/*=====================================================================================* 
 * Exported Define Macros
 *=====================================================================================*/
#undef CLASS_NAME
#undef CLASS_INHERITS
#undef CLASS_MEMBERS
#undef CLASS_METHODS

#define CLASS_NAME _template_1(Vector)

#define CLASS_INHERITS _template_1(Vector_Base)

#define CLASS_MEMBERS(_member)

#define CLASS_METHODS(_method, _void_method) \
void _method(ctor_size, size_t const, _template_t(1) const *) \
void _method(ctor_vector, _template_obj * const) \
size_t _void_method(size) \
size_t _void_method(max_size) \
void _method(resize, size_t const, _template_t(1) const *) \
size_t _void_method(capacity) \
bool_t _void_method(empty) \
void _method(reserve, size_t const) \
_template_t(1) _method(at, uint32_t) \
_template_t(1) _void_method(back) \
_template_t(1) _void_method(front) \
_template_t(1) const * _void_method(data) \
void _method(push_back, _template_t(1) const *) \
void _void_method(pop_back) \
void _void_method(clear) \
void _method(swap, _template_obj * const) \

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
 * template_vector.h
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
#endif /*TEMPLATE_VECTOR_H_*/
