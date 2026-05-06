/*
Given 2 strings, s1 and s2. Find:
1. the number of occurences of s1 in s2
2. The indices where s1 starts in s2 in each occurence.

Eg: s1 = "xy", s2 = "axybxy" -> output: occurences = 2, indices = 1 and 4
Eg: s1 = "xx", s2 = "axxxxbxx" -> output: occurences = 4, indices = 1, 2, 3, and 6
*/

#include <stdio.h>
#include <string.h>

int findString(char* s1, char* s2) {
	int cnt = 0;
	int len1 = strlen(s1), len2 = strlen(s2);
	if(len2 < len1) {
		return -1;
	}
	
	for(int i = 0; i <= len2 - len1; i++) {
        int j;
        for(j = 0; j < len1; j++) {
            if(s1[j] != s2[i+j]) {
                break;
            }
        }

		if(j == len1) {
            printf("%d ", i);
            cnt++;
        }
	}
	return cnt;
}

int main() {
    //char s1[] = "xy";
    //char s2[] = "axybxy";

    char s1[] = "xx";
    char s2[] = "axxxxbxx";

    int count = findString(s1, s2);
    printf("\nNumber of occurrences: %d\n", count);
    return 0;
}
