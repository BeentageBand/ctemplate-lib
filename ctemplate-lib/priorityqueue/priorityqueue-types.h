#include <stdbool.h>
#include "cobject/ctemplate.h"

#ifndef CPriorityQueue_Params
#error "CPriorityQueue_Params is not defined"
#endif

#define PriorityComparator_T TEMPLATE(PriorityComparator, CPriorityQueue_Params)

typedef bool (*PriorityComparator_T)(Q * const, Q * const);

#undef PriorityComparator_T
