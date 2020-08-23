#if !defined(CPTR_TEMPLATE_H) || defined(CPtr_Params)
#ifndef CPtr_Params
#error "CPtr_Params is not defined"
#endif

#include "cobject/ctemplate.h"

#define CPtr_T TEMPLATE(CPtr, CPtr_Params)
#define CPtr_T_Class TEMPLATE(CPtr, CPtr_Params, Class)
#define Get_CPtr_T_Class TEMPLATE(Get, CPtr, CPtr_Params, Class)
#define CPtr_T_empty TEMPLATE(CPtr, CPtr_Params, empty)
#define CPtr_T_count TEMPLATE(CPtr, CPtr_Params, count)
#define CPtr_T_set TEMPLATE(CPtr, CPtr_Params, set)
#define CPtr_T_get TEMPLATE(CPtr, CPtr_Params, get)
#define CPtr_T_share TEMPLATE(CPtr, CPtr_Params, share)
#define CPtr_T_populate TEMPLATE(CPtr, CPtr_Params, populate)

#define P T_Param(1, CPtr_Params)

#include "cptr.h"

#undef CPtr_T
#undef CPtr_T_Class
#undef Get_CPtr_T_Class
#undef CPtr_T_empty
#undef CPtr_T_count
#undef CPtr_T_set
#undef CPtr_T_get
#undef CPtr_T_share
#undef CPtr_T_populate

#undef P

#endif /* CPTR_TEMPLATE_H */