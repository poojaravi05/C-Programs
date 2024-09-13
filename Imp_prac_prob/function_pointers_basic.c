#include <stdio.h>

void printNumbers(int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
}

int main()
{
    void (*func_ptr) (int);
    int n;
    printf("Enter num: ");
    scanf("%d", &n);
    
    func_ptr = &printNumbers;
    printNumbers(n);
    func_ptr(n);
    
    return 0;
}