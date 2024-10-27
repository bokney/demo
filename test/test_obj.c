
#include <unity.h>
#include "obj.h"

uint8_t test_counter_a, test_counter_b;

void setUp(void) {

}

void tearDown(void) {

}

void test_init(void) {
    test_counter_a = 4;
    test_counter_b = 0;
}

uint8_t test_iter(void) {
    test_counter_a--;
    test_counter_b++;
    if (test_counter_a == 0)
        return 1;
    return 0;
}

uint8_t test_exit(void) {
    return 10;
}

void test_basic_functionality(void) {
    obj test_obj;
    assign(
        &test_obj,
        &test_init,
        &test_iter,
        &test_exit
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
        &test_iter,
        &test_exit
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
        &test_init,
        NULL,
        &test_exit
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
        &test_init,
        &test_iter,
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
    RUN_TEST(test_basic_functionality);
    RUN_TEST(test_null_init);
    RUN_TEST(test_null_iter);
    RUN_TEST(test_null_exit);
    return UNITY_END();
}
