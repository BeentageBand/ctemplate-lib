#include "cobject/cobject.h"

#ifdef CQUEUE_T_IMPLEMENTATION 
#define cqueue_t_private
#else
#define cqueue_t_private const
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
    size_t (* cqueue_t_private size)(union CQueue_T * const cqueue_t);
void (* cqueue_t_private clear)(union CQueue_T * const cqueue_t);
void (* cqueue_t_private reserve)(union CQueue_T * const cqueue_t, size_t const capacity);
T * (* cqueue_t_private begin)(union CQueue_T * const cqueue_t);
T * (* cqueue_t_private end)(union CQueue_T * const cqueue_t);
T * (* cqueue_t_private at)(union CQueue_T * const cqueue_t, size_t const index);
T (* cqueue_t_private access)(union CQueue_T * const cqueue_t, size_t const index);
T (* cqueue_t_private back)(union CQueue_T * const cqueue_t);
T (* cqueue_t_private front)(union CQueue_T * const cqueue_t);
void (* cqueue_t_private push_back)(union CQueue_T * const cqueue_t, T const value);
void (* cqueue_t_private pop_back)(union CQueue_T * const cqueue_t);
void (* cqueue_t_private push_front)(union CQueue_T * const cqueue_t, T const value);
void (* cqueue_t_private pop_front)(union CQueue_T * const cqueue_t);

    };
};

union CQueue_T
{
    union CQueue_T_Class * vtbl;
        struct
    {
      union Object Object;
      size_t cqueue_t_private hd;
size_t cqueue_t_private tl;
size_t cqueue_t_private capacity;
T * cqueue_t_private buffer;

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
