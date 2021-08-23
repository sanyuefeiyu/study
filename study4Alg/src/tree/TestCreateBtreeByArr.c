#include <stdio.h>

static void CreateBTree(int unsorted[], int numUnsorted, int bTree[])
{
    bTree[1] = unsorted[0];

    for (int i = 1; i < numUnsorted; i++) {
        int pos = 1;
        while (bTree[pos] != 0) {
            if (unsorted[i] < bTree[pos]) {
                pos *= 2;
            } else {
                pos = pos * 2 + 1;
            }
        }

        bTree[pos] = unsorted[i];
    }
}

void TestCreateBtreeByArr()
{
    printf("%s\n", __FUNCTION__);

    int unsorted[7] = { 30, 18, 16, 25, 34, 7, 31 };
    int bTree[16] = { 0 };

    CreateBTree(unsorted, sizeof(unsorted) / sizeof(int), bTree);

    for (int i = 1; i < sizeof(bTree) / sizeof(int); i++) {
        if (i > 1) {
            printf("  ");
        }
        printf("%d", bTree[i]);
    }

    printf("\n");
}
