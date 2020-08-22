#include <string.h>

#define Pair_T TEMPLATE(Pair, Pair_Params)
#define Pair_T_compare TEMPLATE(Pair, Pair_Params, compare)

int Pair_T_compare(Pair_T * a, Pair_T * b, size_t size)
{
  return memcmp(&a->key, &b->key, sizeof(a->key)); 
}

#undef Pair_T
#undef Pair_T_compare
