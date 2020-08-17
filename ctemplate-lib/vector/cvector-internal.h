#ifndef CVECTOR_T_INT_H
#define CVECTOR_T_INT_H
#define CVECTOR_T_IMPLEMENTATION

#include "cvector.h"

static void cvector_t_override(union CVector_T_Class * const cvector_t);

union CVector_T_Class * Get_CVector_T_Class(void)
{
  static union CVector_T_Class clazz;
  if (0 != clazz.Class.offset) return &clazz;
  Class_populate(&clazz.Class, sizeof(clazz), NULL);
  cvector_t_override(&clazz);
  return &clazz;
}
size_t CVector_T_size(union CVector_T * const cvector_t)
{
  return cvector_t->vtbl->size(cvector_t);
}

void CVector_T_clear(union CVector_T * const cvector_t)
{
  return cvector_t->vtbl->clear(cvector_t);
}

T * CVector_T_begin(union CVector_T * const cvector_t)
{
  return cvector_t->vtbl->begin(cvector_t);
}

T * CVector_T_end(union CVector_T * const cvector_t)
{
  return cvector_t->vtbl->end(cvector_t);
}

T * CVector_T_at(union CVector_T * const cvector_t, size_t const index)
{
  return cvector_t->vtbl->at(cvector_t, index);
}

T CVector_T_access(union CVector_T * const cvector_t, size_t const index)
{
  return cvector_t->vtbl->access(cvector_t, index);
}

T CVector_T_back(union CVector_T * const cvector_t)
{
  return cvector_t->vtbl->back(cvector_t);
}

void CVector_T_push_back(union CVector_T * const cvector_t, T const value)
{
  return cvector_t->vtbl->push_back(cvector_t, value);
}

void CVector_T_pop_back(union CVector_T * const cvector_t)
{
  return cvector_t->vtbl->pop_back(cvector_t);
}


#endif /*CVECTOR_T_INT_H*/
