#include <stdio.h>
#include <string.h>

struct participant {
    char name[20];
    char country[25];
    float score;
    int age;
};

struct team {
    struct participant captain;
    int wins;
    int loses;
    struct participant players[2];
};
/*
struct team details = {
    {.name = "john", .country = "USA", .score = 7.6, .age = 26},
    5,
    2,
    {{.name = "Manju", .country = "India", .score = 9.6, .age = 28},
        {.name = "Pooja", .country = "India", .score = 9.2, .age = 24}}
}; */

struct team new_info;

int main() {
    struct team details[2] = {
        {{.name = "john", .country = "USA", .score = 7.6, .age = 26},
        5,
        2,
        {{.name = "Manju", .country = "India", .score = 9.6, .age = 28},
        {.name = "Pooja", .country = "India", .score = 9.2, .age = 24}}},
        
        {{.name = "Don", .country = "USA", .score = 6.6, .age = 26},
        4,
        3,
        {{.name = "Daniel", .country = "Australia", .score = 5.6, .age = 28},
        {.name = "Rock", .country = "China", .score = 8.2, .age = 24}}},
        
    };
    
    strcpy(new_info.captain.name, details[1].captain.name);
    new_info.players[0].score = details[0].players[1].score;
    
    
    //new_info = details[1];
    
    printf("Captain name = %s\n", new_info.captain.name);
    printf("Player score = %f\n", new_info.players[0].score);
    return 0;
}


