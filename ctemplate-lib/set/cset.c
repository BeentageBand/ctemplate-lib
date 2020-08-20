#include "cset-internal.h"
#include <string.h>

#define TreeNode_Params CSet_Params
#include "treenode.c"

#define TreeNode_T TEMPLATE(TreeNode, TreeNode_Params)
#define Comparator_T TEMPLATE(Comparator, TreeNode_Params)
#define TreeNode_T_leftmost TEMPLATE(TreeNode, TreeNode_Params, leftmost)
#define TreeNode_T_rightmost TEMPLATE(TreeNode, TreeNode_Params, rightmost)
#define TreeNode_T_find TEMPLATE(TreeNode, TreeNode_Params, find)
#define TreeNode_T_insert TEMPLATE(TreeNode, TreeNode_Params, insert)
#define TreeNode_T_erase TEMPLATE(TreeNode, TreeNode_Params, erase)
#define TreeNode_T_size TEMPLATE(TreeNode, TreeNode_Params, size)

static size_t cset_t_size(union CSet_T * const cset_t);
static void cset_t_clear(union CSet_T * const cset_t);
static T * cset_t_begin(union CSet_T * const cset_t);
static T * cset_t_end(union CSet_T * const cset_t);
static T * cset_t_find(union CSet_T * const cset_t, T const index);
static void cset_t_insert(union CSet_T * const cset_t, T const value);
static void cset_t_erase(union CSet_T * const cset_t, T const value);

void cset_t_override(union CSet_T_Class * const clazz)
{
  clazz->size = cset_t_size;
  clazz->clear = cset_t_clear;
  clazz->begin = cset_t_begin;
  clazz->end = cset_t_end;
  clazz->find = cset_t_find;
  clazz->insert = cset_t_insert;
  clazz->erase = cset_t_erase;
}

size_t cset_t_size(union CSet_T * const cset_t)
{
    return TreeNode_T_size(cset_t->head);
}

void cset_t_clear(union CSet_T * const cset_t)
{
    while(cset_t->head) 
    {
        CSet_T_erase(cset_t, cset_t->head->value);
    }
}

T * cset_t_begin(union CSet_T * const cset_t)
{
    if (NULL == cset_t->head) return NULL;
    struct TreeNode_T * right = TreeNode_T_rightmost(cset_t->head);
    return (right) ? right->value : NULL;
}

T * cset_t_end(union CSet_T * const cset_t)
{
    if (NULL == cset_t->head) return NULL;
    struct TreeNode_T * left = TreeNode_T_leftmost(cset_t->head);
    return (left) ? left->value : NULL;
}

T * cset_t_find(union CSet_T * const cset_t, T const index)
{
    if (NULL == cset_t->head) return NULL;
    struct TreeNode_T * found = TreeNode_T_find(cset_t->head, cset_t->cmp, index);
    return (found) ? &found->value : NULL;
}

void cset_t_insert(union CSet_T * const cset_t, T const value)
{
    cset_t->head = TreeNode_T_insert(cset_t->head, cset_t->cmp, value);
}

void cset_t_erase(union CSet_T * const cset_t, T const value)
{
    cset_t->head = TreeNode_T_erase(cset_t->head, cset_t->cmp, value);
}

void CSet_T_populate(union CSet_T * const cset_t, struct TreeNode_T * const head, size_t const size, Comparator_T const cmp)
{
    Object_populate(&cset_t->Object, &Get_CSet_T_Class()->Class);
    cset_t->head = head;
    cset_t->size = size;
    cset_t->cmp = (NULL == cmp) ? (Comparator_T)memcmp : cmp;
}

#undef TreeNode_T 
#undef Comparator_T 
#undef TreeNode_T_leftmost 
#undef TreeNode_T_rightmost 
#undef TreeNode_T_find 
#undef TreeNode_T_insert 
#undef TreeNode_T_erase 
#undef TreeNode_T_size 
#undef TreeNode_Params
