#include <stdio.h>
#include <stdint.h>

uint32_t add_binary(uint32_t a, uint32_t b) {
    uint32_t result = 0;
    uint32_t carry = 0;

    for (int i = 0; i < 32; i++) {
        uint32_t bit_a = (a >> i) & 1;
        uint32_t bit_b = (b >> i) & 1;

        uint32_t sum = bit_a ^ bit_b ^ carry;
        carry = (bit_a & bit_b) | (bit_a & carry) | (bit_b & carry);

        result |= (sum << i);
    }

    return result;
}

int main() {
    uint32_t a = 5;   // 0101
    uint32_t b = 3;   // 0011

    uint32_t sum = add_binary(a, b);

    return 0;
}
