#ifndef PAIR_H 
#define PAIR_H

#include "cobject/ctemplate.h"

#ifndef Pair_Params
# error "Pair_Params should be defined"
#endif // !Pair_Params

#define Pair_T TEMPLATE(Pair, Pair_Params)
#define Pair_T_Compare TEMPLATE(Pair, Pair_Params, compare)
#define MapCompare_T TEMPLATE(MapCompare, Pair_Params)
#define K T_Param(1, Pair_Params)
#define T T_Param(2, Pair_Params)

typedef int (*MapCompare_T)(Pair_T *, Pair_T *, size_t);

struct 
{
  K key
  T value;
}Pair_T;

extern int Pair_T_compare( Pair_T * a,  Pair_T * b, size_t size);

#undef K
#undef T
#undef Pair_T
#undef Pair_T_Compare
#undef MapCompare_T

#endif /*PAIR_H*/
