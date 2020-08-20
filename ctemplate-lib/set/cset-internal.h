#ifndef CSET_T_INT_H
#define CSET_T_INT_H
#define CSET_T_IMPLEMENTATION

#include "cset.h"

static void cset_t_override(union CSet_T_Class * const cset_t);

union CSet_T_Class * Get_CSet_T_Class(void)
{
  static union CSet_T_Class clazz;
  if (0 != clazz.Class.offset) return &clazz;
  Class_populate(&clazz.Class, sizeof(clazz), NULL);
  cset_t_override(&clazz);
  return &clazz;
}
size_t CSet_T_size(union CSet_T * const cset_t)
{
  return cset_t->vtbl->size(cset_t);
}

void CSet_T_clear(union CSet_T * const cset_t)
{
  return cset_t->vtbl->clear(cset_t);
}

T * CSet_T_begin(union CSet_T * const cset_t)
{
  return cset_t->vtbl->begin(cset_t);
}

T * CSet_T_end(union CSet_T * const cset_t)
{
  return cset_t->vtbl->end(cset_t);
}

T * CSet_T_find(union CSet_T * const cset_t, T const index)
{
  return cset_t->vtbl->find(cset_t, index);
}

void CSet_T_insert(union CSet_T * const cset_t, T const value)
{
  return cset_t->vtbl->insert(cset_t, value);
}

void CSet_T_erase(union CSet_T * const cset_t, T const value)
{
  return cset_t->vtbl->erase(cset_t, value);
}


#endif /*CSET_T_INT_H*/
