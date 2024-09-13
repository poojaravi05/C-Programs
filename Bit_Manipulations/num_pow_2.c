// Check if the number is a power of 2

#include <stdio.h>
#include <stdbool.h>

bool isPower(int x) {
    if(x == 0) {
        return false;
    }
    if((x & (x-1)) == 0) {
        return true;
    }
    else{
        return false;
    }
//return x && (!(x & (x - 1)));
}

int main()
{
    int x = 18;
    bool ans;
    
    ans = isPower(x);
    if(ans == true) {
        printf("The given number %d is a power of two\n", x);
    }
    else {
        printf("The given number %d is not a power of two", x);
    }
    
    return 0;
}
