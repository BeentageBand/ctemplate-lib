#include <stdbool.h>
#include <string.h>

#ifndef Bucket_Params 
# error "Bucket_Params should be defined"
#endif // !Bucket_Params
#define Bucket_T TEMPLATE(Bucket, Bucket_Params)
#define Hash_T TEMPLATE(Hash, Bucket_Params)
#define HashCompare_T TEMPLATE(HashCompare, Bucket_Params)
#define Bucket_T_access TEMPLATE(Bucket, Bucket_Params, access)
#define Bucket_T_available TEMPLATE(Bucket, Bucket_Params, available)
#define Bucket_T_is_empty TEMPLATE(Bucket, Bucket_Params, is_empty)
#define Bucket_T_hash TEMPLATE(Bucket, Bucket_Params, hash)

size_t Bucket_T_access(struct Bucket_T * buckets, size_t const size, Hash_T const hash, 
    HashCompare_T const cmp, T value)
{
  for (size_t i = 0; i < size; ++i)
  {
    size_t hash_i = hash(value, size, i);
    bool empty = Bucket_T_is_empty(buckets + hash_i);
    if (empty && !buckets[hash_i].collision) return size;
    else if (0 == cmp(&buckets[hash_i].value, &value, sizeof(value))) return hash_i;
  }

  return size;// if no space was available;
}

size_t Bucket_T_available(struct Bucket_T * buckets, size_t const size, Hash_T const hash, 
    HashCompare_T const cmp, T value)
{
  size_t empty_i = size;
  size_t i = 0;
  size_t hash_i = 0;
  while(i < size)
  {
    hash_i = hash(value, size, hash_i);
    bool empty = Bucket_T_is_empty(buckets + hash_i);
    if (empty && !buckets[hash_i].collision) return hash_i;
    else if(empty && size != empty_i) empty_i = hash_i;
    else if(0 == cmp(&buckets[hash_i].value, &value, sizeof(value))) return size;
    buckets[hash_i].collision = true;
    ++i;
  }
  return (i < size) ? empty_i : size;
}

bool Bucket_T_is_empty(struct Bucket_T * bucket_t)
{
  struct Bucket_T empty;
  memset(&empty, 0, sizeof(empty));
  return memcmp(&bucket_t->value, &empty.value, sizeof(empty.value));
}

size_t Bucket_T_hash(T const value, size_t const capacity, size_t seed)
{
  size_t hash = 0;
  size_t min_size = (sizeof(value) > sizeof(hash)) ? sizeof(hash) : sizeof(value);
  memcpy(&hash, &value, min_size);
  return (hash + seed) % capacity;
}

#undef Bucket_T
#undef Hash_T
#undef HashCompare_T
#undef Bucket_T_access
#undef Bucket_T_available
#undef Bucket_T_is_empty
#undef Bucket_T_hash 
