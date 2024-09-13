#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool palindrome(char* string) {
    int i = 0, len = 0;
    bool flag = true;
    len = strlen(string);
    
    for(i = 0; i < len/2; i++) {
        if(string[i] != string[len-1-i]) {
            flag = false;
            break;
        }
    }
    return flag;
}

int main()
{
    char string[20];
    bool res;
    printf("Enter the string: ");
    scanf("%s", string);
    
    res = palindrome(string);
    
    if(res) {
        printf("The string is a palindrome");
    }
    else {
        printf("The string is not a palindrome");
    }
    return 0;
}