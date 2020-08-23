
#include "cobject/ctemplate.h"

#ifndef Pair_Params
# error "Pair_Params should be defined"
#endif // !Pair_Params

#define Pair_T TEMPLATE(Pair, Pair_Params)
#define Pair_T_compare TEMPLATE(Pair, Pair_Params, compare)
#define PairComparator_T TEMPLATE(PairComparator, Pair_Params)
#define Pair_T_hash TEMPLATE(Pair, Pair_Params, hash)
#define PairHash_T TEMPLATE(PairHash, Pair_Params)
#define K T_Param(1, Pair_Params)
#define V T_Param(2, Pair_Params)

typedef struct 
{
  K key;
  V value;
}Pair_T;

typedef int (*PairComparator_T)(Pair_T const * const, Pair_T const * const, size_t);

extern int Pair_T_compare(Pair_T * a, Pair_T * b, size_t size);

#undef K
#undef V
#undef Pair_T
#undef PairComparator_T
#undef Pair_T_compare
