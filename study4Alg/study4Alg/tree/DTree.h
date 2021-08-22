/*
 * @author Double
 * @since 2021/08/22
 */

#ifndef D_TREE_H
#define D_TREE_H

#include <stdint.h>

typedef struct TreeNode {
    int32_t data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

#ifdef __cplusplus
extern "C" {
#endif

void CreateTreeByArr(int32_t arr[], int32_t numArr, TreeNode **root);
void ReleaseTree(TreeNode *root);

void PrintTreePreorder(TreeNode *root);
void PrintTreeInorder(TreeNode *root);
void PrintTreePostorder(TreeNode *root);

#ifdef __cplusplus
}
#endif

#endif // D_TREE_H
