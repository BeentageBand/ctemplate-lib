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
#ifndef CQUEUE_H_
#define CQUEUE_H_
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
#define Queue_INHERITS BASE_CLASS

#define Queue_MEMBERS(_member, _class, t1) \
   _member(uint32_t _private, size) \
   _member(uint32_t _private, capacity) \
   _member(CAT(t1, _T) _private *, buffer) \

#define Queue_METHODS(_method, _class, t1) \
_method(void, t_Queue(t1), Size, uint32_t const) \
_method(void , t_Queue(t1), Initial, uint32_t const, CAT(t1, _T) const *) \
_method(void , t_Queue(t1), Queue, union t_Queue(t1) const *) \
_method(uint32_t, t_Queue(t1), capacity, void) \
_method(uint32_t , t_Queue(t1), size, void) \
_method(bool_t _, t_Queue(t1), empty, void) \
_method(CAT(t1, _T) * const, t_Queue(t1), begin, void) \
_method(CAT(t1, _T) * const, t_Queue(t1), end, void) \
_method(CAT(t1, _T), t_Queue(t1), front, void)\
_method(CAT(t1, _T), t_Queue(t1), back, void)\
_method(void, t_Queue(t1), push_back, CAT(t1, _T) const *) \
_method(void, t_Queue(t1), pop_back, void) \
_method(void, t_Queue(t1),  push_front, CAT(t1, _T)(1) const *) \
_method(void, t_Queue(t1),  pop_front, void) \
_method(void, t_Queue(t1), erase, CAT(t1, _T) * const begin, CAT(_t1, _T) * const end) \
_method(void, t_Queue(t1), reserve, uint32_t const) \
_method(void, t_Queue(t1), resize, uint32_t const) \
_method(CAT(t1, _T), t_Queue(t1),  at, uint32_t const) \
_method(union t_Queue(t1),  cpy, union t_Queue(t1) const *) \
_method(void, t_Queue(t1), clear, void) \

#define Queue_CONSTRUCTORS(_ctor)

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
 * cqueue.h
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
#endif /*CQUEUE_H_*/
