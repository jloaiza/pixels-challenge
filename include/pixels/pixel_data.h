#ifndef PIXEL_DATA
#define PIXEL_DATA

#include <stdint.h>

#define INVALID_PIXEL 0x00000001

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

#define TYPE_MASK 0xC0000000
#define IS_3D 0xC0000000
#define IS_2D 0x00000000

uint32_t *PixelData(
    uint32_t *ptrHeight,
    uint32_t *ptrWidth,
    uint32_t *ptrDepth,
    uint32_t arraySize
);

uint32_t GetHeightFrom3DPixel(uint32_t pixelData);
uint32_t GetWidthFrom3DPixel(uint32_t pixelData);
uint32_t GetDepthFrom3DPixel(uint32_t pixelData);
uint32_t Is3D(uint32_t pixelData);

uint32_t GetHeightFrom2DPixel(uint32_t pixelData);
uint32_t GetWidthFrom2DPixel(uint32_t pixelData);
uint32_t Is2D(uint32_t pixelData);

#endif
