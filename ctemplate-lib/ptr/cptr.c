#include "cptr-internal.h"
#include <string.h>

static void cptr_t_delete(union CPtr_T * const cptr_t);
static bool cptr_t_empty(union CPtr_T * const cptr_t);
static void cptr_t_set(union CPtr_T * const cptr_t, P * const ptr);
static P * cptr_t_get(union CPtr_T * const cptr_t);
static int cptr_t_count(union CPtr_T * const cptr_t);
static void cptr_t_share(union CPtr_T * const cptr_t, union CPtr_T * const new_cptr);

void cptr_t_override(union CPtr_T_Class * const clazz)
{
  clazz->Class.destroy = cptr_t_delete;
  clazz->empty = cptr_t_empty;
  clazz->set = cptr_t_set;
  clazz->get = cptr_t_get;
  clazz->share = cptr_t_share;
}

void cptr_t_delete(union CPtr_T * const cptr_t)
{
  --(*cptr_t->count);

  if ((*cptr_t->count) <= 0)
  {
    free(cptr_t->ptr); // TODO what to do with object
    free(cptr_t->count);
    cptr_t->ptr = NULL;
  }
}

bool cptr_t_empty(union CPtr_T * const cptr_t)
{
  return NULL == cptr_t->ptr;
}

void cptr_t_set(union CPtr_T * const cptr_t, P * const ptr)
{
  if (cptr_t->ptr) free(cptr_t->ptr); // TODO delete when object
  cptr_t->ptr = ptr;
}

int cptr_t_count(union CPtr_T * const cptr_t)
{
  return (*cptr_t->count);
}

P * cptr_t_get(union CPtr_T * const cptr_t)
{
  return cptr_t->ptr;
}

void cptr_t_share(union CPtr_T * const cptr_t, union CPtr_T * const new_cptr)
{
  memcpy(&new_cptr, cptr_t, sizeof(new_cptr));
  (*cptr_t->count)++;
}

void CPtr_T_populate(union CPtr_T * const cptr_t, P * const ptr)
{
  Object_populate(&cptr_t->Object, &Get_CPtr_T_Class()->Class);
  cptr_t->count = (int *) malloc(sizeof(int));
  *cptr_t->ptr = 1;
  cptr_t->ptr = ptr;
}
