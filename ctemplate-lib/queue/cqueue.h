#include "cobject/cobject.h"

#ifdef CQUEUE_T_IMPLEMENTATION 
#define _private
#else
#define _private const
#endif 

#ifdef __cplusplus
extern "C" {
#endif

union CQueue_T;
union CQueue_T_Class
{
    
    struct
    {
    struct Class Class;
    size_t (* _private size)(union CQueue_T * const cqueue_t);
void (* _private clear)(union CQueue_T * const cqueue_t);
void (* _private reserve)(union CQueue_T * const cqueue_t, size_t const capacity);
T * (* _private begin)(union CQueue_T * const cqueue_t);
T * (* _private end)(union CQueue_T * const cqueue_t);
T * (* _private at)(union CQueue_T * const cqueue_t, size_t const index);
T (* _private access)(union CQueue_T * const cqueue_t, size_t const index);
T (* _private back)(union CQueue_T * const cqueue_t);
T (* _private front)(union CQueue_T * const cqueue_t);
void (* _private push_back)(union CQueue_T * const cqueue_t, T const value);
void (* _private pop_back)(union CQueue_T * const cqueue_t);
void (* _private push_front)(union CQueue_T * const cqueue_t, T const value);
void (* _private pop_front)(union CQueue_T * const cqueue_t);

    };
};

union CQueue_T
{
    union CQueue_T_Class * vtbl;
        struct
    {
      union Object Object;
      size_t _private hd;
size_t _private tl;
size_t _private capacity;
T * _private buffer;

    };
};

extern union CQueue_T_Class * Get_CQueue_T_Class(void);

extern void CQueue_T_populate(union CQueue_T * const cqueue_t);

extern size_t CQueue_T_size(union CQueue_T * const cqueue_t);

extern void CQueue_T_clear(union CQueue_T * const cqueue_t);

extern void CQueue_T_reserve(union CQueue_T * const cqueue_t, size_t const capacity);

extern T * CQueue_T_begin(union CQueue_T * const cqueue_t);

extern T * CQueue_T_end(union CQueue_T * const cqueue_t);

extern T * CQueue_T_at(union CQueue_T * const cqueue_t, size_t const index);

extern T CQueue_T_access(union CQueue_T * const cqueue_t, size_t const index);

extern T CQueue_T_back(union CQueue_T * const cqueue_t);

extern T CQueue_T_front(union CQueue_T * const cqueue_t);

extern void CQueue_T_push_back(union CQueue_T * const cqueue_t, T const value);

extern void CQueue_T_pop_back(union CQueue_T * const cqueue_t);

extern void CQueue_T_push_front(union CQueue_T * const cqueue_t, T const value);

extern void CQueue_T_pop_front(union CQueue_T * const cqueue_t);

#ifdef __cplusplus
}
#endif
