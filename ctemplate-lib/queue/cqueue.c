#include "cqueue-internal.h"
#include <string.h>

static void cqueue_t_delete(union CQueue_T * const);
static size_t cqueue_t_size(union CQueue_T * const);
static void cqueue_t_clear(union CQueue_T * const);
static void cqueue_t_reserve(union CQueue_T * const, size_t const);
static T * cqueue_t_begin(union CQueue_T * const);
static T * cqueue_t_end(union CQueue_T * const);
static T * cqueue_t_at(union CQueue_T * const, size_t const);
static T cqueue_t_access(union CQueue_T * const, size_t const);
static void cqueue_t_push_back(union CQueue_T * const, T const);
static void cqueue_t_push_front(union CQueue_T * const, T const);
static T cqueue_t_back(union CQueue_T * const);
static T cqueue_t_front(union CQueue_T * const);
static void cqueue_t_pop_back(union CQueue_T * const);
static void cqueue_t_pop_front(union CQueue_T * const);

void cqueue_t_override(union CQueue_T_Class * const clazz)
{
  clazz->Class.destroy = (Class_Delete_T) cqueue_t_delete;
  clazz->size = cqueue_t_size;
  clazz->clear = cqueue_t_clear;
  clazz->reserve = cqueue_t_reserve;
  clazz->begin = cqueue_t_begin;
  clazz->end = cqueue_t_end;
  clazz->at = cqueue_t_at;
  clazz->access = cqueue_t_access;
  clazz->back = cqueue_t_back;
  clazz->front = cqueue_t_front;
  clazz->push_back = cqueue_t_push_back;
  clazz->pop_back = cqueue_t_pop_back;
  clazz->push_front = cqueue_t_push_front;
  clazz->pop_front = cqueue_t_pop_front;
}

void cqueue_t_delete(union CQueue_T * const cqueue_t)
{
  CQueue_T_clear(cqueue_t);
  cqueue_t->buffer = NULL;
  cqueue_t->capacity = 0;
}
 
void CQueue_T_populate(union CQueue_T * const cqueue_t)
{
    Object_populate(&cqueue_t->Object, &Get_CQueue_T_Class()->Class);
    cqueue_t->hd = 0;
    cqueue_t->tl = 0;
    cqueue_t->capacity = 0;
    cqueue_t->buffer = NULL;
    CQueue_T_reserve(cqueue_t, 5);
}

T * cqueue_t_begin(union CQueue_T * const cqueue_t)
{
    return cqueue_t->buffer + cqueue_t->hd;
}

T * cqueue_t_end(union CQueue_T * const cqueue_t)
{
    return cqueue_t->buffer + cqueue_t->tl;
}

T cqueue_t_front(union CQueue_T * const cqueue_t)
{
    return cqueue_t->buffer[cqueue_t->hd];
}

T cqueue_t_back(union CQueue_T * const cqueue_t)
{
    return cqueue_t->buffer[cqueue_t->tl - 1];
}

void cqueue_t_push_back(union CQueue_T * const cqueue_t, T const value)
{
    size_t new_index = (cqueue_t->tl + 1)  % cqueue_t->capacity;
    if (new_index == cqueue_t->hd) 
    {
      CQueue_T_reserve(cqueue_t, cqueue_t->capacity * 2);
      new_index = (cqueue_t->tl + 1)  % cqueue_t->capacity;
    }
    cqueue_t->buffer[cqueue_t->tl] = value;
    cqueue_t->tl = new_index; 
}

void cqueue_t_pop_back(union CQueue_T * const cqueue_t)
{
    if (cqueue_t->hd == cqueue_t->tl) return;
    size_t new_index = (cqueue_t->tl) ? cqueue_t->tl - 1 : cqueue_t->capacity - 1; 
    cqueue_t->tl = new_index;
    memset(cqueue_t->buffer + cqueue_t->tl, 0, sizeof(cqueue_t->buffer[cqueue_t->tl]));
}

void cqueue_t_push_front(union CQueue_T * const cqueue_t, T const value)
{
    size_t new_index = (cqueue_t->hd) ? cqueue_t->hd - 1 : cqueue_t->capacity - 1;
    if (new_index == cqueue_t->tl)
    {
      CQueue_T_reserve(cqueue_t, cqueue_t->capacity * 2);
      new_index = (cqueue_t->hd) ? cqueue_t->hd - 1 : cqueue_t->capacity - 1;
    }
    cqueue_t->hd = new_index;
    cqueue_t->buffer[cqueue_t->hd] = value;
}

void cqueue_t_pop_front(union CQueue_T * const cqueue_t)
{
    if (cqueue_t->hd == cqueue_t->tl) return;
    size_t new_index = (cqueue_t->hd + 1) % cqueue_t->capacity;
    memset(cqueue_t->buffer + cqueue_t->hd, 0, sizeof(cqueue_t->buffer[cqueue_t->hd]));
    cqueue_t->hd = new_index;
}

size_t cqueue_t_size(union CQueue_T * const cqueue_t)
{
    return (cqueue_t->tl >= cqueue_t->hd) ? cqueue_t->tl - cqueue_t->hd :
     cqueue_t->capacity + cqueue_t->tl - cqueue_t->hd;
}


T * cqueue_t_at(union CQueue_T * const cqueue_t, size_t const index)
{
    return cqueue_t->buffer + ((cqueue_t->hd + index) % cqueue_t->capacity);
}

T cqueue_t_access(union CQueue_T * const cqueue_t, size_t const index)
{
   return cqueue_t->buffer[(cqueue_t->hd + index) % cqueue_t->capacity];
}

size_t cqueue_t_capacity(union CQueue_T * const cqueue_t)
{
    return cqueue_t->capacity;
}

void cqueue_t_clear(union CQueue_T * const cqueue_t)
{
   while(cqueue_t->hd != cqueue_t->tl) 
   {
      cqueue_t->vtbl->pop_back(cqueue_t);
   }
}

void cqueue_t_reserve(union CQueue_T * const cqueue_t, size_t const capacity)
{
  if (cqueue_t->capacity >= capacity) return;
  T * old_ringbuff = cqueue_t->buffer;
  size_t old_capacity = cqueue_t->capacity;
  cqueue_t->capacity = capacity;
  cqueue_t->buffer = (T*) malloc(cqueue_t->capacity * sizeof(T));

  if (cqueue_t->hd > cqueue_t->tl)
  {
    size_t hd_chunk = old_capacity - cqueue_t->hd;
    memcpy(cqueue_t->buffer, old_ringbuff + cqueue_t->hd,  hd_chunk * sizeof(T));
    memcpy(cqueue_t->buffer + hd_chunk, old_ringbuff, cqueue_t->tl * sizeof(T));
    cqueue_t->tl = hd_chunk + cqueue_t->tl;
    cqueue_t->hd = 0;
  }
  else 
  {
    memcpy(cqueue_t->buffer, old_ringbuff, sizeof(T) * old_capacity);
  }

  if (old_ringbuff) free(old_ringbuff);
}
