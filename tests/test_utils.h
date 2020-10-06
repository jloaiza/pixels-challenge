#ifndef TEST_UTILS
#define TEST_UTILS

#include <stdint.h>

uint32_t *random_list(int length);

int random_number(int top);

void uint32_qsort(uint32_t *numbers, int length);

void print_uint32_array(uint32_t *numbers, int length);

#endif
