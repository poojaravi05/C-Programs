#include <stdio.h>

//enum similar to struct. they are user defined type that can have only certain values.
typedef enum Color{
    RED,
    BLUE = 8,
    PINK
}Color;

//typedef enum Color Color;

int main(int args, char* argv[]){
    Color c = RED;
    Color b = BLUE;
    Color a = PINK;
    printf("%d\n", c); // 0 - index value
    printf("%d\n", b); // 8 - value associated
    printf("%d\n", a); // 9 - value continues
    return 0;
}