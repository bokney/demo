
#include <unity.h>
#include "state_manager.h"

int add(int a, int b) {
    return a + b;
}

void setUp(void) {

}

void tearDown(void) {

}

void test_addition(void) {
    TEST_ASSERT_EQUAL(5, add(2, 3));
}

// void test_

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_addition);
    return UNITY_END();
}
