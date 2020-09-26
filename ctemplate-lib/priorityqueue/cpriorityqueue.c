#include "cpriorityqueue-internal.h"

#define cvector_t_heapify TEMPLATE(cvector, CPriorityQueue_Params, heapify)
#define cpriorityqueue_t_heapify TEMPLATE(cpriorityqueue, CPriorityQueue_Params, heapify)
#define cvector_t_swap TEMPLATE(cvector, CPriorityQueue_Params, swap)
#define cpriorityqueue_t_min TEMPLATE(cpriorityqueue, CPriorityQueue_Params, min)

static void cpriorityqueue_t_delete(union CPriorityQueue_T * const cpriorityqueue_t);
static void cpriorityqueue_t_clear(union CPriorityQueue_T * const cpriorityqueue_t);
static size_t cpriorityqueue_t_size(union CPriorityQueue_T * const cpriorityqueue_t);
static void cpriorityqueue_t_reserve(union CPriorityQueue_T * const cpriorityqueue_t, size_t const capacity);
static Q cpriorityqueue_t_poll(union CPriorityQueue_T * const cpriorityqueue_t);
static Q cpriorityqueue_t_peek(union CPriorityQueue_T * const cpriorityqueue_t);
static void cpriorityqueue_t_push(union CPriorityQueue_T * const cpriorityqueue_t, Q const value);
static void cpriorityqueue_t_heapify(union CPriorityQueue_T * const cpriorityqueue_t);
static void cvector_t_heapify(union CVector_T * const cvector_t, PriorityComparator_T const cmp, size_t const i);
static void cvector_t_swap(union CVector_T * const cvector_t, size_t const i, size_t const j);
static bool cpriorityqueue_t_min(Q * const a, Q * const b);

void cpriorityqueue_t_delete(union CPriorityQueue_T * const cpriorityqueue_t) 
{
  _delete(&cpriorityqueue_t->vector);
  cpriorityqueue_t->cmp = NULL;
}

void cpriorityqueue_t_override(union CPriorityQueue_T_Class * const clazz)
{
  clazz->Class.destroy = (Class_Delete_T) cpriorityqueue_t_delete;
  clazz->clear = cpriorityqueue_t_clear;
  clazz->size = cpriorityqueue_t_size;
  clazz->reserve = cpriorityqueue_t_reserve;
  clazz->poll = cpriorityqueue_t_poll;
  clazz->peek = cpriorityqueue_t_peek;
  clazz->push = cpriorityqueue_t_push;
}

void cpriorityqueue_t_clear(union CPriorityQueue_T * const cpriorityqueue_t)
{
  while (0 < CPriorityQueue_T_size(cpriorityqueue_t))
  {
    CPriorityQueue_T_poll(cpriorityqueue_t);
  }
}

size_t cpriorityqueue_t_size(union CPriorityQueue_T * const cpriorityqueue_t)
{
  return CVector_T_size(&cpriorityqueue_t->vector);
}

void cpriorityqueue_t_reserve(union CPriorityQueue_T * const cpriorityqueue_t, size_t const capacity)
{
  CVector_T_reserve(&cpriorityqueue_t->vector, capacity);
}

Q cpriorityqueue_t_poll(union CPriorityQueue_T * const cpriorityqueue_t)
{
  return CVector_T_back(&cpriorityqueue_t->vector);
}

Q cpriorityqueue_t_peek(union CPriorityQueue_T * const cpriorityqueue_t)
{
  Q back = CVector_T_back(&cpriorityqueue_t->vector);
  CVector_T_pop_back(&cpriorityqueue_t->vector);
  cpriorityqueue_t_heapify(cpriorityqueue_t);
  return back;
}

void cpriorityqueue_t_push(union CPriorityQueue_T * const cpriorityqueue_t, Q const value)
{
  CVector_T_push_back(&cpriorityqueue_t->vector, value);
  cpriorityqueue_t_heapify(cpriorityqueue_t);
}

void cpriorityqueue_t_heapify(union CPriorityQueue_T * const cpriorityqueue_t)
{
  cvector_t_heapify(&cpriorityqueue_t->vector, cpriorityqueue_t->cmp, 0);
  cvector_t_swap(&cpriorityqueue_t->vector, 0, CVector_T_size(&cpriorityqueue_t->vector) - 1);
}

void cvector_t_heapify(union CVector_T * const cvector_t, PriorityComparator_T cmp, size_t i)
{
  size_t left = i * 2 + 1;
  size_t right = i * 2 + 2;
  size_t bound = CVector_T_size(cvector_t);

  if (left < bound) {
    cvector_t_heapify(cvector_t, cmp, left);
    if (cmp(CVector_T_at(cvector_t, left), CVector_T_at(cvector_t, i)))
    {
      cvector_t_swap(cvector_t, left, i);
    }
  }

  if (right < bound) {
    cvector_t_heapify(cvector_t, cmp, right);
    if (cmp(CVector_T_at(cvector_t, right), CVector_T_at(cvector_t, i)))
    {
      cvector_t_swap(cvector_t, right, i);
    }
  }
}

bool cpriorityqueue_t_min(Q * const a, Q * const b)
{
  return memcmp(a, b, sizeof(*a)) < 0;
}

void cvector_t_swap(union CVector_T * const cvector_t, size_t const i, size_t const j)
{
  Q tmp = *CVector_T_at(cvector_t, i);
  *CVector_T_at(cvector_t, i) = *CVector_T_at(cvector_t, j);
  *CVector_T_at(cvector_t, j) = tmp;
}

void CPriorityQueue_T_populate(union CPriorityQueue_T * const cpriorityqueue_t, PriorityComparator_T const cmp)
{
  Object_populate(&cpriorityqueue_t->Object, &Get_CPriorityQueue_T_Class()->Class);
  cpriorityqueue_t->cmp = (NULL == cmp) ? cpriorityqueue_t_min : cmp;
  CVector_T_populate(&cpriorityqueue_t->vector);
}

void CPriorityQueue_T_populate_reserved(union CPriorityQueue_T * const cpriorityqueue_t, size_t const elems, PriorityComparator_T const cmp)
{
  Object_populate(&cpriorityqueue_t->Object, &Get_CPriorityQueue_T_Class()->Class);
  cpriorityqueue_t->cmp = (NULL == cmp) ? cpriorityqueue_t_min : cmp;
  CVector_T_populate(&cpriorityqueue_t->vector);
  CVector_T_reserve(&cpriorityqueue_t->vector, elems);
}


#undef cvector_t_heapify
#undef cpriorityqueue_t_heapify
#undef cvector_t_swap
#undef cpriorityqueue_t_min
