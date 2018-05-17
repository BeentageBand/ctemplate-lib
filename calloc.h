#ifndef CALLOC_H_
#define CALLOC_H_

#include "ctemplate.h"

#ifndef CAlloc_Params
#error "CAlloc_Params not defined"
#endif

#define T_CAlloc(...) EVAL4(TEMPLATE(__VA_ARGS__))
#define _T1 T_Param(1, CAlloc_Params)

#ifdef __cplusplus
extern "C" {
#endif

typedef union T_Calloc(Calloc_Params)
{
   union T_Calloc(Calloc_Params, Class) _private * _private vtbl;
   struct
   {
      struct Object Object;
      _T1 _private * _private buff;
      size_t _private end;
   };
}T_Calloc(Calloc_Params, T);

typedef T_Calloc(Calloc_Params, T) T_Calloc(Heap, Calloc_Params, T);
typedef T_Calloc(Calloc_Params, T) T_Calloc(Pool, Calloc_Params, T);


typedef union T_Calloc(Calloc_Params, Class)
{
   struct
   {
      struct Class Class;
      _T1 * (* _private begin)(union T_Calloc(Calloc_Params) * const);
      _T1 * (* _private end)(union T_Calloc(Calloc_Params) * const);
      _T1 * (*_private alloc)(union T_Calloc(Calloc_Params) * const);
      void (* _private free)(union T_Calloc(Calloc_Params) * const, _T1 * const);
      size_t (* _private capacity)(union T_Calloc(Calloc_Params) * const);
   };
}T_Calloc(Calloc_Params, Class, T);

extern union T_Calloc(Calloc_Params, Class) T_Calloc(Heap, Calloc_Params, Class);
extern union T_Calloc(Calloc_Params, Class) T_Calloc(Pool, Calloc_Params, Class);

extern void Method_Name(Populate, Heap, Calloc, Calloc_Params)(union T_Calloc(Calloc_Params) * const this, size_t const alloc_size);

extern void Method_Name(Populate, Pool, Calloc, Calloc_Params)(union T_Calloc(Calloc_Params) * const this,
      _T1 * const allocated_buff, size_t const alloc_size);

#ifdef __cplusplus
}
#endif
#endif /*CALLOC_H_*/
