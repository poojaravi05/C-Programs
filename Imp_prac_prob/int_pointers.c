#include <stdio.h>

int main()
{
    int array[5];
    
    array[1] = 5;
    
    printf("array = %zu\n", array); //contains address of first element
    printf("array + 1 = %zu\n", array + 1);//address of next element
    printf("*(array + 1) = %zu\n\n", *(array + 1));//address of next element
    printf("&array = %zu\n", &array); //conatains address of the whole array
    printf("&array + 1 = %zu\n", &array + 1);//address of next array.
    printf("*(&array[1]) = %zu\n\n", *(&array[1]));
    
    printf("____________________\n\n");
    
    int matrix[3][5] = {
        {0, 1, 2, 3, 4},
        {5, 6, 7, 8, 9},
        {10, 11, 12, 13, 14}
    };
    
    printf("matrix[1] = %zu\n", matrix[1]);//address of first element of row 1
    printf("matrix[1] + 1 = %zu\n", matrix[1] + 1);//next element of row 1
    printf("*(matrix[1] + 1) = %zu\n\n", *(matrix[1] + 1));
    printf("&matrix[1] = %zu\n", &matrix[1]);//address of entire row 1
    printf("&matrix[1] + 1 = %zu\n", &matrix[1] + 1);//address of row 2
    printf("*(&matrix[1] + 1) = %zu\n\n", *(&matrix[1] + 1));
    printf("*(*(&matrix[1] + 1)) = %zu\n\n", *(*(&matrix[1] + 1)));//this double ptr dereferencing gives value 10
    
    int *ptr = (int*) (&matrix[1] + 1); //typecast to avoid warning
    //it is important to wrap (&matrix[1] + 1) to get the correct output 10, becuase of the operator precedence,
    //if we do not wrap it, the output will be 6. As it converts &matrix[1] to int ptr type and then adds 1.
    
    printf("ptr = %zu\n", ptr);
    printf("*ptr = %zu\n", *ptr);
    
    return 0;
}
