#include <stdio.h>

// Function to count the total number of set bits in `n`
int countSetBits(int n)
{
    // `count` stores the total bits set in `n`
    int count = 0;

    while (n)
    {
        n = n & (n - 1);    // clear the least significant bit set
        count++;
    }

    return count;
}

// Function to print binary representation of an integer
void printBinary(int n)
{
    for (int i = 0; i <= 31; i++)
    {
        int k = n >> i;
        if (k & 1)
            printf("1");
        else
            printf("0");
    }
}

int main()
{
    int n = -1;

    printf("%d in binary is ", n);
    printBinary(n);
    printf("\n");
    printf("The total number of set bits in %d is %d\n", n, countSetBits(n));

    return 0;
}

/*
// In C++ using <bitset>:
#include <iostream>
#include <bitset>
using namespace std;
 
// Function to count the total number of set bits in `n`
int countSetBits(int n)
{
    // `count` stores the total bits set in `n`
    int count = 0;
 
    while (n)
    {
        n = n & (n - 1);    // clear the least significant bit set
        count++;
    }
 
    return count;
}
 
int main()
{
    int n = -1;
 
    cout << n << " in binary is " << bitset<32>(n) << endl;
    cout << "The total number of set bits in " << n << " is "
         << countSetBits(n) << endl;
 
    return 0;
}
// Output:-1 in binary is 11111111111111111111111111111111
//The total number of set bits in -1 is 32
*/

/*
// In C++ using __builtin_popcount
#include <iostream>
using namespace std;
 
int main()
{
    int n = 16;
    cout << "The total number of set bits in " << n << " is "
         << __builtin_popcount (n) << endl;
 
    return 0;
}

//output: The total number of set bits in 16 is 1
*/