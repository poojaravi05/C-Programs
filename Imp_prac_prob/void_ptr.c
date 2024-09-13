#include <stdio.h>
#include <stdlib.h>

typedef enum dataTypes {
    type_char = 0,
    type_int = 1,
    type_float = 2,
    type_student = 3
} dataTypes;

typedef struct student {
    char *name;
    int roll;
    float cgpa;
} student_t;

void print(dataTypes d_type, void *d_ptr)
{
    switch (d_type)
    {
        case type_char:
            printf("Char : %c\n", *(char *)d_ptr);
            break;
        
        case type_int:
            printf("Int: %d\n", *(int *)d_ptr);
            break;
        
        case type_float:
            printf("Float: %f\n", *(float *)d_ptr);
            break;
            
        case type_student:
            student_t *s_ptr = (student_t *)d_ptr;
            printf("Student info: name = %s, roll = %d, cgpa = %f\n", s_ptr->name, s_ptr->roll, s_ptr->cgpa);
            break;
        default:
            printf("Invalid data type\n");
            break;
    }
    
}

int main()
{
    char c = 'A';
    int i = 18;
    float f = 3.142;
    student_t s = {
        .name = "Revanth",
        .roll = 89,
        .cgpa = 3.77
    };
    
    //printf("Name = %s\n", s.name);
    
    print(type_char, (void *)&c);
    print(type_int, (void *)&i);
    print(type_float, (void *)&f);
    print(type_student, (void *)&s);
    
    return 0;
}
