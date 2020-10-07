#include <unity.h>

#include <time.h>
#include <stdlib.h>

#include "test_utils.h"

void set_random_seed(void) {
    time_t t;
    srand((unsigned) time(&t));
}

uint32_t *random_list_aux(int length, int top, int include_zeros) {
    uint32_t *list = (uint32_t *)malloc(sizeof(uint32_t) * length);

    for (int index=0; index < length; index++){

        int number = (uint32_t)(rand() % top);
        while (!include_zeros && number == 0)
            number = (uint32_t)(rand() % top);

        list[index] = number;
    }
    return list;
}

uint32_t *random_list(int length){
    return random_list_with_top(length, 10000);
}

uint32_t *random_list_with_top(int length, int top){
    return random_list_aux(length, top, 1);
}

uint32_t *random_list_with_top_no_zeros(int length, int top){
    return random_list_aux(length, top, 0);
}

int random_number(int top){
    return (int)(rand()%top);
}

int random_number_not_zero(int top) {
    int number = (int)(rand()%top);
    while(number == 0)
        number = (int)(rand()%top);
    return number;
}

int _cmp_func (const void * a, const void * b) {
    // remove the most significate 2 bits because that affects the comparison
    // result.
    uint32_t uint_a = (*(uint32_t*)a << 2) >> 2;
    uint32_t uint_b = (*(uint32_t*)b << 2) >> 2;
    return (int)(uint_a - uint_b);
}

void uint32_qsort(uint32_t *numbers, int length){
    qsort(numbers, length, sizeof(uint32_t), _cmp_func);
}

void print_uint32_array(uint32_t *numbers, int length) {
    printf("[");
    for (int index=0; index < length; index++) {
        printf("%#08x", numbers[index]);
        if (index+1 < length) {
            printf(" ,");
        }
    }
    printf("]\n");
}
