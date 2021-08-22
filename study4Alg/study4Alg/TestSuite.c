#include <stdio.h>
#include "DLog.h"

extern void TestCreateBtreeByArr();
extern void TestCreateBtreeByList();

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
    DLogD(TAG, "<<< %s end", __FUNCTION__);

    printf("\n");
}
