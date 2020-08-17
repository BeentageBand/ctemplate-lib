#if !defined(CVECTOR_TEMPLATE_H) || defined(CVector_Params)
#ifndef CVector_Params
#error "CVector_Params is not defined"
#endif

#include "cobject/ctemplate.h"

#define CVector_T TEMPLATE(CVector, CVector_Params)
#define CVector_T_Class TEMPLATE(CVector, CVector_Params, Class)
#define Get_CVector_T_Class TEMPLATE(Get, CVector, CVector_Params, Class)
#define CVector_T_size TEMPLATE(CVector, CVector_Params, size)
#define CVector_T_clear TEMPLATE(CVector, CVector_Params, clear)
#define CVector_T_begin TEMPLATE(CVector, CVector_Params, begin)
#define CVector_T_end TEMPLATE(CVector, CVector_Params, end)
#define CVector_T_at TEMPLATE(CVector, CVector_Params, at)
#define CVector_T_access TEMPLATE(CVector, CVector_Params, access)
#define CVector_T_back TEMPLATE(CVector, CVector_Params, back)
#define CVector_T_push_back TEMPLATE(CVector, CVector_Params, push_back)
#define CVector_T_pop_back TEMPLATE(CVector, CVector_Params, pop_back)
#define CVector_T_populate TEMPLATE(CVector, CVector_Params, populate)

#define T T_Param(1, CVector_Params)

#include "cvector.h"

#undef CVector_T
#undef CVector_T_Class
#undef Get_CVector_T_Class
#undef CVector_T_size
#undef CVector_T_clear
#undef CVector_T_begin
#undef CVector_T_end
#undef CVector_T_at
#undef CVector_T_access
#undef CVector_T_back
#undef CVector_T_push_back
#undef CVector_T_pop_back
#undef CVector_T_populate

#undef T

#endif /* CVECTOR_TEMPLATE_H */