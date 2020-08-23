#include <stdbool.h>
#include <string.h>

#ifndef Bucket_Params 
# error "Bucket_Params should be defined"
#endif // !Bucket_Params
#define Bucket_T TEMPLATE(Bucket, Bucket_Params)
#define Hash_T TEMPLATE(Hash, Bucket_Params)
#define HashComparator_T TEMPLATE(HashComparator, Bucket_Params)
#define Bucket_T_access TEMPLATE(Bucket, Bucket_Params, access)
#define Bucket_T_available TEMPLATE(Bucket, Bucket_Params, available)
#define Bucket_T_is_empty TEMPLATE(Bucket, Bucket_Params, is_empty)
#define Bucket_T_clear TEMPLATE(Bucket, Bucket_Params, clear)
#define Bucket_T_hash TEMPLATE(Bucket, Bucket_Params, hash)

size_t Bucket_T_access(struct Bucket_T * buckets, size_t const size, Hash_T const hash, 
    HashComparator_T const cmp, T value)
{
  size_t hash_i = 0;
  for (size_t i = 0; i < size; ++i)
  {
    size_t hash_i = hash(&value, size, i);
    bool empty = Bucket_T_is_empty(buckets + hash_i);
    int equals = cmp(&buckets[hash_i].value, &value, sizeof(value));

    if (empty)
    {
      if (!buckets[hash_i].collision) return size;
    }
    else if (0 == equals)
    {
      return hash_i;
    }
  }

  return size;// if no space was available;
}

size_t Bucket_T_available(struct Bucket_T * buckets, size_t const size, Hash_T const hash, 
    HashComparator_T const cmp, T value)
{
 
  size_t i = 0;
  size_t hash_i = 0;
  size_t first_empty_i = size;
  for (; i < size; ++i)
  {
    hash_i = hash(&value, size, i);
    bool empty = Bucket_T_is_empty(buckets + hash_i);
    int equals = cmp(&buckets[hash_i].value, &value, sizeof(value));
    
    if (empty)
    {
      if (!buckets[hash_i].collision) return hash_i;
      else if (size == first_empty_i) first_empty_i = hash_i;
    }
    else if (0 == equals)
    {
      return size;
    }

    buckets[hash_i].collision = true;
  }
  return (i < size) ? first_empty_i : size;
}

void Bucket_T_clear(struct Bucket_T * bucket_t)
{
  memset(&bucket_t->value, 0xFFU, sizeof(bucket_t->value));
}

bool Bucket_T_is_empty(struct Bucket_T * bucket_t)
{
  struct Bucket_T empty;
  Bucket_T_clear(&empty);
  return 0 == memcmp(&bucket_t->value, &empty.value, sizeof(empty.value));
}

size_t Bucket_T_hash(T * const value, size_t const capacity, size_t const seed)
{
  size_t hash = 0;
  size_t min_size = (sizeof(*value) > sizeof(hash)) ? sizeof(hash) : sizeof(*value);
  memcpy(&hash, value, min_size);
  return (hash + seed) % capacity;
}

#undef Bucket_T
#undef Hash_T
#undef HashComparator_T
#undef Bucket_T_access
#undef Bucket_T_available
#undef Bucket_T_is_empty
#undef Bucket_T_clear
#undef Bucket_T_hash 
