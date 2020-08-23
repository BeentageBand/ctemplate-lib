static void cptr_t_override(union CPtr_T_Class * const cptr_t);

union CPtr_T_Class * Get_CPtr_T_Class(void)
{
  static union CPtr_T_Class clazz;
  if (0 != clazz.Class.offset) return &clazz;
  Class_populate(&clazz.Class, sizeof(clazz), NULL);
  cptr_t_override(&clazz);
  return &clazz;
}
bool CPtr_T_empty(union CPtr_T * const cptr_t)
{
  return cptr_t->vtbl->empty(cptr_t);
}

int CPtr_T_count(union CPtr_T * const cptr_t)
{
  return cptr_t->vtbl->count(cptr_t);
}

void CPtr_T_set(union CPtr_T * const cptr_t, P * const ptr)
{
  return cptr_t->vtbl->set(cptr_t, ptr);
}

P * CPtr_T_get(union CPtr_T * const cptr_t)
{
  return cptr_t->vtbl->get(cptr_t);
}

void CPtr_T_share(union CPtr_T * const cptr_t, union CPtr_T * const new_cptr)
{
  return cptr_t->vtbl->share(cptr_t, new_cptr);
}
