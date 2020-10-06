
#include <unity.h>

#include <stdlib.h>
#include <string.h>

#include "test_utils.h"
#include "../src/sort.h"

void test_quicksort_no_elements() {
    uint32_t elements[] = {};
    quickSort(elements, 0);
}

void test_quicksort_one_element() {
    uint32_t elements[] = {7};
    quickSort(elements, 1);
    TEST_ASSERT_EQUAL_UINT32(7, elements[0]);
}

void test_quicksort_two_unordered_elements() {
    uint32_t elements[] = {7, 3};
    quickSort(elements, 2);
    TEST_ASSERT_EQUAL_UINT32(3, elements[0]);
    TEST_ASSERT_EQUAL_UINT32(7, elements[1]);
}

void test_quicksort_two_ordered_elements() {
    uint32_t elements[] = {3, 7};
    quickSort(elements, 2);
    TEST_ASSERT_EQUAL_UINT32(3, elements[0]);
    TEST_ASSERT_EQUAL_UINT32(7, elements[1]);
}

void test_quicksort_two_same_elements() {
    uint32_t elements[] = {7, 7};
    quickSort(elements, 2);
    TEST_ASSERT_EQUAL_UINT32(7, elements[0]);
    TEST_ASSERT_EQUAL_UINT32(7, elements[1]);
}

void test_quicksort_five_same_elements() {
    uint32_t elements[] = {7, 7, 7, 7, 7};
    quickSort(elements, 5);
    TEST_ASSERT_EQUAL_UINT32(7, elements[0]);
    TEST_ASSERT_EQUAL_UINT32(7, elements[1]);
    TEST_ASSERT_EQUAL_UINT32(7, elements[2]);
    TEST_ASSERT_EQUAL_UINT32(7, elements[3]);
    TEST_ASSERT_EQUAL_UINT32(7, elements[4]);
}

void test_ordered_elements() {
    for(int test=0; test<100; test++){
        int length = random_number(100);
        uint32_t *elements = random_list(length);
        uint32_t *expected_elements =
            (uint32_t *)malloc(sizeof(uint32_t)*length);
        uint32_qsort(elements, length);
        memcpy(expected_elements, elements, sizeof(uint32_t)*length);

        print_uint32_array(expected_elements, length);
        print_uint32_array(elements, length);

        quickSort(elements, length);


        TEST_ASSERT_EQUAL_UINT32_ARRAY(expected_elements, elements, length);
    }
}

void test_unordered_elements() {
    for(int test=0; test<100; test++){
        int length = random_number(100);
        uint32_t *elements = random_list(length);
        uint32_t *expected_elements = malloc(sizeof(uint32_t)*length);
        memcpy(expected_elements, elements, sizeof(uint32_t)*length);
        uint32_qsort(expected_elements, length);

        quickSort(elements, length);

        TEST_ASSERT_EQUAL_UINT32_ARRAY(expected_elements, elements, length);
    }
}

void setUp (void) {}

void tearDown (void) {}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_quicksort_no_elements);
    RUN_TEST(test_quicksort_one_element);
    RUN_TEST(test_quicksort_two_unordered_elements);
    RUN_TEST(test_quicksort_two_ordered_elements);
    RUN_TEST(test_quicksort_two_same_elements);
    RUN_TEST(test_quicksort_five_same_elements);
    RUN_TEST(test_ordered_elements);
    RUN_TEST(test_unordered_elements);

    return UNITY_END();
}
