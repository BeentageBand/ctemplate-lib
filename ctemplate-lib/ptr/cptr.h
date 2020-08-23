#ifndef CPTR_T_H
#define CPTR_T_H
#include "cobject/cobject.h"

#ifdef CPTR_T_IMPLEMENTATION 
#define _private
#else
#define _private const
#endif 

#ifdef __cplusplus
extern "C" {
#endif

union CPtr_T;
union CPtr_T_Class
{
    
    struct
    {
    struct Class Class;
    bool (* _private empty)(union CPtr_T * const cptr_t);
int (* _private count)(union CPtr_T * const cptr_t);
void (* _private set)(union CPtr_T * const cptr_t, P * const ptr);
P * (* _private get)(union CPtr_T * const cptr_t);
void (* _private share)(union CPtr_T * const cptr_t, union CPtr_T * const new_cptr);

    };
};

union CPtr_T
{
    union CPtr_T_Class * vtbl;
        struct
    {
      union Object Object;
      P * _private ptr;
int * _private count;

    };
};

extern union CPtr_T_Class * Get_CPtr_T_Class(void);

extern void CPtr_T_populate(union CPtr_T * const cptr_t, P * const ptr);

extern bool CPtr_T_empty(union CPtr_T * const cptr_t);

extern int CPtr_T_count(union CPtr_T * const cptr_t);

extern void CPtr_T_set(union CPtr_T * const cptr_t, P * const ptr);

extern P * CPtr_T_get(union CPtr_T * const cptr_t);

extern void CPtr_T_share(union CPtr_T * const cptr_t, union CPtr_T * const new_cptr);

#ifdef __cplusplus
}
#endif
#endif /*CPTR_TNone_H*/
