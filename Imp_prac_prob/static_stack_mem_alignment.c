#include <stdio.h>
#include <stdalign.h>
#include <stdint.h>

//alignas(16) uint8_t buffer[sz]; // 16 bytes

//alignas(uint32_t) uint8_t buff[sz]; // 4 bytes

struct S {
    short f[3];
    //int i;
    char c;
} __attribute__ ((aligned (8)));

// In C, alignas won't work on a struct definition. You need to align the first member.
// Alternatively, the aligned attribute will work on the struct definition.
typedef struct my_struct
{
    alignas(16) uint32_t x;
    uint32_t buffer[4];
}my_struct;

// You could also just align the variable declaration, rather than the first member.
// But you would have to do this every time if alignment mattered for every object.
alignas(32) struct my_struct an_object;

// This example uses alignas on a "later" struct member. The outcome here is:
// - every object of type data will be 128-byte aligned
// - member cacheline will also be 128-byte aligned
// - there will be padding between member x and member cacheline
// - overall size of the object increases from 132 bytes to 256 bytes
struct data {
  //uint32_t x;
  alignas(128) char cacheline[128]; // over-aligned array of char, not array of over-aligned chars
  uint32_t x;
};

int main()
{
    printf("sizeof(struct S) = %ld\n", sizeof(struct S));
    printf("sizeof(my_struct) = %ld\n", sizeof(my_struct));
    printf("sizeof(struct data) = %ld\n", sizeof(struct data));

    return 0;
}