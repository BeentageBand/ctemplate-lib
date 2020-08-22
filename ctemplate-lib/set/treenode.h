#include "cobject/ctemplate.h"
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

typedef int (*Comparator_T)(T * const, T * const, size_t);

struct TreeNode_T
{
    T value;
    struct TreeNode_T * left;
    struct TreeNode_T * right;
};

extern struct TreeNode_T * TreeNode_T_leftmost(struct TreeNode_T * treenode_t);
extern struct TreeNode_T * TreeNode_T_rightmost(struct TreeNode_T * treenode_t);
extern struct TreeNode_T * TreeNode_T_insert(struct TreeNode_T * treenode_t, Comparator_T cmp, T const value);
extern struct TreeNode_T * TreeNode_T_insert(struct TreeNode_T * treenode_t, Comparator_T cmp, T const value);
extern struct TreeNode_T * TreeNode_T_erase(struct TreeNode_T * treenode_t, Comparator_T cmp, T const value);
extern size_t TreeNode_T_size(struct TreeNode_T * treenode_t);

#undef TreeNode_T 
#undef Comparator_T 
#undef TreeNode_T_leftmost 
#undef TreeNode_T_rightmost 
#undef TreeNode_T_find 
#undef TreeNode_T_insert 
#undef TreeNode_T_erase 
#undef TreeNode_T_size 
