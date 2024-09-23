/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

void print_byte_format(int arg)
{
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (arg & ((int)1 << i ))  ? 1 : 0);
    }
    printf("\n");
   
}

int main()
{
    int a;
    printf("Enter number: ");
    scanf("%d", &a);
    
    print_byte_format(a);

    return 0;
}

/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

void print_byte_format(int arg)
{
    unsigned int b = (unsigned int)arg;
    printf("Given number : 0x%8x : ", b);
    for (int i = 31; i >= 0; i--)
    {
        printf("%u", (b & ((unsigned int)1 << i )) ? 1: 0);
    }
    printf("\n");
}

int reverse_bits(int a)
{
    int res = 0;
    unsigned int num = (unsigned int) a;
    
    for (int i = 0; i < 8; i++)
    {
        res = (res << 4) | (num & 0x0000000F);
        num = num >> 4;
    }    
    return res;
}

int main()
{
    int a = 0x3caf0c53;
    //printf("Enter number: ");
    //scanf("%d", &a);
    
    print_byte_format(a);
    
    int b = reverse_bits(a);
    
    print_byte_format(b);

    return 0;
}

//int:   0011 1100 1010 1111 0000 1100 0101 0011 = 0x3caf0c53
//rev:   1100 1010 0011 0000 1111 0101 0011 1100 = 0xca30f53c
//swap:  0011 0101 1100 0000 1111 1010 1100 0011

//12345
//54321


