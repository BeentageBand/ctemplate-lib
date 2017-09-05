/*=====================================================================================*/
/**
 * cset.h
 * author : puch
 * date : Oct 22 2015
 *
 * description : Any comments
 *
 */
/*=====================================================================================*/
#if !defined(CSET_H_) || defined(OBJECT_TEMPLATE)
#define CSET_H_
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

#define CLASS_NAME _template_1(Set)

#define CLASS_INHERITS Object

#define CLASS_MEMBERS(_member) \
   _member(uint32_t _private, size) \
   _member(uint32_t _private, capacity) \
   _member(_template_t(1) _private *, buffer) \
   _member(_concat(CLASS_NAME,_Cmp_T) _private, cmp) \

#define CLASS_METHODS(_method, _void_method) \
   /* Contructors */\
   void _method(ctor_cmp, _concat(CLASS_NAME,_Cmp_T) const) \
   void _method(ctor_set, _template_obj const *) \
   /* Iterators */\
   _template_t(1) * const _void_method(begin) \
   _template_t(1) * const _void_method(end) \
   /* Capacity */\
   uint32_t _void_method(capacity) \
   uint32_t _void_method(size) \
   bool_t _void_method(empty) \
   void _method(reserve, uint32_t const) \
   void _method(resize, uint32_t const) \
   /* Modifiers */\
   void _void_method(clear) \
   void _method(insert, _template_t(1) const *) \
   void _method(erase, _template_t(1) * const begin, _template_t(1) * const end) \
   /* Lookup */\
   _template_t(1) * const _method(find, _template_t(1) const *) \
   uint32_t _method(count, _template_t(1) const *) \
   _template_t(1) _method(at, uint32_t const) \
   _template_obj _method(cpy, _template_obj const *) \

#ifdef __cplusplus
extern "C" {
#endif
/*=====================================================================================* 
 * Exported Type Declarations
 *=====================================================================================*/
typedef  int (*_concat(CLASS_NAME,_Cmp_T))(void const *, void const *);
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
 * cset.h
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
#endif /*CSET_H_*/
