#Add 2 numbers in binary format like manually adding bits

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

/*
int add_binary(int n1, int n2) {
    int carry = 0;
    int res = 0;
    int pos = 0;

    while(n1 || n2 || carry) {
        int bit1 = n1 & 1;
        int bit2 = n2 & 1;

        int sum = bit1 + bit2 + carry;

        int result_bit = sum % 2;
        carry = sum / 2;

        res |= (result_bit << pos);

        pos++;

        n1 >>= 1;
        n2 >>= 1;
    }

    return res;
}
*/

int main() {
    uint32_t a = 5;   // 0101
    uint32_t b = 3;   // 0011

    uint32_t sum = add_binary(a, b);

    return 0;
}
