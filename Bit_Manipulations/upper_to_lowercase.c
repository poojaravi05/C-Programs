// Convert uppercase character to lower case

#include <stdio.h> 

int main() {
    for(char ch = 'A'; ch <= 'Z'; ch++) {
        char lower = ch | ' ';
        printf("%c in lower case: %c\n", ch, lower);
    }
    return 0;
}