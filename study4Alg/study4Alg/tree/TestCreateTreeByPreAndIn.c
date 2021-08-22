#include <stdlib.h>
#include <stdio.h>
#include "DTree.h"

void TestCreateTreeByPreAndIn()
{
    printf("%s\n", __FUNCTION__);

    int preorder[] = { 3, 9, 20, 15, 7 };
    int inorder[] = { 9, 3, 15, 20, 7 };

    TreeNode *root = NULL;
    CreateTreeByPreAndIn(preorder, inorder, sizeof(preorder) / sizeof(int), &root);

    PrintTreePreorder(root);
    printf("\n");
    PrintTreeInorder(root);
    printf("\n");
    PrintTreePostorder(root);
    printf("\n");

    ReleaseTree(root);

    printf("\n");
}
