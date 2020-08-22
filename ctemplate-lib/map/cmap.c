#include "cmap-internal.h"

#define Pair_Params CMap_Params
#include "pair.c"

#define Pair_T TEMPLATE(Pair, Pair_Params)
#define Pair_T_Compare TEMPLATE(Pair, Pair_Params, compare)
#define MapCompare_T TEMPLATE(MapCompare, Pair_Params)


#define CSet_Params Pair_T
#include "ctemplate-lib/set/cset-template.h"

#define CSet_T TEMPLATE(CSet, CSet_Params)
#define Compare_T TEMPLATE(TreeNode, CSet_Params)
#define CSet_T_size TEMPLATE(CSet, CSet_Params, size)
#define CSet_T_clear TEMPLATE(CSet, CSet_Params, clear)
#define CSet_T_begin TEMPLATE(CSet, CSet_Params, begin)
#define CSet_T_end TEMPLATE(CSet, CSet_Params, end)
#define CSet_T_find TEMPLATE(CSet, CSet_Params, find)
#define CSet_T_insert TEMPLATE(CSet, CSet_Params, insert)
#define CSet_T_erase TEMPLATE(CSet, CSet_Params, erase)
#define CSet_T_populate TEMPLATE(CSet, CSet_Params, populate)

size_t cmap_t_size(union CMap_T * const cmap_t);
void cmap_t_clear(union CMap_T * const cmap_t);
struct Pair_T * cmap_t_begin(union CMap_T * const cmap_t);
struct Pair_T * cmap_t_end(union CMap_T * const cmap_t);
struct Pair_T * cmap_t_find(union CMap_T * const cmap_t, K const index);
void cmap_t_insert(union CMap_T * const cmap_t, K const key, T const value);
void cmap_t_erase(union CMap_T * const cmap_t, K const key);

void cmap_t_override(union CMap_T_Class * const clazz)
{
  clazz->size = cmap_t_size;
  clazz->clear = cmap_t_clear;
  clazz->begin = cmap_t_begin;
  clazz->end = cmap_t_end;
  clazz->find = cmap_t_find;
  clazz->insert = cmap_t_insert;
  clazz->erase = cmap_t_erase;
}

size_t cmap_t_size(union CMap_T * const cmap_t)
{
  return CSet_T_size(&cmap_t->set);
}

void cmap_t_clear(union CMap_T * const cmap_t)
{
  return CSet_T_clear(&cmap_t->set);
}

struct Pair_T * cmap_t_begin(union CMap_T * const cmap_t)
{
  return CSet_T_begin(&cmap_t->set);
}

struct Pair_T * cmap_t_end(union CMap_T * const cmap_t)
{
  return CSet_T_end(&cmap_t->set);
}

struct Pair_T * cmap_t_find(union CMap_T * const cmap_t, K const index)
{
  struct Pair_T pair = {index, {0}};
  return CSet_T_find(&cmap_t->set, pair);
}

void cmap_t_insert(union CMap_T * const cmap_t, K const key, T const value)
{
  struct Pair_T pair = {key, value};
  CSet_T_insert(&cmap_t->set, pair);
}
void cmap_t_erase(union CMap_T * const cmap_t, K const key)
{
  struct Pair_T pair = {key, {0}};
  CSet_T_erase(&cmap_t->set, pair);
}

void CMap_T_populate(union CMap_T * const cmap_t, MapCompare_T const cmp)
{
  Object_populate(&cmap_t->Object, &Get_CMap_T_Class()->Class);
  cmap_t->cmp = (NULL == cmp) ? (MapCompare_T) Pair_T_compare : cmp;
  CSet_T_populate(&cmap_t->set, NULL, 0, (Compare_T) cmap_t->cmp);
}

#undef Pair_T
#undef Pair_T_Compare
#undef MapCompare_T 
#undef Pair_Params
#undef CSet_T
#undef Compare_T
#undef CSet_T_size
#undef CSet_T_clear
#undef CSet_T_begin
#undef CSet_T_end
#undef CSet_T_find
#undef CSet_T_insert
#undef CSet_T_erase
#undef CSet_T_populate
#undef CSet_Params
