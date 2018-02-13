#if !defined(CSET_H_) || defined(CSet_Params)
#define CSET_H_
 
#include "ctemplate.h"

#ifndef CSet_Params
#error "CSet_Params not defined"
#endif

#define CSet_T TEMPLATE(CSet, CSet_Params)
#define CSet_Class_T TEMPLATE(CSet, CSet_Params, Class)
#define T1 T_Param(1, CSet_Params)

#ifdef __cplusplus
extern "C" {
#endif

typedef int (* CSet_Cmp_T)(void const *, void const *);

typedef union CSet_T
{
	struct CSet_Class_T _private * _private vtbl;
	struct
	{
		struct Object Object;
		uint32_t _private i;
		uint32_t _private capacity;
		T1 _private _private * _private buffer;
		CSet_Cmp_T _private compare;
	};
}TEMPLATE(CSet, CSet_Params, T);

typedef struct CSet_Class_T
{
        struct Class Class;
        uint32_t (* _private size)(union CSet_T * const);
        void (* _private clear)(union CSet_T * const);
        T1 * (* _private begin)(union CSet_T * const);
        T1 * (* _private end)(union CSet_T * const);
        T1 * (* _private at)(union CSet_T * const, uint32_t const);
        T1 (* _private access)(union CSet_T * const, uint32_t const);
        void (* _private insert)(union CSet_T * const, T1 const);
        T1 * (* _private find)(union CSet_T * const, T1 const);
        void (* _private erase)(union CSet_T * const, T1 const);
}TEMPLATE(CSet, CSet_Params, Class_T);

extern struct CSet_Class_T _private CSet_Class_T;

extern void Method_Name(Populate, CSet, CSet_Params)(union CSet_T * const set, T1 * const buff,
		size_t const buff_size);
 
extern void Method_Name(Populate, CSet_Cmp, CSet_Params)(union CSet_T * const set, T1 * const buff,
		size_t const buff_size, CSet_Cmp_T compare);

#ifdef __cplusplus
}
#endif

#undef CSet_T 
#undef CSet_Class_T 
#undef T1 
#endif /*CSET_H_*/
