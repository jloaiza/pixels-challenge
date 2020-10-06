#ifndef PIXEL_DATA
#define PIXEL_DATA

#include <stdint.h>

#define INVALID_PIXEL 1

#define HEIGHT_2D_OFFSET 15
#define WIDTH_2D_OFFSET 1

#define HEIGHT_3D_OFFSET 20
#define WIDTH_3D_OFFSET 11
#define DEPTH_3D_OFFSET 1

#define MASK_14_BITS 0X3FFF
#define MASK_10_BITS 0x3FF
#define MASK_9_BITS 0x1FF

#define HEIGHT_3D_MASK MASK_10_BITS
#define WIDTH_3D_MASK MASK_9_BITS
#define DEPTH_3D_MASK MASK_10_BITS

#define HEIGHT_2D_MASK MASK_14_BITS
#define WIDTH_2D_MASK MASK_14_BITS

#define IS_3D 0x40000000
#define IS_2D 0x80000000

uint32_t *PixelData(
    uint32_t *ptrHeight,
    uint32_t *ptrWidth,
    uint32_t *ptrDepth,
    uint32_t arraySize
);

uint32_t GetHeightFromPixel(uint32_t pixelData);
uint32_t GetWidthFromPixel(uint32_t pixelData);
uint32_t GetDepthFromPixel(uint32_t pixelData);
uint32_t Is2D(uint32_t pixelData);
uint32_t Is3D(uint32_t pixelData);

#endif
