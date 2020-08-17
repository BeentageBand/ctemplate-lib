#ifndef CQUEUE_T_INT_H
#define CQUEUE_T_INT_H
#define CQUEUE_T_IMPLEMENTATION

#include "cqueue.h"

static void cqueue_t_override(union CQueue_T_Class * const cqueue_t);

union CQueue_T_Class * Get_CQueue_T_Class(void)
{
  static union CQueue_T_Class clazz;
  if (0 != clazz.Class.offset) return &clazz;
  Class_populate(&clazz.Class, sizeof(clazz), NULL);
  cqueue_t_override(&clazz);
  return &clazz;
}
size_t CQueue_T_size(union CQueue_T * const cqueue_t)
{
  return cqueue_t->vtbl->size(cqueue_t);
}

void CQueue_T_clear(union CQueue_T * const cqueue_t)
{
  return cqueue_t->vtbl->clear(cqueue_t);
}

T * CQueue_T_begin(union CQueue_T * const cqueue_t)
{
  return cqueue_t->vtbl->begin(cqueue_t);
}

T * CQueue_T_end(union CQueue_T * const cqueue_t)
{
  return cqueue_t->vtbl->end(cqueue_t);
}

T * CQueue_T_at(union CQueue_T * const cqueue_t, size_t const index)
{
  return cqueue_t->vtbl->at(cqueue_t, index);
}

T CQueue_T_access(union CQueue_T * const cqueue_t, size_t const index)
{
  return cqueue_t->vtbl->access(cqueue_t, index);
}

T CQueue_T_back(union CQueue_T * const cqueue_t)
{
  return cqueue_t->vtbl->back(cqueue_t);
}

T CQueue_T_front(union CQueue_T * const cqueue_t)
{
  return cqueue_t->vtbl->front(cqueue_t);
}

void CQueue_T_push_back(union CQueue_T * const cqueue_t, T const value)
{
  return cqueue_t->vtbl->push_back(cqueue_t, value);
}

void CQueue_T_pop_back(union CQueue_T * const cqueue_t)
{
  return cqueue_t->vtbl->pop_back(cqueue_t);
}

void CQueue_T_push_front(union CQueue_T * const cqueue_t, T const value)
{
  return cqueue_t->vtbl->push_front(cqueue_t, value);
}

void CQueue_T_pop_front(union CQueue_T * const cqueue_t)
{
  return cqueue_t->vtbl->pop_front(cqueue_t);
}


#endif /*CQUEUE_T_INT_H*/
