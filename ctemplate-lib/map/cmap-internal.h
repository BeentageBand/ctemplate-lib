#define Pair_Params CMap_Params
#define Pair_T TEMPLATE(Pair, Pair_Params)

static void cmap_t_override(union CMap_T_Class * const cmap_t);

union CMap_T_Class * Get_CMap_T_Class(void)
{
  static union CMap_T_Class clazz;
  if (0 != clazz.Class.offset) return &clazz;
  Class_populate(&clazz.Class, sizeof(clazz), NULL);
  cmap_t_override(&clazz);
  return &clazz;
}
size_t CMap_T_size(union CMap_T * const cmap_t)
{
  return cmap_t->vtbl->size(cmap_t);
}

void CMap_T_clear(union CMap_T * const cmap_t)
{
  return cmap_t->vtbl->clear(cmap_t);
}

Pair_T * CMap_T_begin(union CMap_T * const cmap_t)
{
  return cmap_t->vtbl->begin(cmap_t);
}

Pair_T * CMap_T_end(union CMap_T * const cmap_t)
{
  return cmap_t->vtbl->end(cmap_t);
}

Pair_T * CMap_T_find(union CMap_T * const cmap_t, Key_T const index)
{
  return cmap_t->vtbl->find(cmap_t, index);
}

void CMap_T_insert(union CMap_T * const cmap_t, Key_T const key, Value_T const value)
{
  return cmap_t->vtbl->insert(cmap_t, key, value);
}

void CMap_T_erase(union CMap_T * const cmap_t, Key_T const key)
{
  return cmap_t->vtbl->erase(cmap_t, key);
}


#undef Pair_Params 
#undef Pair_T 
