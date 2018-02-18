#ifndef CALGORITHM_H_
#define CALGORITHM_H_

#include "ctemplate.h"

#ifndef CAlgo_Params
#error "CAlgo Params is not defined"
#endif

#define CAlgo_T TEMPLATE(CAlgo, CAlgo_Params)
#define CAlgo_Class_T TEMPLATE(CAlgo, CAlgo_Params, Class)
#define T1 T_Param(1, CAlgo_Params)
#define CAlgo_Method(method) TEMPLATE(CAlgo, CAlgo_Params, method)

#ifdef __cplusplus
extern "C" {
#endif

typedef int (* CAlgo_Cmp_T)(void const *, void const *);

extern T1 * CAlgo_Method(find_first)(T1 * const begin, T1 * const end, T1 const v, CAlgo_Cmp_T compare);

extern T1 * CAlgo_Method(maximum)(T1 * const begin, T1 * const end, T1 const v, CAlgo_Cmp_T compare);

extern T1 * CAlgo_Method(minimum)(T1 * const begin, T1 * const end, T1 const v, CAlgo_Cmp_T compare);

#ifdef __cplusplus
}
#endif
#endif /*CALGORITHM_H_*/
