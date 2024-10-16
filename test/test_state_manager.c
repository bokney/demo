
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

void test_a(void) {
    state test_state;
    test_state.step = 0;
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_addition);
    return UNITY_END();
}
