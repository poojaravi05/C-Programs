// Invert the alphabet's case

#include <stdio.h> 

int main() {
    for(char ch = 'a'; ch <= 'z'; ch++) {
        //converts uppercase to lowercase and viceversa
        char lower = ch ^ ' '; 
        printf("%c in inverted case: %c\n", ch, lower);
    }
    return 0;
}