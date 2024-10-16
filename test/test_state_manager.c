
#include <unity.h>
#include "state_manager.h"

uint8_t test_counter_a, test_counter_b;

void setUp(void) {
    // test_counter_a = 10;
    // test_counter_b = 10;
}

void tearDown(void) {

}

/*
    things to test...
    - init and first iter trigger same invocation of runStep
    - last iter and exit trigger same invocation of runStep
    - correct amount of iter iterations
    - handover to next state
*/

void test_init(void) {
    test_counter_a = 4;
    test_counter_b = 0;
    printf("WHAT?\n");
}

uint8_t test_iter(void) {
    test_counter_a--;
    if (test_counter_a == 0)
        return 1;
    return 0;
}

uint8_t test_exit(void) {
    test_counter_b++;
    return 0;
}

void test_init_and_first_iter_trigger_on_same_runstep_invocation(void) {
    state test_state;
    test_state.step = 0;
    test_state.init = &test_init;
    test_state.iter = &test_iter;
    test_state.exit = NULL;
    runState(&test_state);
    TEST_ASSERT_EQUAL(test_counter_a, 3);
    TEST_ASSERT_EQUAL(test_counter_b, 0);
    runState(&test_state);
    TEST_ASSERT_EQUAL(test_counter_a, 2);
    TEST_ASSERT_EQUAL(test_counter_b, 0);
    runState(&test_state);
    TEST_ASSERT_EQUAL(test_counter_a, 1);
    TEST_ASSERT_EQUAL(test_counter_b, 0);
    runState(&test_state);
    TEST_ASSERT_EQUAL(test_counter_a, 0);
    TEST_ASSERT_EQUAL(test_counter_b, 0);
    runState(&test_state);
    TEST_ASSERT_EQUAL(test_counter_a, 3);
    TEST_ASSERT_EQUAL(test_counter_b, 0);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_init_and_first_iter_trigger_on_same_runstep_invocation);
    return UNITY_END();
}
