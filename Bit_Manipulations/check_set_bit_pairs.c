//check if the number has adjacent set bits in it(11). Return if pair found
//eg: n = 6 -> 0110 -> true

#include <stdio.h>

bool check_set_bits_pairs(int n) {
    return (n & (n << 1));
}

int main()
{
    int n = 6;
    bool res = check_set_bits_pairs(n);

    return 0;
}
