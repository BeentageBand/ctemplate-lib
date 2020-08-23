#include "chashset-internal.h"

static void chashset_t_delete(union CHashSet_T * const chashset_t);
static size_t chashset_t_size(union CHashSet_T * const chashset_t);
static void chashset_t_clear(union CHashSet_T * const chashset_t);
static T * chashset_t_begin(union CHashSet_T * const chashset_t);
static T * chashset_t_end(union CHashSet_T * const chashset_t);
static T * chashset_t_find(union CHashSet_T * const chashset_t, T const index);
static void chashset_t_insert(union CHashSet_T * const chashset_t, T const value);
static void chashset_t_erase(union CHashSet_T * const chashset_t, T const value);

void chashset_t_delete(union CHashSet_T * const chashset_t)
{
  CHashSet_T_clear(chashset_t);
  chashset_t->buckets = NULL;
  chashset_t->size = 0;
  chashset_t->hash = NULL;
  chashset_t->cmp = NULL;
}

void chashset_t_override(union CHashSet_T_Class * const clazz)
{
  clazz->Class.destroy = (Class_Delete_T) chashset_t_delete;
  clazz->size = chashset_t_size;
  clazz->clear = chashset_t_clear;
  clazz->begin = chashset_t_begin;
  clazz->end = chashset_t_end;
  clazz->find = chashset_t_find;
  clazz->insert = chashset_t_insert;
  clazz->erase = chashset_t_erase;
}

size_t chashset_t_size(union CHashSet_T * const chashset_t)
{
  return chashset_t->count;
}

void chashset_t_clear(union CHashSet_T * const chashset_t)
{
  T * begin = CHashSet_T_begin(chashset_t);
  while (NULL != begin)
  {
    CHashSet_T_erase(chashset_t, *begin);
    begin = CHashSet_T_begin(chashset_t);
  }
}

T * chashset_t_begin(union CHashSet_T * const chashset_t)
{
  struct Bucket_T * begin = chashset_t->buckets;
  for (size_t i = 0; i < chashset_t->size; ++i)
  {
    if (!Bucket_T_is_empty(chashset_t->buckets + i))
    {
      return &begin->value;
    }
  }
  return NULL;
};

T * chashset_t_end(union CHashSet_T * const chashset_t)
{
  return NULL;
}

T * chashset_t_find(union CHashSet_T * const chashset_t, T const value)
{
  size_t hash_i = Bucket_T_access(chashset_t->buckets, chashset_t->size, chashset_t->hash, chashset_t->cmp, value);

  return (hash_i == chashset_t->size) ? NULL : &chashset_t->buckets[hash_i].value ;
}

void chashset_t_insert(union CHashSet_T * const chashset_t, T const value)
{
  size_t hash_i = Bucket_T_available(chashset_t->buckets, chashset_t->size, chashset_t->hash, 
      chashset_t->cmp, value);
  if (hash_i != chashset_t->size)
  {
    chashset_t->count++;
    chashset_t->buckets[hash_i].value = value;
  }
}

void chashset_t_erase(union CHashSet_T * const chashset_t, T const value)
{
  size_t hash_i = Bucket_T_access(chashset_t->buckets, chashset_t->size, chashset_t->hash, 
      chashset_t->cmp, value);
  if (hash_i != chashset_t->size)
  {
    Bucket_T_clear(chashset_t->buckets + hash_i);
    chashset_t->count--;
  }
}

void CHashSet_T_populate(union CHashSet_T * const chashset_t, struct Bucket_T* const buckets, size_t const size,
    size_t const count, Hash_T const hash, HashComparator_T const cmp)
{
  Object_populate(&chashset_t->Object, &Get_CHashSet_T_Class()->Class);
  chashset_t->buckets= buckets;
  chashset_t->size = size;

  for (size_t i = 0; i < size; ++i)
  {
    Bucket_T_clear(chashset_t->buckets + i);
  }

  chashset_t->hash = (NULL == hash) ? (Hash_T) Bucket_T_hash : hash;
  chashset_t->cmp = (NULL == cmp) ? (HashComparator_T) memcmp : cmp;
}
