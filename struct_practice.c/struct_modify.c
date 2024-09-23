#include<stdio.h>

typedef struct student {
    int id;
    int age;
} student;

student std[2]; 

void details() {
    std[0].id = 1;
    std[0].age = 15;
    std[1].id = 2;
    std[1].age = 15;
}

void modify(int *age) {
    printf("Given age = %d\n", *age);
    *age = 20;
    printf("New age = %d\n", *age);
}

int main() {
    details();
    modify(&std[1].age);
    printf("Changed age = %d\n", std[1].age);

    return 0;
}
