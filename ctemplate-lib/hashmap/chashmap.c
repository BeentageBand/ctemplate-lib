#include "chashmap-internal.h"

size_t chashmap_t_size(union CHashMap_T * const chashmap_t);
void chashmap_t_clear(union CHashMap_T * const chashmap_t);
HashPair_T * chashmap_t_begin(union CHashMap_T * const chashmap_t);
HashPair_T * chashmap_t_end(union CHashMap_T * const chashmap_t);
HashPair_T * chashmap_t_find(union CHashMap_T * const chashmap_t, HashKey_T const index);
void chashmap_t_insert(union CHashMap_T * const chashmap_t, HashKey_T const key, HashValue_T const value);
void chashmap_t_erase(union CHashMap_T * const chashmap_t, HashKey_T const key);

void chashmap_t_override(union CHashMap_T_Class * const clazz)
{
  clazz->size = chashmap_t_size;
  clazz->clear = chashmap_t_clear;
  clazz->begin = chashmap_t_begin;
  clazz->end = chashmap_t_end;
  clazz->find = chashmap_t_find;
  clazz->insert = chashmap_t_insert;
  clazz->erase = chashmap_t_erase;
}

size_t chashmap_t_size(union CHashMap_T * const chashmap_t)
{
  return CHashSet_T_size(&chashmap_t->set);
}

void chashmap_t_clear(union CHashMap_T * const chashmap_t)
{
  return CHashSet_T_clear(&chashmap_t->set);
}

HashPair_T * chashmap_t_begin(union CHashMap_T * const chashmap_t)
{
  return CHashSet_T_begin(&chashmap_t->set);
}

HashPair_T * chashmap_t_end(union CHashMap_T * const chashmap_t)
{
  return CHashSet_T_end(&chashmap_t->set);
}

HashPair_T * chashmap_t_find(union CHashMap_T * const chashmap_t, HashKey_T const index)
{
  HashPair_T pair = {0}; 
  pair.key = index;
  return CHashSet_T_find(&chashmap_t->set, pair);
}

void chashmap_t_insert(union CHashMap_T * const chashmap_t, HashKey_T const key, HashValue_T const value)
{
  HashPair_T pair = {0};
  pair.key = key;
  pair.value = value;
  CHashSet_T_insert(&chashmap_t->set, pair);
}
void chashmap_t_erase(union CHashMap_T * const chashmap_t, HashKey_T const key)
{
  HashPair_T pair = {0};
  pair.key = key;
  CHashSet_T_erase(&chashmap_t->set, pair);
}

void CHashMap_T_populate(union CHashMap_T * const chashmap_t, HashPairHash_T const hash, HashPairComparator_T const cmp)
{
  Object_populate(&chashmap_t->Object, &Get_CHashMap_T_Class()->Class);
  chashmap_t->cmp = (NULL == cmp) ? (HashPairComparator_T) HashPair_T_compare : cmp;
  chashmap_t->hash = (NULL == hash) ? (HashPairHash_T) HashPair_T_hash : cmp;
  CHashSet_T_populate(&chashmap_t->set, NULL, 0, 0, (Hash_T) chashmap_t->hash, (HashComparator_T) chashmap_t->cmp);
}

