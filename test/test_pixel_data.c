
#include <unity.h>

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include <pixels/pixel_data.h>

#include "test_utils.h"

// This will override the pixel_data.h const value, this is in case the header
// value is wrong
#define INVALID_PIXEL 0x01

// defined at pixel_data.c
uint32_t onePixelData(uint32_t *height, uint32_t *width, uint32_t *depth);

// utils

void check_invalids(uint32_t *pixel_data, int length, int invalids) {
    int no_more_invalids = 0;
    int invalid_count = 0;
    for (int index=0; index < length; index++) {

        if (pixel_data[index] == INVALID_PIXEL) {
            invalid_count++;
            char msg[] = "Missplaced invalid value after non-invalid ones.";
            TEST_ASSERT_FALSE_MESSAGE(no_more_invalids, msg);

        } else {
            no_more_invalids = 1;
        }
    }

    TEST_ASSERT_EQUAL_INT_MESSAGE(
        invalids, invalid_count, "Expected invalid count mismatch."
    );
}

void inject_invalid_pixels(
    uint32_t *depth_list, int length, int invalid_number
) {
    for (int invalids=0; invalids < invalid_number; invalids++) {

        int random_index = random_number(length);
        while(depth_list[random_index] == 0) {
            random_index = random_number(length);
        }
        depth_list[random_index] = 0;
    }
}

uint32_t *generate_list_full_of_ones(int length) {
    uint32_t *list = (uint32_t *)malloc(sizeof(uint32_t)*length);
    for (int index=0; index < length; index++)
        list[index] = 1;
    return list;
}


// 3D tests

void test_one_3d_pixel_data(void) {
    uint32_t height = 5;
    uint32_t width = 10;
    uint32_t depth = 2;

    uint32_t result = onePixelData(&height, &width, &depth);

    uint32_t expected_result = 0xC0505004;
    TEST_ASSERT_EQUAL_UINT32(expected_result, result);
}

void test_get_3d_height(void) {
    uint32_t pixel_data = 0xC0505004;

    uint32_t height = GetHeightFrom3DPixel(pixel_data);

    uint32_t expected_height = 5;
    TEST_ASSERT_EQUAL_UINT32(expected_height, height);
}

void test_get_3d_width(void) {
    uint32_t pixel_data = 0xC0505004;

    uint32_t width = GetWidthFrom3DPixel(pixel_data);

    uint32_t expected_width = 10;
    TEST_ASSERT_EQUAL_UINT32(expected_width, width);
}

void test_get_3d_depth(void) {
    uint32_t pixel_data = 0xC0505004;

    uint32_t depth = GetDepthFrom3DPixel(pixel_data);

    uint32_t expected_depth = 2;
    TEST_ASSERT_EQUAL_UINT32(expected_depth, depth);
}

void test_is_3d_true(void) {
    uint32_t pixel_data = 0xC0505004;

    TEST_ASSERT_TRUE(Is3D(pixel_data));
}

void test_is_3d_false(void) {
    uint32_t pixel_data = 0x00505004;

    TEST_ASSERT_FALSE(Is3D(pixel_data));
}

void test_raw_to_3d_pixel(void) {
    for(int test=0; test<100; test++){
        int length = random_number_not_zero(100);
        uint32_t *height_list = random_list_with_top(length, HEIGHT_3D_MASK);
        uint32_t *width_list = random_list_with_top(length, WIDTH_3D_MASK);
        uint32_t *depth_list = random_list_with_top_no_zeros(
            length, DEPTH_3D_MASK
        );

        int invalids = random_number(length);
        inject_invalid_pixels(depth_list, length, invalids);

        uint32_t *all_pixels = PixelData(
            height_list, width_list, depth_list, length
        );

        uint32_t *pixels_copy = (uint32_t *)malloc(sizeof(uint32_t) * length);
        if (pixels_copy == NULL) {
            printf("Can't allocate more memory\n");
            exit(1);
        }
        memcpy(pixels_copy, all_pixels, sizeof(uint32_t)*length);
        uint32_qsort(pixels_copy, length);

        check_invalids(all_pixels, length, invalids);
        TEST_ASSERT_EQUAL_UINT32_ARRAY(pixels_copy, all_pixels, length);

        free(height_list);
        free(width_list);
        free(depth_list);
        free(pixels_copy);
    }
}


// 2D tests

void test_one_2d_pixel_data(void) {
    uint32_t height = 10;
    uint32_t width = 6;
    uint32_t depth = 1;

    uint32_t result = onePixelData(&height, &width, &depth);

    uint32_t expected_result = 0x0005000C;
    TEST_ASSERT_EQUAL_UINT32(expected_result, result);
}

void test_get_2d_height(void) {
    uint32_t pixel_data = 0x0005000C;

    uint32_t height = GetHeightFrom2DPixel(pixel_data);

    uint32_t expected_height = 10;
    TEST_ASSERT_EQUAL_UINT32(expected_height, height);
}

void test_get_2d_width(void) {
    uint32_t pixel_data = 0x0005000C;

    uint32_t width = GetWidthFrom2DPixel(pixel_data);

    uint32_t expected_width = 6;
    TEST_ASSERT_EQUAL_UINT32(expected_width, width);
}

void test_is_2d_true(void) {
    uint32_t pixel_data = 0x00505004;

    TEST_ASSERT_TRUE(Is2D(pixel_data));
}

void test_is_2d_false(void) {
    uint32_t pixel_data = 0xC0505004;

    TEST_ASSERT_FALSE(Is2D(pixel_data));
}

void test_raw_to_2d_pixel(void) {
    for(int test=0; test<100; test++){
        int length = random_number_not_zero(100);
        uint32_t *height_list = random_list_with_top(length, HEIGHT_3D_MASK);
        uint32_t *width_list = random_list_with_top(length, WIDTH_3D_MASK);
        uint32_t *depth_list = generate_list_full_of_ones(length);

        int invalids = random_number(length);
        inject_invalid_pixels(depth_list, length, invalids);

        uint32_t *all_pixels = PixelData(
            height_list, width_list, depth_list, length
        );

        uint32_t *pixels_copy = (uint32_t *)malloc(sizeof(uint32_t) * length);
        if (pixels_copy == NULL) {
            printf("Can't allocate more memory\n");
            exit(1);
        }
        memcpy(pixels_copy, all_pixels, sizeof(uint32_t)*length);
        uint32_qsort(pixels_copy, length);

        check_invalids(all_pixels, length, invalids);
        TEST_ASSERT_EQUAL_UINT32_ARRAY(pixels_copy, all_pixels, length);

        free(height_list);
        free(width_list);
        free(depth_list);
        free(pixels_copy);
    }
}

// invalid pixel tests

void test_one_invalid_pixel_data(void) {
    uint32_t height = 10;
    uint32_t width = 6;
    uint32_t depth = 0;

    uint32_t result = onePixelData(&height, &width, &depth);

    uint32_t expected_result = 0x1;
    TEST_ASSERT_EQUAL_UINT32(expected_result, result);
}

void setUp (void) {
    set_random_seed();
}

void tearDown (void) {}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_one_3d_pixel_data);
    RUN_TEST(test_get_3d_height);
    RUN_TEST(test_get_3d_width);
    RUN_TEST(test_get_3d_depth);
    RUN_TEST(test_is_3d_true);
    RUN_TEST(test_is_3d_false);
    RUN_TEST(test_raw_to_3d_pixel);
    RUN_TEST(test_one_2d_pixel_data);
    RUN_TEST(test_get_2d_height);
    RUN_TEST(test_get_2d_width);
    RUN_TEST(test_is_2d_true);
    RUN_TEST(test_is_2d_false);
    RUN_TEST(test_raw_to_2d_pixel);
    RUN_TEST(test_one_invalid_pixel_data);

    return UNITY_END();
}
