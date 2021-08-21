#include <stdio.h>
#include <malloc.h>

typedef struct tree
{
    int data;
    struct tree *left, *right;
}ElemBT;

static void create_btree(ElemBT *root, int list[], int n) /*n表示list数组中元素的个数*/
{
    int i;
    ElemBT *current, *parent, *p;

    for (i = 1; i < n; i++)
    {
        p = (ElemBT *)malloc(sizeof(ElemBT));
        p->left = p->right = NULL;
        p->data = list[i];
        current = root;
        while (current != NULL)
        {
            parent = current;
            if (current->data > p->data)
                current = current->left;
            else
                current = current->right;
        }
        if (parent->data > p->data)
            parent->left = p;
        else
            parent->right = p;
    }
}

int TestCreateBtreeByList()
{
    int list[7] = { 30, 18, 16, 25, 34, 7, 31 };
    ElemBT *root;

    root = (ElemBT *)malloc(sizeof(ElemBT));
    root->data = list[0];
    root->left = root->right = NULL;
    create_btree(root, list, 7);

    return 0;
}
