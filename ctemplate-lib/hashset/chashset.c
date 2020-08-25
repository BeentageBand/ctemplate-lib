#include "chashset-internal.h"

#define chashset_t_next_prime TEMPLATE(chashset, CHashSet_Params, next_prime)
#define chashset_t_is_prime TEMPLATE(chashset, CHashSet_Params, is_prime)

static void chashset_t_delete(union CHashSet_T * const chashset_t);
static size_t chashset_t_size(union CHashSet_T * const chashset_t);
static void chashset_t_clear(union CHashSet_T * const chashset_t);
static T * chashset_t_begin(union CHashSet_T * const chashset_t);
static T * chashset_t_end(union CHashSet_T * const chashset_t);
static T * chashset_t_find(union CHashSet_T * const chashset_t, T const index);
static void chashset_t_insert(union CHashSet_T * const chashset_t, T const value);
static void chashset_t_erase(union CHashSet_T * const chashset_t, T const value);
static void chashset_t_reserve(union CHashSet_T * const chashset_t, size_t const capacity);
static size_t chashset_t_next_prime(size_t prime);
static bool chashset_t_is_prime(size_t const prime);

size_t chashset_t_next_prime(size_t prime)
{
  if (prime <= 5) return 7;

  while(true)
  {
    ++prime;
    if (chashset_t_is_prime(prime))
      return prime;
  }
}

bool chashset_t_is_prime(size_t const prime)
{
  if (!(prime & 1) || 0 == prime % 3) return false;
  for (size_t i = 5; i*i<=prime; i=i+6)  
        if (prime % i == 0 || prime % (i + 2) == 0)  
           return false;  
    
    return true;  
}


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
  clazz->reserve = chashset_t_reserve;
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
  if (0 == chashset_t->count) return;

  chashset_t->count = 0;
  for (size_t i = 0; i < chashset_t->size; ++i)
  {
    if (!Bucket_T_is_empty(chashset_t->buckets + i))
    {
      Bucket_T_clear(chashset_t->buckets + i);
      chashset_t->buckets[i].collision = false;
    }
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
  if (chashset_t->count >= chashset_t->size)
  {
    CHashSet_T_reserve(chashset_t, chashset_t_next_prime(chashset_t->size));
  }

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

void chashset_t_reserve(union CHashSet_T * const chashset_t, size_t const capacity)
{
  if (capacity <= chashset_t->size) return;

  struct Bucket_T * old_buckets = chashset_t->buckets;
  size_t old_capacity = chashset_t->size;

  chashset_t->size = capacity;
  chashset_t->count = 0;
  chashset_t->buckets = (struct Bucket_T *) malloc(sizeof(struct Bucket_T) * chashset_t->size);

  for (size_t i = 0; i < chashset_t->size; ++i)
  {
    Bucket_T_clear(chashset_t->buckets + i);
    chashset_t->buckets[i].collision = false;
  }

  for (size_t i = 0; i < old_capacity; ++i)
  {
    if (!Bucket_T_is_empty(old_buckets + i))
    {
      CHashSet_T_insert(chashset_t, old_buckets[i].value);
    }
  }

  if (old_buckets) free(old_buckets);
}

void CHashSet_T_populate(union CHashSet_T * const chashset_t, Hash_T const hash, HashComparator_T const cmp)
{
  Object_populate(&chashset_t->Object, &Get_CHashSet_T_Class()->Class);
  chashset_t->buckets= NULL;
  chashset_t->size = 0;

  chashset_t->hash = (NULL == hash) ? (Hash_T) Bucket_T_hash : hash;
  chashset_t->cmp = (NULL == cmp) ? (HashComparator_T) memcmp : cmp;

  CHashSet_T_reserve(chashset_t, chashset_t_next_prime(chashset_t->size));
}

void CHashSet_T_populate_reserved(union CHashSet_T * const chashset_t, size_t const elems, Hash_T const hash, HashComparator_T const cmp)
{
  Object_populate(&chashset_t->Object, &Get_CHashSet_T_Class()->Class);
  chashset_t->buckets= NULL;
  chashset_t->size = 0;

  chashset_t->hash = (NULL == hash) ? (Hash_T) Bucket_T_hash : hash;
  chashset_t->cmp = (NULL == cmp) ? (HashComparator_T) memcmp : cmp;

  CHashSet_T_reserve(chashset_t, elems);
}

#undef chashset_t_next_prime
#undef chashset_t_is_prime
