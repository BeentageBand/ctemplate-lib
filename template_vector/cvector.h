/*=====================================================================================*/
/**
 * cvector.h
 * author : puch
 * date : Oct 22 2015
 *
 * description : Any comments
 *
 */
/*=====================================================================================*/
#ifndef CVECTOR_H_
#define CVECTOR_H_
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
#define Vector_INHERITS BASE_CLASS

#define Vector_MEMBERS(_member, _class, t1) \
   _member(uint32_t _private, size) \
   _member(uint32_t _private, capacity) \
   _member(CAT(_t1, _T) _private * _private, buffer) \

#define Vector_METHODS(_method, _class, t1) \
   _method(uint32_t , t_Vector(t1), capacity, void) \
   _method(uint32_t , t_Vector(t1), size, void) \
   _method(bool_t , t_Vector(t1), empty, void) \
   _method(CAT(_t1, _T) *, t_Vector(t1), begin, void) \
   _method(CAT(_t1, _T) *, t_Vector(t1), end, void) \
   _method(CAT(_t1, _T), t_Vector(t1), front, void)\
   _method(CAT(_t1, _T), t_Vector(t1), back, void)\
   _method(void, t_Vector(t1), push_back, CAT(_t1, _T) const ) \
   _method(void, t_Vector(t1), pop_back, void) \
   _method(void, t_Vector(t1), reserve, uint32_t const) \
   _method(void, t_Vector(t1), resize, uint32_t const) \
   _method(CAT(_t1, _T), t_Vector(t1), at, uint32_t const) \
   _method(void , t_Vector(t1), clear, void) \

#define Vector_CONSTRUCTORS(_ctor, _class, t1) \
extern union t_Vector(t1) t_Vector(t1)(void); \
extern union t_Vector(t1) * CAT(t_Vector(t1), _New)(void); \
_ctor(t_Vector(t1),Size, uint32_t const) \
_ctor(t_Vector(t1),Initial, uint32_t const, CAT(t1,_T) const) \
_ctor(t_Vector(t1),Vector, union t_Vector(t1) const *) \

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
 * cvector.h
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
#endif /*CVECTOR_H_*/
