#if !defined(CPRIORITYQUEUE_TEMPLATE_H) || defined(CPriorityQueue_Params)
#ifndef CPriorityQueue_Params
#error "CPriorityQueue_Params is not defined"
#endif

#include "cobject/ctemplate.h"

#define CPriorityQueue_T TEMPLATE(CPriorityQueue, CPriorityQueue_Params)
#define CPriorityQueue_T_Class TEMPLATE(CPriorityQueue, CPriorityQueue_Params, Class)
#define Get_CPriorityQueue_T_Class TEMPLATE(Get, CPriorityQueue, CPriorityQueue_Params, Class)
#define CPriorityQueue_T_clear TEMPLATE(CPriorityQueue, CPriorityQueue_Params, clear)
#define CPriorityQueue_T_size TEMPLATE(CPriorityQueue, CPriorityQueue_Params, size)
#define CPriorityQueue_T_reserve TEMPLATE(CPriorityQueue, CPriorityQueue_Params, reserve)
#define CPriorityQueue_T_poll TEMPLATE(CPriorityQueue, CPriorityQueue_Params, poll)
#define CPriorityQueue_T_peek TEMPLATE(CPriorityQueue, CPriorityQueue_Params, peek)
#define CPriorityQueue_T_push TEMPLATE(CPriorityQueue, CPriorityQueue_Params, push)
#define CPriorityQueue_T_populate TEMPLATE(CPriorityQueue, CPriorityQueue_Params, populate)

#define Q T_Param(1, CPriorityQueue_Params)

#define CVector_Params CPriorityQueue_Params
#include "ctemplate-lib/vector/cvector-template.h"

#define CVector_T TEMPLATE(CVector, CVector_Params)
#define CVector_T_Class TEMPLATE(CVector, CVector_Params, Class)
#define Get_CVector_T_Class TEMPLATE(Get, CVector, CVector_Params, Class)
#define CVector_T_size TEMPLATE(CVector, CVector_Params, size)
#define CVector_T_clear TEMPLATE(CVector, CVector_Params, clear)
#define CVector_T_reserve TEMPLATE(CVector, CVector_Params, reserve)
#define CVector_T_begin TEMPLATE(CVector, CVector_Params, begin)
#define CVector_T_end TEMPLATE(CVector, CVector_Params, end)
#define CVector_T_at TEMPLATE(CVector, CVector_Params, at)
#define CVector_T_access TEMPLATE(CVector, CVector_Params, access)
#define CVector_T_back TEMPLATE(CVector, CVector_Params, back)
#define CVector_T_push_back TEMPLATE(CVector, CVector_Params, push_back)
#define CVector_T_pop_back TEMPLATE(CVector, CVector_Params, pop_back)
#define CVector_T_populate TEMPLATE(CVector, CVector_Params, populate)

#include "priorityqueue-types.h"

#define PriorityComparator_T TEMPLATE(PriorityComparator, CPriorityQueue_Params)

#define CPriorityQueue_T_populate_reserved         TEMPLATE(CPriorityQueue, CPriorityQueue_Params, populate, reserved)
#include "cpriorityqueue.h"

#undef PriorityComparator_T

#undef CVector_T
#undef CVector_T_Class
#undef Get_CVector_T_Class
#undef CVector_T_size
#undef CVector_T_clear
#undef CVector_T_reserve
#undef CVector_T_begin
#undef CVector_T_end
#undef CVector_T_at
#undef CVector_T_access
#undef CVector_T_back
#undef CVector_T_push_back
#undef CVector_T_pop_back
#undef CVector_T_populate

#undef CPriorityQueue_T
#undef CPriorityQueue_T_Class
#undef Get_CPriorityQueue_T_Class
#undef CPriorityQueue_T_clear
#undef CPriorityQueue_T_size
#undef CPriorityQueue_T_reserve
#undef CPriorityQueue_T_poll
#undef CPriorityQueue_T_peek
#undef CPriorityQueue_T_push
#undef CPriorityQueue_T_populate

#undef Q

#undef CPriorityQueue_T_populate_reserved
#endif /* CPRIORITYQUEUE_TEMPLATE_H */