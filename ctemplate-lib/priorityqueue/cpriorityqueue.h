#include "cobject/cobject.h"
#ifdef CPRIORITYQUEUE_T_IMPLEMENTATION 
#define _private
#else
#define _private const
#endif 

#ifdef __cplusplus
extern "C" {
#endif

union CPriorityQueue_T;
union CPriorityQueue_T_Class
{
    struct
    {
        struct Class Class;
        void (* _private clear)(union CPriorityQueue_T * const cpriorityqueue_t);
        size_t (* _private size)(union CPriorityQueue_T * const cpriorityqueue_t);
        void (* _private reserve)(union CPriorityQueue_T * const cpriorityqueue_t, size_t const capacity);
        Q (* _private poll)(union CPriorityQueue_T * const cpriorityqueue_t);
        Q (* _private peek)(union CPriorityQueue_T * const cpriorityqueue_t);
        void (* _private push)(union CPriorityQueue_T * const cpriorityqueue_t, Q const value);
    };
};

union CPriorityQueue_T
{
    union CPriorityQueue_T_Class * vtbl;
        struct
    {
      union Object Object;
      union CVector_T _private vector;
      PriorityComparator_T _private cmp;
    };
};

extern union CPriorityQueue_T_Class * Get_CPriorityQueue_T_Class(void);

extern void CPriorityQueue_T_populate(union CPriorityQueue_T * const cpriorityqueue_t, PriorityComparator_T const cmp);

extern void CPriorityQueue_T_populate_reserved(union CPriorityQueue_T * const cpriorityqueue_t, size_t const elems, PriorityComparator_T const cmp);

extern void CPriorityQueue_T_clear(union CPriorityQueue_T * const cpriorityqueue_t);

extern size_t CPriorityQueue_T_size(union CPriorityQueue_T * const cpriorityqueue_t);

extern void CPriorityQueue_T_reserve(union CPriorityQueue_T * const cpriorityqueue_t, size_t const capacity);

extern Q CPriorityQueue_T_poll(union CPriorityQueue_T * const cpriorityqueue_t);

extern Q CPriorityQueue_T_peek(union CPriorityQueue_T * const cpriorityqueue_t);

extern void CPriorityQueue_T_push(union CPriorityQueue_T * const cpriorityqueue_t, Q const value);

#ifdef __cplusplus
}
#endif
#undef _private