#include "unity.h"
#include "example.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_taskFunction_should_return_1()
{
    int i = taskFunction(7);

    TEST_ASSERT(i == 1);
}


