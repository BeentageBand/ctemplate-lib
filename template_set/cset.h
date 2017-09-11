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
#ifndef CSET_H_
#define CSET_H_
/*=====================================================================================*
 * Project Includes
 *=====================================================================================*/
#include "template.h"
/*=====================================================================================* 
 * Standard Includes
 *=====================================================================================*/

/*=====================================================================================* 
 * Exported Define Macros
 *=====================================================================================*/
#define Set_INHERITS Object

#define Set_MEMBERS(_member, _class, t1) \
   _member(uint32_t _private, size) \
   _member(uint32_t _private, capacity) \
   _member(t1 _private *, buffer) \
   _member(_concat(CLASS_NAME,_Cmp_T) _private, cmp) \

#define Set_METHODS(_method, _class, t1) \
   /* Contructors */\
   /* Iterators */\
   _method(t1 * const, _class, begin, void) \
   _method(t1 * const, _class, end, void) \
   /* Capacity */\
   _method(uint32_t, _class, capacity, void) \
   _method(uint32_t, _class, size, void) \
   _method(bool_t, _class, empty, void) \
   _method(void, _class, reserve, uint32_t const) \
   _method(void, _class, resize, uint32_t const) \
   /* Modifiers */\
   _method(void, _class, clear, void) \
   _method(void, _class, insert, t1 const *) \
   _method(void, _class, erase, t1 * const begin, t1 * const end) \
   /* Lookup */\
   _method(t1 * const, _class, find, t1 const *) \
   _method(uint32_t, _class, count, t1 const *) \
   _method(t1, _class, at, uint32_t const) \

#define Set_CONSTRUCTORS(_ctor, _class, t1) \
   _ctor(t_Set(t1), Cmp, Member_Name(t_Set(tq), Cmp_T) const) \
   _ctor(t_Set(t1), Set, union t_Set(t1) const *) \
typedef  int (*Member_Name(t_Set(t1), Cmp_T))(void const *, void const *);

#ifdef __cplusplus
extern "C" {
#endif
/*=====================================================================================* 
 * Exported Type Declarations
 *=====================================================================================*/

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
