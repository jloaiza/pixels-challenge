#ifndef TEST_UTILS
#define TEST_UTILS

#include <stdint.h>

uint32_t *random_list_with_top(int length, int top);
uint32_t *random_list_with_top_no_zeros(int length, int top);
uint32_t *random_list(int length);

int random_number(int top);

int random_number_not_zero(int top);

void uint32_qsort(uint32_t *numbers, int length);

void print_uint32_array(uint32_t *numbers, int length);

void set_random_seed(void);

#endif
