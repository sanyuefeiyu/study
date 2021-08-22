#include <stdio.h>
#include "DLog.h"

extern void TestCreateBtreeByArr();
extern void TestCreateBtreeByList();
extern void TestMaxPathSum();
extern void TestCreateTreeByPreAndIn();

#define TAG "TestSuite"

void TestSuite()
{
    printf("\n");
    DLogD(TAG, ">>> %s begin", __FUNCTION__);

    printf("\n");
    TestCreateBtreeByArr();

    printf("\n");
    TestCreateBtreeByList();

    printf("\n");
    TestMaxPathSum();

    printf("\n");
    TestCreateTreeByPreAndIn();

    printf("\n");
    DLogD(TAG, "<<< %s end", __FUNCTION__);

    printf("\n");
}
