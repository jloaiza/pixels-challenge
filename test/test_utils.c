#include <unity.h>

#include <time.h>
#include <stdlib.h>

#include "test_utils.h"

uint32_t *random_list(int length){
    time_t t;
    srand((unsigned) time(&t));
    uint32_t *list = (uint32_t *)malloc(sizeof(uint32_t)*length);
    for (int index=0; index < length; index++){
        list[index] = (uint32_t)(rand()%10000);
    }
    return list;
}

int random_number(int top){
    time_t t;
    srand((unsigned) time(&t));
    return (int)(rand()%top);
}

int _cmp_func (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void uint32_qsort(uint32_t *numbers, int length){
    qsort(numbers, length, sizeof(uint32_t), _cmp_func);
}

void print_uint32_array(uint32_t *numbers, int length) {
    printf("[");
    for (int index=0; index < length; index++) {
        printf("%d", numbers[index]);
        if (index+1 < length) {
            printf(" ,");
        }
    }
    printf("]\n");
}
