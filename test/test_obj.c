
#include <unity.h>
#include "obj.h"

uint8_t test_counter_a, test_counter_b;

void setUp(void) {

}

void tearDown(void) {

}

void init_func(void) {
    test_counter_a = 4;
    test_counter_b = 0;
}

uint8_t iter_func(void) {
    test_counter_a--;
    test_counter_b++;
    if (test_counter_a == 0)
        return 1;
    return 0;
}

uint8_t exit_func(void) {
    return 10;
}

void test_assign(void) {
    obj test_obj;
    test_obj.state = 10;
    test_obj.init = NULL;
    test_obj.step = NULL;
    test_obj.exit = NULL;
    TEST_ASSERT_EQUAL(test_obj.state, 10);
    TEST_ASSERT_EQUAL(test_obj.init, NULL);
    TEST_ASSERT_EQUAL(test_obj.step, NULL);
    TEST_ASSERT_EQUAL(test_obj.exit, NULL);
    assign(
        &test_obj,
        &init_func,
        &iter_func,
        &exit_func
    );
    TEST_ASSERT_EQUAL(test_obj.state, 0);
    TEST_ASSERT_EQUAL(test_obj.init, &init_func);
    TEST_ASSERT_EQUAL(test_obj.step, &iter_func);
    TEST_ASSERT_EQUAL(test_obj.exit, &exit_func);
}

void test_basic_functionality(void) {
    obj test_obj;
    assign(
        &test_obj,
        &init_func,
        &iter_func,
        &exit_func
    );
    test_counter_a = 255;
    test_counter_b = 255;
    uint8_t result;
    result = run(&test_obj);
    TEST_ASSERT_EQUAL(test_counter_a, 3);
    TEST_ASSERT_EQUAL(test_counter_b, 1);
    TEST_ASSERT_EQUAL(0, result);
    result = run(&test_obj);
    TEST_ASSERT_EQUAL(test_counter_a, 2);
    TEST_ASSERT_EQUAL(test_counter_b, 2);
    TEST_ASSERT_EQUAL(0, result);
    result = run(&test_obj);
    TEST_ASSERT_EQUAL(test_counter_a, 1);
    TEST_ASSERT_EQUAL(test_counter_b, 3);
    TEST_ASSERT_EQUAL(0, result);
    result = run(&test_obj);
    TEST_ASSERT_EQUAL(test_counter_a, 0);
    TEST_ASSERT_EQUAL(test_counter_b, 4);
    TEST_ASSERT_EQUAL(10, result);
    result = run(&test_obj);
    TEST_ASSERT_EQUAL(test_counter_a, 3);
    TEST_ASSERT_EQUAL(test_counter_b, 1);
    TEST_ASSERT_EQUAL(0, result);
}

void test_null_init(void) {
    obj test_obj;
    assign(
        &test_obj,
        NULL,
        &iter_func,
        &exit_func
    );
    test_counter_a = 6;
    test_counter_b = 3;
    uint8_t result;
    result = run(&test_obj);
    TEST_ASSERT_EQUAL(test_counter_a, 5);
    TEST_ASSERT_EQUAL(test_counter_b, 4);
    TEST_ASSERT_EQUAL(0, result);
}

void test_null_iter(void) {
    obj test_obj;
    assign(
        &test_obj,
        &init_func,
        NULL,
        &exit_func
    );
    test_counter_a = 255;
    test_counter_b = 255;
    uint8_t result;
    result = run(&test_obj);
    TEST_ASSERT_EQUAL(test_counter_a, 4);
    TEST_ASSERT_EQUAL(test_counter_b, 0);
    TEST_ASSERT_EQUAL(10, result);
    test_counter_a = 255;
    test_counter_b = 255;
    result = run(&test_obj);
    TEST_ASSERT_EQUAL(test_counter_a, 4);
    TEST_ASSERT_EQUAL(test_counter_b, 0);
    TEST_ASSERT_EQUAL(10, result);
}

void test_null_exit(void) {
    obj test_obj;
    assign(
        &test_obj,
        &init_func,
        &iter_func,
        NULL
    );
    test_counter_a = 255;
    test_counter_b = 255;
    uint8_t result;
    result = run(&test_obj);
    TEST_ASSERT_EQUAL(test_counter_a, 3);
    TEST_ASSERT_EQUAL(test_counter_b, 1);
    TEST_ASSERT_EQUAL(0, result);
    result = run(&test_obj);
    TEST_ASSERT_EQUAL(test_counter_a, 2);
    TEST_ASSERT_EQUAL(test_counter_b, 2);
    TEST_ASSERT_EQUAL(0, result);
    result = run(&test_obj);
    TEST_ASSERT_EQUAL(test_counter_a, 1);
    TEST_ASSERT_EQUAL(test_counter_b, 3);
    TEST_ASSERT_EQUAL(0, result);
    result = run(&test_obj);
    TEST_ASSERT_EQUAL(test_counter_a, 0);
    TEST_ASSERT_EQUAL(test_counter_b, 4);
    TEST_ASSERT_EQUAL(0, result);
    result = run(&test_obj);
    TEST_ASSERT_EQUAL(test_counter_a, 3);
    TEST_ASSERT_EQUAL(test_counter_b, 1);
    TEST_ASSERT_EQUAL(0, result);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_assign);
    RUN_TEST(test_basic_functionality);
    RUN_TEST(test_null_init);
    RUN_TEST(test_null_iter);
    RUN_TEST(test_null_exit);
    return UNITY_END();
}
