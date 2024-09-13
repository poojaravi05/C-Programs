#include <stdio.h>

int main() {
    int x = 4;
    int res = -~x;

    // -x = (~x) + 1 (two's complement)
    // -~x = x + 1

    printf("%d + 1 = %d", x, res);

    return 0;
}
