#include <stdlib.h>
#include <stdio.h>
#include "DTree.h"

static void CreateTreeByArrInternal(int32_t arr[], int32_t numArr, TreeNode **root, int pos)
{
    if ((pos - 1) > (numArr - 1)) {
        return;
    }

    if (arr[pos - 1] == 0) {
        return;
    }

    *root = (TreeNode *)malloc(sizeof(TreeNode));
    (*root)->data = arr[pos - 1];
    (*root)->left = NULL;
    (*root)->right = NULL;

    CreateTreeByArrInternal(arr, numArr, &((*root)->left), pos * 2);
    CreateTreeByArrInternal(arr, numArr, &((*root)->right), pos * 2 + 1);

}

void CreateTreeByArr(int32_t arr[], int32_t numArr, TreeNode **root)
{
    if (numArr <= 0 || root == NULL) {
        return;
    }

    int pos = 1;
    CreateTreeByArrInternal(arr, numArr, root, pos);
}

void ReleaseTree(TreeNode *root)
{
    if (root == NULL) {
        return;
    }

    ReleaseTree(root->left);
    ReleaseTree(root->right);
    free(root);
}

void PrintTreePreorder(TreeNode *root)
{
    if (root == NULL) {
        return;
    }

    printf("  %d", root->data);
    PrintTreePreorder(root->left);
    PrintTreePreorder(root->right);
}

void PrintTreeInorder(TreeNode *root)
{
    if (root == NULL) {
        return;
    }

    PrintTreeInorder(root->left);
    printf("  %d", root->data);
    PrintTreeInorder(root->right);
}

void PrintTreePostorder(TreeNode *root)
{
    if (root == NULL) {
        return;
    }

    PrintTreePostorder(root->left);
    PrintTreePostorder(root->right);
    printf("  %d", root->data);
}
