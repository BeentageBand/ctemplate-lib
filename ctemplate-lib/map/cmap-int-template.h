#ifndef CMap_Params
#error "CMap_Params is not defined"
#endif

#define CMap_T TEMPLATE(CMap, CMap_Params)
#define CMap_T_Class TEMPLATE(CMap, CMap_Params, Class)
#define Get_CMap_T_Class TEMPLATE(Get, CMap, CMap_Params, Class)
#define CMap_T_size TEMPLATE(CMap, CMap_Params, size)
#define CMap_T_clear TEMPLATE(CMap, CMap_Params, clear)
#define CMap_T_begin TEMPLATE(CMap, CMap_Params, begin)
#define CMap_T_end TEMPLATE(CMap, CMap_Params, end)
#define CMap_T_find TEMPLATE(CMap, CMap_Params, find)
#define CMap_T_insert TEMPLATE(CMap, CMap_Params, insert)
#define CMap_T_erase TEMPLATE(CMap, CMap_Params, erase)
#define cmap_t_size TEMPLATE(cmap, CMap_Params, size)
#define cmap_t_clear TEMPLATE(cmap, CMap_Params, clear)
#define cmap_t_begin TEMPLATE(cmap, CMap_Params, begin)
#define cmap_t_end TEMPLATE(cmap, CMap_Params, end)
#define cmap_t_find TEMPLATE(cmap, CMap_Params, find)
#define cmap_t_insert TEMPLATE(cmap, CMap_Params, insert)
#define cmap_t_erase TEMPLATE(cmap, CMap_Params, erase)
#define cmap_t_override TEMPLATE(cmap, CMap_Params, override)
#define CMap_T_populate TEMPLATE(CMap, CMap_Params, populate)

#define Key_T T_Param(1, CMap_Params)
#define Value_T T_Param(2, CMap_Params)

#include "cmap.c"

#undef CMap_T
#undef CMap_T_Class
#undef Get_CMap_T_Class
#undef CMap_T_size
#undef CMap_T_clear
#undef CMap_T_begin
#undef CMap_T_end
#undef CMap_T_find
#undef CMap_T_insert
#undef CMap_T_erase
#undef cmap_t_size
#undef cmap_t_clear
#undef cmap_t_begin
#undef cmap_t_end
#undef cmap_t_find
#undef cmap_t_insert
#undef cmap_t_erase
#undef cmap_t_override
#undef CMap_T_populate

#undef Key_T
#undef Value_T
