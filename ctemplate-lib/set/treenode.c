#include <string.h>
#include <stdio.h>

#ifndef TreeNode_Params
# error "TreeNode_Params should be defined"
#endif // !TreeNode_Params

#define TreeNode_T TEMPLATE(TreeNode, TreeNode_Params)
#define Comparator_T TEMPLATE(Comparator, TreeNode_Params)
#define TreeNode_T_leftmost TEMPLATE(TreeNode, TreeNode_Params, leftmost)
#define TreeNode_T_rightmost TEMPLATE(TreeNode, TreeNode_Params, rightmost)
#define TreeNode_T_find TEMPLATE(TreeNode, TreeNode_Params, find)
#define TreeNode_T_insert TEMPLATE(TreeNode, TreeNode_Params, insert)
#define TreeNode_T_erase TEMPLATE(TreeNode, TreeNode_Params, erase)
#define TreeNode_T_size TEMPLATE(TreeNode, TreeNode_Params, size)

struct TreeNode_T * TreeNode_T_leftmost(struct TreeNode_T * treenode_t)
{
  if (NULL == treenode_t) return treenode_t;
  while (NULL != treenode_t->left) treenode_t = treenode_t->left;
  return treenode_t;
}

struct TreeNode_T * TreeNode_T_rightmost(struct TreeNode_T * treenode_t)
{
  if (NULL == treenode_t) return treenode_t;
  while (NULL != treenode_t->right) treenode_t = treenode_t->right;
  return treenode_t;
}

struct TreeNode_T * TreeNode_T_find(struct TreeNode_T * treenode_t, Comparator_T cmp, T const value)
{
  while(treenode_t)
  {
    if (0 == cmp(&(treenode_t->value), &value, sizeof(value))) 
    {
      return treenode_t;
    }
    else if (cmp(&(treenode_t->value), &value, sizeof(value)) > 0)
    {
      treenode_t = treenode_t->left;
    }
    else 
    {
      treenode_t = treenode_t->right;
    }
  }
  return treenode_t;
}


struct TreeNode_T * TreeNode_T_insert(struct TreeNode_T * treenode_t, Comparator_T cmp, T const value)
{
    if (NULL == treenode_t)
    {
      treenode_t = (struct TreeNode_T *) malloc(sizeof(struct TreeNode_T));
      treenode_t->value = value;
      treenode_t->left = NULL;
      treenode_t->right = NULL;
    } 
    else if (cmp(&(treenode_t->value), &value, sizeof(value)) > 0)
    {
      treenode_t->left = TreeNode_T_insert(treenode_t->left, cmp, value);

    }
    else if (cmp(&(treenode_t->value), &value, sizeof(value)) < 0)
    {
      treenode_t->right = TreeNode_T_insert(treenode_t->right, cmp, value);
    }

    return treenode_t;
}

struct TreeNode_T * TreeNode_T_erase(struct TreeNode_T * treenode_t, Comparator_T cmp, T const value)
{
    if (NULL == treenode_t) return treenode_t;
    if (cmp(&treenode_t->value, &value, sizeof(value)) < 0)
    {
        treenode_t->right = TreeNode_T_erase(treenode_t->right, cmp, value);
    }
    else if (cmp(&treenode_t->value, &value, sizeof(value)) > 0)
    {
        treenode_t->left = TreeNode_T_erase(treenode_t->left, cmp, value);
    } else {
        if (NULL == treenode_t->left) 
        {
            struct TreeNode_T * right = treenode_t->right;
            free(treenode_t);
            return right;
        }

        if (NULL == treenode_t->right) {
            struct TreeNode_T * left = treenode_t->left;
            free(treenode_t);
            return left;
        }

        struct TreeNode_T * right = TreeNode_T_leftmost(treenode_t->right);
        treenode_t->value = right->value;
        treenode_t->right = TreeNode_T_erase(treenode_t->right, cmp, right->value);
    }

    return treenode_t;
}

size_t TreeNode_T_size(struct TreeNode_T * treenode_t)
{
  if (NULL == treenode_t) return 0;

  return TreeNode_T_size(treenode_t->left) + TreeNode_T_size(treenode_t->right) + 1;
}

#undef TreeNode_T 
#undef Comparator_T 
#undef TreeNode_T_leftmost 
#undef TreeNode_T_rightmost 
#undef TreeNode_T_find 
#undef TreeNode_T_insert 
#undef TreeNode_T_erase 
#undef TreeNode_T_size 
