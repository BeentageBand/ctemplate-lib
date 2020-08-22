#include "cobject/ctemplate.h"

#ifndef HashPair_Params
# error "HashPair_Params should be defined"
#endif // !HashPair_Params

#define HashPair_T TEMPLATE(HashPair, HashPair_Params)
#define HashPair_T_compare TEMPLATE(HashPair, HashPair_Params, compare)
#define HashPairComparator_T TEMPLATE(HashPairComparator, HashPair_Params)
#define HashPair_T_hash TEMPLATE(HashPair, HashPair_Params, hash)
#define HashPairHash_T TEMPLATE(HashPairHash, HashPair_Params)
#define K T_Param(1, HashPair_Params)
#define V T_Param(2, HashPair_Params)

typedef struct 
 {
  K key;
  V value;
}HashPair_T;

typedef int (*HashPairComparator_T)(HashPair_T *, HashPair_T *, size_t);
typedef int (*HashPairHash_T)(HashPair_T *, size_t const, size_t const);

extern int HashPair_T_compare(HashPair_T * a, HashPair_T * b, size_t size);
extern size_t HashPair_T_hash(HashPair_T * const pair, size_t const capacity, size_t const seed);

#undef K
#undef V
#undef HashPair_T
#undef HashPairComparator_T
#undef HashPair_T_compare
#undef HashPair_T_hash
