#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct date {
    int day, month, year;
};

struct employee {
    char name[25];
    float salary;
    struct date hired;
};

struct dept {
    struct employee manager;
    struct employee engineer[2];
    float profit;
};

int main() {
    struct date date1 = {27, 05, 2024};
    printf("The date = %d/%d/%d\n", date1.day, date1.month, date1.year);
    
    struct employee Person1 = {"Roger", 50000, {10, 03, 2020}};
    printf("Employee Name = %s\n", Person1.name);
    printf("Hired Date = %d/%d/%d\n", Person1.hired.day, Person1.hired.month, Person1.hired.year);
    printf("Salary = $%.2f\n", Person1.salary);
    
    struct dept Toys[2] = {
        Person1,
        {{"David", 35000, {9, 02, 2021}}, {"Julie", 42000, {16, 8, 2022}}},
        75000
    };
    printf("%s is the manager\n", Toys->manager.name);

    printf("Company profit is $%.2f\n", Toys->profit);

    printf("Hired Date for %s is %d/%d/%d\n", Toys->engineer[0].name, Toys->engineer[0].hired.month, Toys->engineer[0].hired.day, Toys->engineer[0].hired.year);
    
    return 0;
}