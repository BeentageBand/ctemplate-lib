#if !defined(CQUEUE_H_) || defined(CQueue_Params)
#define CQUEUE_H_
 
#include "ctemplate.h"
 
#ifndef CQueue_Params
#error "CQueue_Params is not defined"
#endif

#define CQueue_T TEMPLATE(CQueue, CQueue_Params)
#define CQueue_Class_T TEMPLATE(CQueue, CQueue_Params, Class)
#define T1 T_Param(1, CQueue_Params)

#ifdef __cplusplus
extern "C" {
#endif

typedef union CQueue_T
{
	union CQueue_Class_T _private * _private vtbl; 
	struct 
	{
		struct Object Object;
		uint32_t _private i;
		size_t _private capacity;
		T1 _private * _private buffer;
	};
}TEMPLATE(CQueue, CQueue_Params, T);

typedef union CQueue_Class_T
{
	struct
	{
		struct Class Class;
		uint32_t (* _private size)(union CQueue_T * const);
		void (* _private clear)(union CQueue_T * const);
		T1 * (* _private begin)(union CQueue_T * const);
		T1 * (* _private end)(union CQueue_T * const);
		T1 * (* _private at)(union CQueue_T * const, uint32_t const);
		T1 (* _private access)(union CQueue_T * const, uint32_t const);
		void (* _private push_back)(union CQueue_T * const, T1 const);
		void (* _private push_front)(union CQueue_T * const, T1 const);
		T1 (* _private back)(union CQueue_T * const);
		T1 (* _private front)(union CQueue_T * const);
		void (* _private pop_back)(union CQueue_T * const);
		void (* _private pop_front)(union CQueue_T * const);
	};
}TEMPLATE(CQueue, CQueue_Params, Class_T);

extern union CQueue_Class_T _private CQueue_Class_T;

void TEMPLATE(Populate, CQueue, CQueue_Params)(union CQueue_T * const queue, T1 * const buff,
		size_t const buff_size);


#ifdef __cplusplus
}
#endif

#undef CQueue_T 
#undef CQueue_Class_T 
#undef T1 
#endif /*CQUEUE_H_*/
