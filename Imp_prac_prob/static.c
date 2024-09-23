#include <stdio.h>
#define MAXNUM 3

void sum_up(void);

int main() {
    int count;
    printf("\n*****static storage*****\n");
    printf("Key in 3 numbers to be summed ");
    for(count = 0; count < MAXNUM; count++)
        sum_up();
    printf("\n*****COMPLETED*****\n");

    return 0;
}

void sum_up(void) {
    //if static is not given, the sum value will not be updated as intended for each itrn, because ince the function exits,
    //it gets erased from the stack frame. 
    static int sum;
    //auto int sum = here sum will be created new everytime the function is called. doesn't update as intended.
    //const int sum = gives error
    int num;
    printf("\nEnter a number: ");
    scanf("%d", &num);
    sum += num;
    printf("\nThe current total is: %d\n", sum);
}