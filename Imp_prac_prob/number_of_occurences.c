#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

//input: Apple
//output: A:1 p:2 l:1 e:1

void num_of_occurences(char* s) {
    char freq[256] = {0};

    for(int i = 0; s[i] != '\0'; i++) {
        freq[(unsigned char)s[i]]++;
    }

    for(int i = 0; s[i] != '\0'; i++) {
        if(freq[(unsigned char)s[i]] != 0) {
            printf("%c:%d ", s[i], freq[(unsigned char)s[i]]);
            freq[(unsigned char)s[i]] = 0;
        }
    }
    printf("\n");
    return;
}

int main() {
    char s[] = "Apple";
    num_of_occurences(s);
    return 0;
}
