#include "chashset-internal.h"

#define Bucket_Params CHashSet_Params
#include "bucket.c"

#define Bucket_T TEMPLATE(Bucket, Bucket_Params)
#define Hash_T TEMPLATE(Hash, Bucket_Params)
#define HashCompare_T TEMPLATE(HashCompare, Bucket_Params)
#define Bucket_T_access TEMPLATE(Bucket, Bucket_Params, access)
#define Bucket_T_available TEMPLATE(Bucket, Bucket_Params, available)
#define Bucket_T_is_empty TEMPLATE(Bucket, Bucket_Params, is_empty)
#define Bucket_T_hash TEMPLATE(Bucket, Bucket_Params, hash)

static size_t chashset_t_size(union CHashSet_T * const chashset_t);
static void chashset_t_clear(union CHashSet_T * const chashset_t);
static T * chashset_t_begin(union CHashSet_T * const chashset_t);
static T * chashset_t_end(union CHashSet_T * const chashset_t);
static T * chashset_t_find(union CHashSet_T * const chashset_t, T const index);
static void chashset_t_insert(union CHashSet_T * const chashset_t, T const value);
static void chashset_t_erase(union CHashSet_T * const chashset_t, T const value);


void chashset_t_override(union CHashSet_T_Class * const clazz)
{
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
  T * begin;
  while (NULL != (begin = CHashSet_T_begin(chashset_t)))
  {
    CHashSet_T_erase(chashset_t, *begin);
  }
}

T * chashset_t_begin(union CHashSet_T * const chashset_t)
{
  struct Bucket_T * begin = chashset_t->buckets;
  struct Bucket_T empty_bucket;
  memset(&empty_bucket, 0, sizeof(empty_bucket));
  for (size_t i = 0; i < chashset_t->size; ++i)
  {
    if (Bucket_T_is_empty(chashset_t->buckets + i))
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
    memset(&chashset_t->buckets[hash_i].value, 0, sizeof(value));
    chashset_t->count--;
  }
}

void CHashSet_T_populate(union CHashSet_T * const chashset_t, struct Bucket_T* const buckets, size_t const size,
    size_t const count, Hash_T const hash, HashCompare_T const cmp)
{
  Object_populate(&chashset_t->Object, &Get_CHashSet_T_Class()->Class);
  chashset_t->buckets= buckets;
  chashset_t->size = size;
  chashset_t->hash = (NULL == hash) ? (Hash_T) Bucket_T_hash : hash;
  chashset_t->cmp = (NULL == cmp) ? (HashCompare_T) memcmp : cmp;
}
#undef Bucket_T
#undef Hash_T
#undef HashCompare_T
#undef Bucket_T_access
#undef Bucket_T_available
#undef Bucket_T_is_empty
#undef Bucket_T_hash_
#undef Bucket_Params 
