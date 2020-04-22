#include "unity.h"
#include "mock_example.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_myfunction_this_call_taskFunction()
{
    int i = 0;
    
    // This sets up the mock to call taskFunction and make it return 1 instead of 8
    taskFunction_ExpectAndReturn(7, 1);

    taskFunction(7);

    TEST_ASSERT(i == 1);
}


