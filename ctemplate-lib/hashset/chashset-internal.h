static void chashset_t_override(union CHashSet_T_Class * const chashset_t);

union CHashSet_T_Class * Get_CHashSet_T_Class(void)
{
  static union CHashSet_T_Class clazz;
  if (0 != clazz.Class.offset) return &clazz;
  Class_populate(&clazz.Class, sizeof(clazz), NULL);
  chashset_t_override(&clazz);
  return &clazz;
}
size_t CHashSet_T_size(union CHashSet_T * const chashset_t)
{
  return chashset_t->vtbl->size(chashset_t);
}

void CHashSet_T_clear(union CHashSet_T * const chashset_t)
{
  return chashset_t->vtbl->clear(chashset_t);
}

void CHashSet_T_reserve(union CHashSet_T * const chashset_t, size_t const capacity)
{
  return chashset_t->vtbl->reserve(chashset_t, capacity);
}

T * CHashSet_T_begin(union CHashSet_T * const chashset_t)
{
  return chashset_t->vtbl->begin(chashset_t);
}

T * CHashSet_T_end(union CHashSet_T * const chashset_t)
{
  return chashset_t->vtbl->end(chashset_t);
}

T * CHashSet_T_find(union CHashSet_T * const chashset_t, T const index)
{
  return chashset_t->vtbl->find(chashset_t, index);
}

void CHashSet_T_insert(union CHashSet_T * const chashset_t, T const value)
{
  return chashset_t->vtbl->insert(chashset_t, value);
}

void CHashSet_T_erase(union CHashSet_T * const chashset_t, T const value)
{
  return chashset_t->vtbl->erase(chashset_t, value);
}
