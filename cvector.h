#if !defined(CVECTOR_H_) || defined(CVector_Params)
#define CVECTOR_H_
 
#include "ctemplate.h"
 
#ifndef CVector_Params
#error "CVector_Params is not defined"
#endif

#define CVector_T TEMPLATE(CVector, CVector_Params)
#define CVector_Class_T TEMPLATE(CVector, CVector_Params, Class)
#define T1 T_Param(1, CVector_Params)

#ifdef __cplusplus
extern "C" {
#endif

typedef union CVector_T
{
   union CVector_Class_T _private * _private vtbl;
   struct
   {
      struct Object Object;
      uint32_t _private i;
      size_t _private capacity;
      T1 _private * _private buffer;
   };
}TEMPLATE(CVector, CVector_Params, T);

typedef union CVector_Class_T
{
   struct
   {
      struct Class Class;
      uint32_t (* _private size)(union CVector_T * const);
      void (* _private clear)(union CVector_T * const);
      T1 * (* _private begin)(union CVector_T * const);
      T1 * (* _private end)(union CVector_T * const);
      T1 * (* _private at)(union CVector_T * const, uint32_t const);
      T1 (* _private access)(union CVector_T * const, uint32_t const);
      void (* _private push_back)(union CVector_T * const, T1 const);
      T1 (* _private back)(union CVector_T * const);
      void (* _private pop_back)(union CVector_T * const);
   };
}TEMPLATE(CVector, CVector_Params, Class_T);


extern union CVector_Class_T  _private CVector_Class_T;

extern void TEMPLATE(Populate, CVector, CVector_Params)(union CVector_T * const vector, T1 * const, size_t const);

#ifdef __cplusplus
}
#endif

#undef CVector_T
#undef CVector_Class_T
#undef T1
#undef CVector_Method

#endif /*CVECTOR_H_*/
