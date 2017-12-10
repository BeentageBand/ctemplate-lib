#if !defined(CSET_H_) || defined(CSet_Params)
#define CSET_H_
 
#include "ctemplate.h"

#ifdef CSet_Params
#error "CSet_Params not defined"
#endif

#define CSet_T TEMPLATE(CSet, CSet_Params)
#define CSet_Class_T TEMPLATE(CSet, CSet_Params, Class)
#define T1 CAT(T_Params(1, CSet_Params), _T)

#ifdef __cplusplus
extern "C" {
#endif

typedef union CSet_T
{
	union CSet_Class_T _private * _private vtbl;
	struct
	{
		struct Object Object;
		uint32_t _private size;
		uint32_t _private capacity;
		t1 _private * buffer;
		int (* _private compare)(void * void *);
	};
}TEMPLATE(CSet, CSet_Params, _T);

typedef union CSet_Class_T
{
	struct
	{
		struct Class Class;
		void (* _private clear)(union cset_t * const);
		t1 * (* _private begin)(union cset_t * const);
		t1 * (* _private end)(union cset_t * const);
		t1 * (* _private at)(union cset_t * const, uint32_t const);
		t1 (* _private access)(union cset_t * const, uint32_t const);
		void (* _private insert)(union cset_t * const, t1 const);
		t1 * (* _private find)(union cset_t * const, t1 const * const);
		t1 * (* _private erase)(union cset_t * const, t1 const * const);
	};
}TEMPLATE(CSet, CSet_Params, Class_T);

extern CSet_Class_T _private CSet_Class_T;

extern Method_Name(Populate, CSet, CSet_Params)(union CSet_T * const this, T1 * const buff,
		size_t const buff_size);
 
#ifdef __cplusplus
}
#endif
#endif /*CSET_H_*/
