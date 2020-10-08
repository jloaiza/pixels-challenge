#include <stdlib.h>
#include <stdio.h>

#include <pixels/pixel_data.h>
#include <pixels/error_codes.h>

#include "sort.h"

// Convert to pixel data functions

uint32_t onePixelData(uint32_t *height, uint32_t *width, uint32_t *depth) {
    if (*depth == 0) {
        return INVALID_PIXEL;

    } else if (*depth == 1) {
        return
            IS_2D
            | (*height & HEIGHT_2D_MASK) << HEIGHT_2D_OFFSET
            | (*width  & WIDTH_2D_MASK ) << WIDTH_2D_OFFSET;

    } else {
        return
            IS_3D
            | (*height & HEIGHT_3D_MASK) << HEIGHT_3D_OFFSET
            | (*width  & WIDTH_3D_MASK ) << WIDTH_3D_OFFSET
            | (*depth  & DEPTH_3D_MASK ) << DEPTH_3D_OFFSET;
    }
}

uint32_t *PixelData(
    uint32_t *ptrHeight,
    uint32_t *ptrWidth,
    uint32_t *ptrDepth,
    uint32_t arraySize
) {
    uint32_t * data = malloc(sizeof(uint32_t *) * arraySize);
    if (data == NULL) {
        printf("Error: Couldn't allocate memory for the new pixels array.");
        exit(OUT_OF_MEMORY_ERROR);
    }

    for (int index=0; index < (int)arraySize; index++) {
        *(data+index) = onePixelData(
            ptrHeight + index,
            ptrWidth + index,
            ptrDepth + index
        );
    }

    // This quick sort will only work if the array elemnts are of the same
    // pixel type. 3D pixels to 2D pixels comparison will be affected by the
    // "type" bits and will not fullfill the specification.
    // Modify the quickSort function to support this scenario.
    quickSort(data, arraySize);

    return data;
}

// 3D Functions

uint32_t GetHeightFrom3DPixel(uint32_t pixelData) {
    return (pixelData >> HEIGHT_3D_OFFSET) & HEIGHT_3D_MASK;
}

uint32_t GetWidthFrom3DPixel(uint32_t pixelData) {
    return (pixelData >> WIDTH_3D_OFFSET) & WIDTH_3D_MASK;
}

uint32_t GetDepthFrom3DPixel(uint32_t pixelData) {
    return (pixelData >> DEPTH_3D_OFFSET) & DEPTH_3D_MASK;
}

uint32_t Is3D(uint32_t pixelData) {
    return (pixelData & TYPE_MASK) == IS_3D;
}

// 2D Functions

uint32_t GetHeightFrom2DPixel(uint32_t pixelData) {
    return (pixelData >> HEIGHT_2D_OFFSET) & HEIGHT_2D_MASK;
}

uint32_t GetWidthFrom2DPixel(uint32_t pixelData) {
    return (pixelData >> WIDTH_2D_OFFSET) & WIDTH_2D_MASK;
}

uint32_t Is2D(uint32_t pixelData) {
    return (pixelData & TYPE_MASK) == IS_2D;
}
