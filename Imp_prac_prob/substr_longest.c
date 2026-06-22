/*
Given string S and an integer P. Return the number of longest substr by changing characters P times.
Input: S = "aaaabbbccccc", P = 2
Output: 7
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int longestSubstr(char* s, int p) {
    if(s == NULL) {
        return -1;
    }

    int len = strlen(s);
    int cnt = 1, max_len = 1;
    int i = 0, j = 0, k = 0, end = 0, pos = 0;
    bool marked = false;

    if(len <= 0) {
        return -1;
    }

    while(j <= len-1) {
        if(s[j] == s[j+1]) {
            if(marked == false) {
                k = j;
                marked = true;
            }
            cnt++;
        }
        else {
            if(cnt > max_len) {
                i = k;
                printf("i = %d\n", i);
                end = j;
                printf("end = %d\n", end);
                max_len = cnt;
                printf("max_len = %d\n", max_len);
            }
            cnt = 1;
            marked = false;
        }
        j++;
    }

    while(p > 0 && i > 0) {
        char c = s[i];
        s[--i] = c;
        p--;
        pos++;
    }

    while(p > 0 && end < len-1) {
        char c = s[end];
        s[++end] = c;
        p--;
        pos++;
    }

    printf("New s = %s\n", s);

    if(len >= (max_len + pos)) {
        return (max_len+pos);
    }
    else {
        return len;
    }
}

int main() {
    char s[] = "aaaabbbccccc";
    int p = 2, n = 0;
    
    n = longestSubstr(s, p);
    printf("Longest Substr = %d\n", n);

    return 0;
}
