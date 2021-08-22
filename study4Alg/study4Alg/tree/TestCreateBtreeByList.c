#include <stdlib.h>
#include <stdio.h>
#include "DTree.h"

static void CreateBTree(int unsorted[], int numUnsorted, TreeNode *root)
{
    for (int i = 1; i < numUnsorted; i++) {
        TreeNode *p = (TreeNode *)malloc(sizeof(TreeNode));
        p->data = unsorted[i];
        p->left = NULL;
        p->right = NULL;

        TreeNode *parent = NULL;
        TreeNode *current = root;
        while (current != NULL) {
            parent = current;
            if (current->data > p->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (parent->data > p->data) {
            parent->left = p;
        } else {
            parent->right = p;
        }
    }
}

void TestCreateBtreeByList()
{
    printf("%s\n", __FUNCTION__);

    int unsorted[7] = { 30, 18, 16, 25, 34, 7, 31 };

    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->data = unsorted[0];
    root->left = NULL;
    root->right = NULL;

    CreateBTree(unsorted, sizeof(unsorted) / sizeof(int), root);

    PrintTreeInorder(root);
    printf("\n");

    ReleaseTree(root);
}
