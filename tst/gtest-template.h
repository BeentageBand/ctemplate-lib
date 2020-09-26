#ifndef GTEST_TEMPLATE_UTILS_H_
#define GTEST_TEMPLATE_UTILS_H_
 
#ifdef __cplusplus
extern "C" {
#endif
 
#define CQueue_Params int 
#include "ctemplate-lib/queue/cqueue-template.h"
#undef CQueue_Params

#define CSet_Params int 
#include "ctemplate-lib/set/cset-template.h"
#undef CSet_Params

#define CHashSet_Params int 
#include "ctemplate-lib/hashset/chashset-template.h"
#undef CHashSet_Params

#define CMap_Params int, int
#include "ctemplate-lib/map/cmap-template.h"
#undef CMap_Params

#define CHashMap_Params int, int
#include "ctemplate-lib/hashmap/chashmap-template.h"
#undef CHashMap_Params

#define CPriorityQueue_Params int
#include "ctemplate-lib/priorityqueue/cpriorityqueue-template.h"
#undef CPriorityQueue_Params

#define CPtr_Params int
#include "ctemplate-lib/ptr/cptr-template.h"
#undef CPtr_Params


typedef struct {
  int id;
  char const * obj;
}Tuple_T;

typedef Tuple_T * Tuple_Ptr_T;

/*
#define CSet_Params Tuple_Ptr
#include "ctemplate-lib/set/cset-template.h"
#undef CSet_Params
*/

#ifdef __cplusplus
}

#include <iostream>
template<typename Container>
inline void printToCout(Container & container, char const * delimiter = ",") {
    std::copy(container.begin(), container.end(),
        std::ostream_iterator<typename Container::value_type>(std::cout, delimiter));
    std::cout << std::endl;
}
#endif


#endif /*GTEST_TEMPLATE_UTILS_H_*/
