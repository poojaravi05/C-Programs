#include <stdio.h>
#include <limits.h>

int my_atoi(char* str) {
    int i = 0, res = 0, sign = 1;

    // Skip leading spaces
    while (str[i] == ' ') i++;

    // Handle sign
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    // Process digits
    for (; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            break;  // stop at non-digit
        }

        int val = str[i] - '0';

        // Check overflow
        if (res > (INT_MAX - val) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        res = res * 10 + val;
    }

    return sign * res;
}

int main() {
    printf("%d\n", my_atoi("123"));        // 123
    printf("%d\n", my_atoi("123ABC"));     // 123
    printf("%d\n", my_atoi("ABC"));        // 0
    printf("%d\n", my_atoi("2147483648")); // INT_MAX
    printf("%d\n", my_atoi("-2147483649"));// INT_MIN
    return 0;
}
