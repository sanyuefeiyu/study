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

static int32_t FindNode(int32_t arr[], int32_t numArr, int32_t value)
{
    for (int32_t i = 0; i < numArr; i++) {
        if (arr[i] == value) {
            return i;
        }
    }

    return -1;
}

void CreateTreeByPreAndIn(int32_t preorder[], int32_t inorder[], int32_t numArr, TreeNode **root)
{
    if (numArr <= 0 || root == NULL) {
        return;
    }

    *root = (TreeNode *)malloc(sizeof(TreeNode));
    (*root)->data = preorder[0];
    (*root)->left = NULL;
    (*root)->right = NULL;

    int32_t index = FindNode(inorder, numArr, preorder[0]);
    int32_t leftSize = index;
    int32_t rightSize = numArr - 1 - index;

    CreateTreeByPreAndIn(preorder + 1, inorder, leftSize, &((*root)->left));
    CreateTreeByPreAndIn(preorder + 1 + leftSize, inorder + 1 + leftSize, rightSize, &((*root)->right));
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
