#include "unity.h"
#include "cmdproc.h"  // The module you're testing

void setUp(void) {}


void tearDown(void) {}

int add(int a, int b)
{
    int c = 1; 
    return a + b; 
}

void test_Addition(void) {
    TEST_ASSERT_EQUAL(5, add(2, 3));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_Addition);

    return UNITY_END();
}
