#include "unity.h"
#include "example.h"
#include "mock_library.h"


void setUp(void)
{
}

void tearDown(void)
{
}

void test_myfunction_expectCalledFewer()
{
    int i = 0;
    
    // This sets up the mock to expect a call to libFunction once only and make it return 1 whencalled.
    libFunction_ExpectAndReturn(0, 1);
    taskFunction(2);

    // Because we passed in 2 the libFunction will never be called and this test fails
}


void test_myfunction_expectAndCalledMore()
{
    int i = 0;
    
    // This sets up the mock to expect a call to libFunction with param 2 once only and make it 
    //    return 1 whencalled.
    libFunction_ExpectAndReturn(2, 1);
    taskFunction(1);
    taskFunction(1);

    // Because we called taskFunction twice with 1 as argument the libFunction is called twice 
    //    causing this test to fail.
}


void test_myfunction_expectAndCalledFewerIgnoreParam()
{
    int i = 0;
    
    // This sets up the mock to expect a call to libFunction with param 2 once only and make it 
    //    return 1 whencalled.
    libFunction_ExpectAnyArgsAndReturn(1);
    taskFunction(7);
    taskFunction(8);

    // Because we called taskFunction twice libFunction is called twice (ignoring the parameter)
    //    causing this test to fail.
}




