#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// A function to copy block of 'n' bytes from source
// address 'src' to destination address 'dest'.
void myMemMove(void *dest, void *src, size_t n)
{
    // Typecast src and dest addresses to (char *)
    char *csrc = (char *)src;
    char *cdest = (char *)dest;

    printf("csrc address: %p, cdest address: %p\n, csrc+n: %p\n", csrc, cdest, csrc+n);
    
    // If source and destination addresses overlap
    if (csrc < cdest && cdest < csrc + n)
    {
        // Copy from end to beginning
        for (size_t i = n; i > 0; i--)
            cdest[i - 1] = csrc[i - 1];
    }
    else
    {
        // Copy from beginning to end
        for (size_t i = 0; i < n; i++)
            cdest[i] = csrc[i];
    }
}

// Driver program
int main()
{
    char csrc[100] = "GeeksforGeeks";
    char cdest[100] = "Practice";
    printf("Before: csrc = %s, cdest = %s\n", csrc, cdest);
    myMemMove(csrc + 5, csrc, strlen(csrc) + 1);
    printf("After: csrc = %s, cdest = %s\n", csrc, cdest); // GeeksGeeksfor
    return 0;
}
