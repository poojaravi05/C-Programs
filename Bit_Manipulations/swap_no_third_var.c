#include <stdio.h>

void swap (int num1, int num2) {
    num1 = num1 ^ num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;

    printf("After swapping: X = %d and Y = %d", num1, num2);
}

int main() {
    int x = 3, y = 4;

    printf("Before swapping: X = %d and Y = %d", x, y);
    swap(x, y);

    return 0;
}

/*
void swap(int* xp, int* yp) 
{ 
    if (xp == yp) // Check if the two addresses are same 
        return; 
    *xp = *xp + *yp; 
    *yp = *xp - *yp; 
    *xp = *xp - *yp; 
} 
int main() 
{ 
    int x = 10, y = 20; 
    swap(&x, &y); 
    printf("After swap(&x, &y): x = %d and y = %d", x, y); 
    return 0; 
}

*/