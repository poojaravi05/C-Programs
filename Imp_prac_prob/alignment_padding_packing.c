
#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

typedef struct student {
    
    int id; //4
    char initial[5]; //5
    double score; //8
    short class; //2
    float marks;  //4
}student;

struct temp {
    int id; //4
    double d; //8
    char str[2]; //2
    float f; //4
}__attribute__((packed));

char a;

void argument_alignment_check(char c1, char c2) {
    printf("Displacement = %d\n", (int)&c2-(int)&c1);
}

void main() {
    char b;
    //positive for downward stack. negative for upward stack
    argument_alignment_check(a, b);
    // printf("Size of char = %d\n", sizeof(char));
    // printf("Size of int = %d\n", sizeof(int));
    // printf("Size of float = %d\n", sizeof(float));
    printf("Size of struct temp = %ld\n", sizeof(struct temp));
}
