#include <stdlib.h>
#include <stdio.h>
#include "DTree.h"

int GetMaxPathSum(TreeNode *root, int *maxPathSum)
{
    if (root == NULL) {
        return 0;
    }

    int leftPathSum = GetMaxPathSum(root->left, maxPathSum);
    int rightPathSum = GetMaxPathSum(root->right, maxPathSum);

    int curNodeMaxPathSum = max(root->data, max(root->data + leftPathSum, root->data + rightPathSum));
    *maxPathSum = max(*maxPathSum, max(curNodeMaxPathSum, root->data + leftPathSum + rightPathSum));

    return curNodeMaxPathSum;
}

void TestMaxPathSum()
{
    printf("%s\n", __FUNCTION__);

    int arr[] = { -10, 9, 20, 0, 0, 15, 7 };
    TreeNode *root = NULL;

    CreateTreeByArr(arr, sizeof(arr) / sizeof(int), &root);
    PrintTreePreorder(root);
    printf("\n");
    PrintTreeInorder(root);
    printf("\n");

    int maxPathSum = INT_MIN;
    GetMaxPathSum(root, &maxPathSum);
    printf("maxPathSum: %d\n", maxPathSum);

    ReleaseTree(root);

    printf("\n");
}
