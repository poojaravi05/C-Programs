#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*
 * Fast memcpy implementation:
 * 1. Align destination to 8 bytes
 * 2. Copy 8 bytes at a time
 * 3. Copy remaining bytes
 *
 * NOTE:
 * - Does NOT handle overlapping memory (like memcpy).
 * - For overlap-safe version use memmove logic.
 */
void* fast_memcpy(void* dest, const void* src, size_t n)
{
    uint8_t* d8 = (uint8_t*)dest;
    const uint8_t* s8 = (const uint8_t*)src;

    // Step 1: Align destination to 8-byte boundary
    while (n > 0 && ((uintptr_t)d8 % 8 != 0))
    {
        *d8++ = *s8++;
        n--;
    }

    // Step 2: Copy 8 bytes at a time
    uint64_t* d64 = (uint64_t*)d8;
    const uint64_t* s64 = (const uint64_t*)s8;

    while (n >= 8)
    {
        *d64++ = *s64++;
        n -= 8;
    }

    // Step 3: Copy remaining bytes
    d8 = (uint8_t*)d64;
    s8 = (const uint8_t*)s64;

    while (n--)
    {
        *d8++ = *s8++;
    }

    return dest;
}

/* Utility function to print byte buffer */
void print_buffer(const char* label, const uint8_t* buf, size_t size)
{
    printf("%s: ", label);
    for (size_t i = 0; i < size; i++)
    {
        printf("%02X ", buf[i]);
    }
    printf("\n");
}

int main()
{
    printf("===== Test Case 1: Simple Byte Copy =====\n");

    uint8_t src1[16]  = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    uint8_t dest1[16] = {0};

    fast_memcpy(dest1, src1, 16);

    print_buffer("Source", src1, 16);
    print_buffer("Dest  ", dest1, 16);


    printf("\n===== Test Case 2: Non-Multiple of 8 =====\n");

    uint8_t src2[13]  = {10,20,30,40,50,60,70,80,90,100,110,120,130};
    uint8_t dest2[13] = {0};

    fast_memcpy(dest2, src2, 13);

    print_buffer("Source", src2, 13);
    print_buffer("Dest  ", dest2, 13);

    return 0;
}
