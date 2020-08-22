#include <string.h>

#define HashPair_T TEMPLATE(HashPair, HashPair_Params)
#define HashPair_T_compare TEMPLATE(HashPair, HashPair_Params, compare)
#define HashPair_T_hash TEMPLATE(HashPair, HashPair_Params, hash)

int HashPair_T_compare(HashPair_T * a, HashPair_T * b, size_t size)
{
  return memcmp(&a->key, &b->key, sizeof(a->key)); 
}

size_t HashPair_T_hash(HashPair_T * const pair, size_t const capacity, size_t const seed)
{
  size_t hash = 0;
  size_t min_size = (sizeof(pair->key) > sizeof(hash)) ? sizeof(hash) : sizeof(pair->key);
  memcpy(&hash, &pair->key, min_size);
  return (hash + seed) % capacity;
}

#undef HashPair_T
#undef HashPair_T_compare
#undef HashPair_T_hash
