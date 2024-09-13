// Convert lower case character to uppercase

#include <stdio.h> 

int main() {
    for(char ch = 'a'; ch <= 'z'; ch++) {
        char lower = ch & '_';
        printf("%c in upper case: %c\n", ch, lower);
    }
    return 0;
}