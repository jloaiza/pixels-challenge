#include <stdio.h>

#include "sort.h"

void swap(uint32_t *elements, int index1, int index2) {
    if (index1==index2)
        return;
    uint32_t tmp = elements[index1];
    elements[index1] = elements[index2];
    elements[index2] = tmp;
}

void quickSort(uint32_t *elements, uint32_t length) {
    if (length <= 1){
        return;
    }
    uint32_t *pivotPtr = elements;
    int storeIndex = 1;
    for (int index=1; index < length; index++) {
        if (elements[storeIndex] <= *pivotPtr)
            swap(elements, storeIndex++, index);
    }
    swap(elements, 0, storeIndex-1);
    quickSort(elements, storeIndex-1);
    quickSort(elements + storeIndex + 1, length-storeIndex);
}
