#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
    return a+b;
}

int sub(int a, int b) {
    return a-b;
}

int mul(int a, int b) {
    return a*b;
}

int divi(int a, int b) {
    return a/b;
}

typedef struct student {
    char* name;
    int roll;
    float cgpa;
    char section;
    char (*sec_ptr)(int);
}stud_t;

typedef struct qurem {
    int quo;
    int dummy;
    char ch;
    int rem;
}qurem;

qurem division(int a, int b) {
    qurem res;
    res.dummy = -1;
    res.quo = a/b;
    res.rem = a%b;
    res.ch = 'D';

    return res;
}

char get_stud_section(int roll) {
    if(roll < 10)
        return 'A';
    else if (roll > 10 && roll < 20)
        return 'B';
    else
        return 'C';
}
int main() {
    int op = 0, a = 5, b = 3;
    /*
    printf("Res = %d\n", add(a, b));
    printf("Res = %d\n", sub(a, b));

    int (*add_ptr) (int, int) = &add;
    add_ptr = sub;
    printf("Res = %d\n", add_ptr(a, b));
    */
    /*
    int (*calci_ptr[4]) (int, int) = {add, sub, mul, divi};
    printf("Enter operation: 0. Add, 1, Sub, 2. Mul, 3. Divi\n");
    scanf("%d", &op);

    int res = calci_ptr[op](a, b);
    printf("Res = %d\n", res);
    */
    
    qurem (*struct_func_ptr)(int, int) = division;
    qurem ans = struct_func_ptr(a, b);
    
    printf("Quotient = %d, remainder = %d\n", ans.quo, ans.rem);
    //printf("Quotient = %d, dummy = %d, char = %c, remainder = %d\n", struct_func_ptr(10, 3));

    /*
    stud_t stu_1 = {
        .name = "Manju",
        .roll = 18,
        .cgpa = 3.8,
        .sec_ptr = get_stud_section
    };

    stu_1.section = stu_1.sec_ptr(stu_1.roll);
    printf("Name = %s, Roll = %d, cgpa = %f, Section = %c\n", stu_1.name, stu_1.roll, stu_1.cgpa, stu_1.section);
    printf("Section = %d\n", stu_1.sec_ptr(stu_1.roll));
    */
    return 0;
}