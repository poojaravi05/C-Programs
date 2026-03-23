#include <stdio.h>
#include <stdint.h>

uint32_t reverse_power_of_two(uint32_t n) {
    int pos = 0;

    // find position of the only set bit
    while ((n & 1) == 0) {
        n >>= 1;
        pos++;
    }

    // place bit at reversed position (32-bit)
    return (1U << (31 - pos));
}

int main() {
    uint32_t n = 8; // 00000000 00000000 00000000 00001000

    uint32_t res = reverse_power_of_two(n);

    printf("Result: %u\n", res);
    return 0;
}
