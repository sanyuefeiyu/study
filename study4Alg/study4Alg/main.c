#define CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#include "DBase.h"

extern void TestSuite();

int main(int argc, char **argv)
{
    _CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);

    DBaseInit(DLOG_D, DLOG_ALL, "d:\\log.txt");

    TestSuite();

    return 0;
}
