#include <stdio.h>
#include <string.h>

char* reverse_string_word(char* s) {
    int n = strlen(s);
    int i = 0, j = n-1;
    char temp;
    /*
    //reverse entire string
    while(i < j) {
        temp = s[i];
        s[i++] = s[j];
        s[j--] = temp;
    }
    */

    i = 0, j = 0;
    int r = 0;
    while(j < n) {
        //skip spaces if any
        while(j < n && s[j] == ' ') {
            j++;
        }
        i = j;
        //find a word
        while(j < n && s[j] != ' ') {
            j++;
        }

        if(i < j) {
            //add space between words
            if(r > 0) {
                s[r++] = ' ';
            }

            int start = r;
            int k = i;
            //copy the reversed word into right place
            while(k < j) {
                s[r++] = s[k++];
            }

            int end = r-1;
            //reverse word
            while(start < end) {
                temp = s[start];
                s[start++] = s[end];
                s[end--] = temp;
            }
        }
    }
    s[r] = '\0';
    return s;

}

int main() {
    /*
    char words[] = "  hello world  ";
    char* res = reverse_string_word(words); //world hello
    printf("Res = %s\n", res);
    */
    char words[] = "  hello world  ";
    char* res = reverse_string_word(words); //olleh dlrow
    printf("Res = %s\n", res);

    return 0;
}
