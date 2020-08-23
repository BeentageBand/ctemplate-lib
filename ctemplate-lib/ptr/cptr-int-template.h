#ifndef CPtr_Params
#error "CPtr_Params is not defined"
#endif

#define CPtr_T TEMPLATE(CPtr, CPtr_Params)
#define CPtr_T_Class TEMPLATE(CPtr, CPtr_Params, Class)
#define Get_CPtr_T_Class TEMPLATE(Get, CPtr, CPtr_Params, Class)
#define CPtr_T_empty TEMPLATE(CPtr, CPtr_Params, empty)
#define CPtr_T_count TEMPLATE(CPtr, CPtr_Params, count)
#define CPtr_T_set TEMPLATE(CPtr, CPtr_Params, set)
#define CPtr_T_get TEMPLATE(CPtr, CPtr_Params, get)
#define CPtr_T_share TEMPLATE(CPtr, CPtr_Params, share)
#define cptr_t_empty TEMPLATE(cptr, CPtr_Params, empty)
#define cptr_t_count TEMPLATE(cptr, CPtr_Params, count)
#define cptr_t_set TEMPLATE(cptr, CPtr_Params, set)
#define cptr_t_get TEMPLATE(cptr, CPtr_Params, get)
#define cptr_t_share TEMPLATE(cptr, CPtr_Params, share)
#define cptr_t_delete TEMPLATE(cptr, CPtr_Params, delete)
#define CPtr_T_populate TEMPLATE(CPtr, CPtr_Params, populate)

#define P T_Param(1, CPtr_Params)

#include "cptr.c"

#undef CPtr_T
#undef CPtr_T_Class
#undef Get_CPtr_T_Class
#undef CPtr_T_empty
#undef CPtr_T_count
#undef CPtr_T_set
#undef CPtr_T_get
#undef CPtr_T_share
#undef cptr_t_empty
#undef cptr_t_count
#undef cptr_t_set
#undef cptr_t_get
#undef cptr_t_share
#undef cptr_t_delete
#undef CPtr_T_populate

#undef P
