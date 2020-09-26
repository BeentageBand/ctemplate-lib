static void cpriorityqueue_t_override(union CPriorityQueue_T_Class * const cpriorityqueue_t);

union CPriorityQueue_T_Class * Get_CPriorityQueue_T_Class(void)
{
  static union CPriorityQueue_T_Class clazz;
  if (0 != clazz.Class.offset) return &clazz;
  Class_populate(&clazz.Class, sizeof(clazz), NULL);
  cpriorityqueue_t_override(&clazz);
  return &clazz;
}
void CPriorityQueue_T_clear(union CPriorityQueue_T * const cpriorityqueue_t)
{
  return cpriorityqueue_t->vtbl->clear(cpriorityqueue_t);
}

size_t CPriorityQueue_T_size(union CPriorityQueue_T * const cpriorityqueue_t)
{
  return cpriorityqueue_t->vtbl->size(cpriorityqueue_t);
}

void CPriorityQueue_T_reserve(union CPriorityQueue_T * const cpriorityqueue_t, size_t const capacity)
{
  return cpriorityqueue_t->vtbl->reserve(cpriorityqueue_t, capacity);
}

Q CPriorityQueue_T_poll(union CPriorityQueue_T * const cpriorityqueue_t)
{
  return cpriorityqueue_t->vtbl->poll(cpriorityqueue_t);
}

Q CPriorityQueue_T_peek(union CPriorityQueue_T * const cpriorityqueue_t)
{
  return cpriorityqueue_t->vtbl->peek(cpriorityqueue_t);
}

void CPriorityQueue_T_push(union CPriorityQueue_T * const cpriorityqueue_t, Q const value)
{
  return cpriorityqueue_t->vtbl->push(cpriorityqueue_t, value);
}