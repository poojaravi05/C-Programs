/*
 * Complete implementation of memcmp in C
 *
 * Compares the first n bytes of two memory blocks.
 *
 * Return value:
 *   < 0  if s1 < s2
 *   = 0  if s1 == s2
 *   > 0  if s1 > s2
 */

#include <stdio.h>
#include <stddef.h>

int my_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *p1 = (const unsigned char *)s1;
    const unsigned char *p2 = (const unsigned char *)s2;

    while (n--)
    {
        if (*p1 != *p2)
        {
            return (*p1 - *p2);
        }

        p1++;
        p2++;
    }

    return 0;
}

/* Test program */
int main()
{
    char a[] = "Hello";
    char b[] = "Hello";
    char c[] = "Hella";

    int result1 = my_memcmp(a, b, 5);
    int result2 = my_memcmp(a, c, 5);

    printf("Compare a and b: %d\n", result1);
    printf("Compare a and c: %d\n", result2);

    if (result2 > 0)
        printf("a is greater than c\n");
    else if (result2 < 0)
        printf("a is less than c\n");
    else
        printf("a and c are equal\n");

    return 0;
}
