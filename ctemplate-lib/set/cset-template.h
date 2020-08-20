#if !defined(CSET_TEMPLATE_H) || defined(CSet_Params)
#ifndef CSet_Params
#error "CSet_Params is not defined"
#endif

#include "cobject/ctemplate.h"

#define CSet_T TEMPLATE(CSet, CSet_Params)
#define CSet_T_Class TEMPLATE(CSet, CSet_Params, Class)
#define Get_CSet_T_Class TEMPLATE(Get, CSet, CSet_Params, Class)
#define CSet_T_size TEMPLATE(CSet, CSet_Params, size)
#define CSet_T_clear TEMPLATE(CSet, CSet_Params, clear)
#define CSet_T_begin TEMPLATE(CSet, CSet_Params, begin)
#define CSet_T_end TEMPLATE(CSet, CSet_Params, end)
#define CSet_T_find TEMPLATE(CSet, CSet_Params, find)
#define CSet_T_insert TEMPLATE(CSet, CSet_Params, insert)
#define CSet_T_erase TEMPLATE(CSet, CSet_Params, erase)
#define CSet_T_populate TEMPLATE(CSet, CSet_Params, populate)

#define T T_Param(1, CSet_Params)

#include "cset.h"

#undef CSet_T
#undef CSet_T_Class
#undef Get_CSet_T_Class
#undef CSet_T_size
#undef CSet_T_clear
#undef CSet_T_begin
#undef CSet_T_end
#undef CSet_T_find
#undef CSet_T_insert
#undef CSet_T_erase
#undef CSet_T_populate

#undef T

#endif /* CSET_TEMPLATE_H */