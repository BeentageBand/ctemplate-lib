#if !defined(CQUEUE_TEMPLATE_H) || defined(CQueue_Params)
#ifndef CQueue_Params
#error "CQueue_Params is not defined"
#endif

#include "cobject/ctemplate.h"

#define CQueue_T TEMPLATE(CQueue, CQueue_Params)
#define CQueue_T_Class TEMPLATE(CQueue, CQueue_Params, Class)
#define Get_CQueue_T_Class TEMPLATE(Get, CQueue, CQueue_Params, Class)
#define CQueue_T_size TEMPLATE(CQueue, CQueue_Params, size)
#define CQueue_T_clear TEMPLATE(CQueue, CQueue_Params, clear)
#define CQueue_T_reserve TEMPLATE(CQueue, CQueue_Params, reserve)
#define CQueue_T_begin TEMPLATE(CQueue, CQueue_Params, begin)
#define CQueue_T_end TEMPLATE(CQueue, CQueue_Params, end)
#define CQueue_T_at TEMPLATE(CQueue, CQueue_Params, at)
#define CQueue_T_access TEMPLATE(CQueue, CQueue_Params, access)
#define CQueue_T_back TEMPLATE(CQueue, CQueue_Params, back)
#define CQueue_T_front TEMPLATE(CQueue, CQueue_Params, front)
#define CQueue_T_push_back TEMPLATE(CQueue, CQueue_Params, push_back)
#define CQueue_T_pop_back TEMPLATE(CQueue, CQueue_Params, pop_back)
#define CQueue_T_push_front TEMPLATE(CQueue, CQueue_Params, push_front)
#define CQueue_T_pop_front TEMPLATE(CQueue, CQueue_Params, pop_front)
#define CQueue_T_populate TEMPLATE(CQueue, CQueue_Params, populate)

#define T T_Param(1, CQueue_Params)

#include "cqueue.h"

#undef CQueue_T
#undef CQueue_T_Class
#undef Get_CQueue_T_Class
#undef CQueue_T_size
#undef CQueue_T_clear
#undef CQueue_T_reserve
#undef CQueue_T_begin
#undef CQueue_T_end
#undef CQueue_T_at
#undef CQueue_T_access
#undef CQueue_T_back
#undef CQueue_T_front
#undef CQueue_T_push_back
#undef CQueue_T_pop_back
#undef CQueue_T_push_front
#undef CQueue_T_pop_front
#undef CQueue_T_populate

#undef T

#endif /* CQUEUE_TEMPLATE_H */