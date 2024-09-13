#include <stdio.h>
#include <cstdlib>

static int g_is_enbled = 0;

int returnInt(void)
{
    if (g_is_enbled)
        return 10;
    else
        return 0;
}

void enable(void)
{
    g_is_enbled = 1;
}

//the user calling this function should free the memory after use
int *returnIntPtrWithRandomSz(int *retSz)
{
    int sz = rand() % 100;
    printf("Random sz = %d\n", sz);
    
    *retSz = sz;
    
    int *arr = (int *)calloc(sizeof(int), sz);
    if (arr == NULL)
    {
        printf("Memory error\n");
        return NULL;
    }
    
    
    for (int i = 0; i < sz; i++)
    {
        arr[i] = i + 10;
    }
    
    return arr;
}

void printArr(int *arr, int sz)
{
    if (arr == NULL)
    {
        printf("Invalid input ptr\n");
        return;
    }
    
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

int main()
{
    int n = returnInt();
    printf("n = %d\n", n);
    enable();
    n = returnInt();
    printf("n = %d\n", n);
    
    int l_sz  = 0;
    
    int *p = returnIntPtrWithRandomSz(&l_sz);
    printf("Size of p = %zu, p = %p, l_sz = %d\n", sizeof(p), p, l_sz);
    
    char ch = 'A';
    char *ch_ptr = &ch;
    printf("Size of ch = %zu, size of ch_ptr = %zu, ch_ptr = %p \n", sizeof(ch), sizeof(ch_ptr), ch_ptr);
    printArr(p, l_sz);
    free(p);
    
    return 0;
}