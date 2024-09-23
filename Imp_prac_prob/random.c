#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
int main(int argc, char*argv[]){
    time_t random = time(NULL);
    srand(random);
    //srand(time(NULL)); --> can do this way as well
    printf("%d\n", rand());
    printf("%d\n", rand());
    return 0;
}*/

int rand_interval(int a, int b){
    return rand() % (b-a)+a;
}

double rand_double(){
    return ((double)rand()) / ((double)RAND_MAX);
}

double rand_double_interval(double a, double b){
    return rand_double() * (b-a) + a;
}

void rand_string(char* str, int num){
    for(int i = 0; i < num; i++){
        str[i] = rand() % ('z' - 97 + 1) + 97;
        //ASCII values instead of letters. +1 to indicate both are inclusive in intervals
    }
    str[num] = 0;
}

//generate random string from a set of characters.
char random_chars[] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'a', 'b', 'c', 'd', 'e', 'f', '+', '&', '-', '%'
};
int random_chars_len = sizeof(random_chars) / sizeof(char);

void rand_string2(char* str, int num){
    for(int i = 0; i < num; i++){
        str[i] = random_chars[rand() % random_chars_len];
    }
    str[num] = 0;
}

int main(){
    srand(time(NULL));
    //if you add this in functions other than in main and call the function multiple times,
    //the output generated will be same each time.
    for(int i=0; i < 10; i++){
        printf("%d ", rand_interval(5, 20));
    }
    for(int i=0; i < 10; i++){
        printf("%lf ", rand_double());
    }
    for(int i=0; i < 10; i++){
        printf("%lf ", rand_double_interval(5, 10));
    }

    char str[16];
    rand_string(str, 15);
    printf("%s ", str);
    rand_string2(str, 15);
    printf("%s ", str);
    return 0;
}