#include "DLog.h"

extern int TestCreateBtreeByArr();
extern int TestCreateBtreeByList();

#define TAG "TestSuite"

void TestSuite()
{
    DLogD(TAG, ">>> %s begin", __FUNCTION__);

    TestCreateBtreeByArr();
    TestCreateBtreeByList();

    DLogD(TAG, "<<< %s end", __FUNCTION__);
}