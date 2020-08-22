static void chashmap_t_override(union CHashMap_T_Class * const chashmap_t);

union CHashMap_T_Class * Get_CHashMap_T_Class(void)
{
  static union CHashMap_T_Class clazz;
  if (0 != clazz.Class.offset) return &clazz;
  Class_populate(&clazz.Class, sizeof(clazz), NULL);
  chashmap_t_override(&clazz);
  return &clazz;
}
size_t CHashMap_T_size(union CHashMap_T * const chashmap_t)
{
  return chashmap_t->vtbl->size(chashmap_t);
}

void CHashMap_T_clear(union CHashMap_T * const chashmap_t)
{
  return chashmap_t->vtbl->clear(chashmap_t);
}

HashPair_T * CHashMap_T_begin(union CHashMap_T * const chashmap_t)
{
  return chashmap_t->vtbl->begin(chashmap_t);
}

HashPair_T * CHashMap_T_end(union CHashMap_T * const chashmap_t)
{
  return chashmap_t->vtbl->end(chashmap_t);
}

HashPair_T * CHashMap_T_find(union CHashMap_T * const chashmap_t, HashKey_T const index)
{
  return chashmap_t->vtbl->find(chashmap_t, index);
}

void CHashMap_T_insert(union CHashMap_T * const chashmap_t, HashKey_T const key, HashValue_T const value)
{
  return chashmap_t->vtbl->insert(chashmap_t, key, value);
}

void CHashMap_T_erase(union CHashMap_T * const chashmap_t, HashKey_T const key)
{
  return chashmap_t->vtbl->erase(chashmap_t, key);
}
