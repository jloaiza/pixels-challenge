#include <stdio.h>

#include "sort.h"

void swap(uint32_t *elements, int index1, int index2) {
    if (index1==index2)
        return;
    uint32_t tmp = elements[index1];
    elements[index1] = elements[index2];
    elements[index2] = tmp;
}

void quickSort(uint32_t *elements, int length) {
    if (length <= 1){
        return;
    }
    uint32_t *pivotPtr = elements;
    int storeIndex = 1;
    for (int index=1; index < length; index++) {
        if (elements[index] < *pivotPtr)
            swap(elements, storeIndex++, index);
    }
    int lastIndex = storeIndex - 1;
    swap(elements, 0, lastIndex);
    quickSort(elements, lastIndex);
    quickSort(elements + storeIndex, length-storeIndex);
}
