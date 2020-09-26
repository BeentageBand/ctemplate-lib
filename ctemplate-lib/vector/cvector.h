#include "cobject/cobject.h"

#ifdef CVECTOR_T_IMPLEMENTATION 
#define _private
#else
#define _private const
#endif 

#ifdef __cplusplus
extern "C" {
#endif

union CVector_T;
union CVector_T_Class
{
    
    struct
    {
    struct Class Class;
    size_t (* _private size)(union CVector_T * const cvector_t);
void (* _private clear)(union CVector_T * const cvector_t);
void (* _private reserve)(union CVector_T * const cvector_t, size_t const n);
T * (* _private begin)(union CVector_T * const cvector_t);
T * (* _private end)(union CVector_T * const cvector_t);
T * (* _private at)(union CVector_T * const cvector_t, size_t const index);
T (* _private access)(union CVector_T * const cvector_t, size_t const index);
T (* _private back)(union CVector_T * const cvector_t);
void (* _private push_back)(union CVector_T * const cvector_t, T const value);
void (* _private pop_back)(union CVector_T * const cvector_t);

    };
};

union CVector_T
{
    union CVector_T_Class * vtbl;
        struct
    {
      union Object Object;
      size_t _private i;
size_t _private capacity;
T * _private buffer;

    };
};

extern union CVector_T_Class * Get_CVector_T_Class(void);

extern void CVector_T_populate(union CVector_T * const cvector_t);

extern size_t CVector_T_size(union CVector_T * const cvector_t);

extern void CVector_T_clear(union CVector_T * const cvector_t);

extern void CVector_T_reserve(union CVector_T * const cvector_t, size_t const n);

extern T * CVector_T_begin(union CVector_T * const cvector_t);

extern T * CVector_T_end(union CVector_T * const cvector_t);

extern T * CVector_T_at(union CVector_T * const cvector_t, size_t const index);

extern T CVector_T_access(union CVector_T * const cvector_t, size_t const index);

extern T CVector_T_back(union CVector_T * const cvector_t);

extern void CVector_T_push_back(union CVector_T * const cvector_t, T const value);

extern void CVector_T_pop_back(union CVector_T * const cvector_t);

#ifdef __cplusplus
}
#endif
#undef _private