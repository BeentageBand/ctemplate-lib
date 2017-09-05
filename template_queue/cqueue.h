/*=====================================================================================*/
/**
 * cqueue.h
 * author : puch
 * date : Oct 22 2015
 *
 * description : Any comments
 *
 */
/*=====================================================================================*/
#if !defined(CQUEUE_H_) || defined(OBJECT_TEMPLATE)
#define CQUEUE_H_
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

#define CLASS_NAME _template_1(Queue)

#define CLASS_INHERITS Object

#define CLASS_MEMBERS(_member) \
   _member(uint32_t _private, size) \
   _member(uint32_t _private, capacity) \
   _member(_template_t(1) _private *, buffer) \

#define CLASS_METHODS(_method, _void_method) \
   void _method(ctor_size, uint32_t const) \
   void _method(ctor_initial, uint32_t const, _template_t(1) const *) \
   void _method(ctor_queue, _template_obj const *) \
   uint32_t _void_method(capacity) \
   uint32_t _void_method(size) \
   bool_t _void_method(empty) \
   _template_t(1) * const _void_method(begin) \
   _template_t(1) * const _void_method(end) \
   _template_t(1) _void_method(front)\
   _template_t(1) _void_method(back)\
   void _method(push_back, _template_t(1) const *) \
   void _void_method(pop_back) \
   void _method(push_front, _template_t(1) const *) \
   void _void_method(pop_front) \
   void _method(erase, _template_t(1) * const begin, _template_t(1) * const end) \
   void _method(reserve, uint32_t const) \
   void _method(resize, uint32_t const) \
   _template_t(1) _method(at, uint32_t const) \
   _template_obj _method(cpy, _template_obj const *) \
   void _void_method(clear) \

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
 * cqueue.h
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
#endif /*CQUEUE_H_*/
