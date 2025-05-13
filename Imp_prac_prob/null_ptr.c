#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 1, b = 2;
    printf("a = %d, b = %d\n", a, b);
    
    int *ptr1 = &a, *ptr2 = &b;
    printf("*ptr1 = %d, *ptr2 = %d\n", *ptr1, *ptr2);

    int *ptr = NULL;
    if (ptr == NULL)
    {
        printf("ptr = NULL\n");
    }
    
    ptr = (int *)calloc(1, sizeof(int));
    if (ptr == NULL)
    {
        return -1;
    }
    
    *ptr = 18;
    printf("ptr = %p, *ptr = %d\n", ptr, *ptr);
    
    free(ptr);
    
    if (ptr != NULL)
    {
        printf("ptr is NOT NULL. ptr = %p\n", ptr);
        *ptr = 29;
        printf("New *ptr = %d\n", *ptr);
    }
    return 0;
}
