#include "cobject/ctemplate.h"
#ifndef CSet_Params
#error "CSet_Params is not defined"
#endif

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
#define cset_t_size TEMPLATE(cset, CSet_Params, size)
#define cset_t_clear TEMPLATE(cset, CSet_Params, clear)
#define cset_t_begin TEMPLATE(cset, CSet_Params, begin)
#define cset_t_end TEMPLATE(cset, CSet_Params, end)
#define cset_t_find TEMPLATE(cset, CSet_Params, find)
#define cset_t_insert TEMPLATE(cset, CSet_Params, insert)
#define cset_t_erase TEMPLATE(cset, CSet_Params, erase)
#define cset_t_override TEMPLATE(cset, CSet_Params, override)
#define CSet_T_populate TEMPLATE(CSet, CSet_Params, populate)

#define T T_Param(1, CSet_Params)

#include "cset.c"

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
#undef cset_t_size
#undef cset_t_clear
#undef cset_t_begin
#undef cset_t_end
#undef cset_t_find
#undef cset_t_insert
#undef cset_t_erase
#undef cset_t_override 
#undef CSet_T_populate

#undef T
