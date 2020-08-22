#include <string.h>

#define Pair_T TEMPLATE(Pair, Pair_Params)
#define Pair_T_Compare TEMPLATE(Pair, Pair_Params, compare)
#define MapCompare_T TEMPLATE(MapCompare, Pair_Params)

int Pair_T_compare(struct Pair_T * a, struct Pair_T * b, size_t size)
{
  return memcmp(&a->key, &b->key, sizeof(a->key)); 
}

#undef Pair_T
#undef Pair_T_Compare
#undef MapCompare_T
