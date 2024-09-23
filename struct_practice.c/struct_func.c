#include <stdio.h>
#include <string.h>

struct mobile {
    char make[15];
    int year;
};

struct mobile car1, car2;

struct mobile findYear(char name[]) {
    struct mobile car;
    printf("Enter year of %s: \n", name);
    scanf("%d", &car.year);
    printf("car.year = %d\n", car.year);
    strcpy(car.make, name);
    return car;
}

void printOldest(struct mobile auto1, struct mobile auto2) {
    if(auto1.year > auto2.year) {
        printf("The oldest car is %s\n", auto2.make);
    }
    else if (auto1.year < auto2.year) {
        printf("The oldest car is %s\n", auto1.make);
    }
    else {
        printf("Both are same year models\n");
    }
}

void main() {
    car1 = findYear("Honda");
    car2 = findYear("Tesla");
    printOldest(car1, car2);
}
