#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Unions - all the members share the memory unlike in structs
// typedef union Example{
//     long long num;
//     char bytes[8];
// } Example;

//Anonymous unions
typedef struct customFloat{
    bool isExtended;
    union {
        float value;
        double valueExtended;
    };
}customFloat;
//in the above example, if bool is true, union is executed.

int main(){
    customFloat cf, cf2;
    cf.isExtended = false;
    cf.value = 12.5f;

    cf2.isExtended = true;
    cf2.valueExtended = 0.25;
    printf("%f %lf\n", cf.value, cf2.valueExtended); //12.500000 0.250000
    printf("%f %lf\n", cf.valueExtended, cf2.value); //0000 0000 - garbage value
    printf("%p %p\n", &cf.value, &cf2.valueExtended); // gets same address in memory
    return 0;
    /*
    Example e;
    e.num = 17;
    e.bytes[0] = 15;
    printf("%lld\n", e.num);//17
    for(int i = 0; i < 8; i++){
        printf("%02hhx ", e.bytes[i]); //11 00 00 00 00 00 00 00
        //here we are getting the memory of 17 instead of just 0's. converting 11 from hex to decimal will give 17.
        //because of memory sharing in unions.
        //02hhx - print whatever is in there...1 byte in hexadecimal, padding with 0, show 2 characters
    }
    */
}