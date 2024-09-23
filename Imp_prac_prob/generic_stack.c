#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
    STACK_INT,
    STACK_CHAR,
    STACK_UINT64
}DataType;

typedef struct stack{
    DataType type;
    size_t size;
    void* data;
    void* top;
}stack;

stack stackCreate(size_t size, DataType type){
    size_t effectiveSize = 0;
    if(type == STACK_CHAR){
        effectiveSize = size * sizeof(char);
    }
    else if(type == STACK_INT){
        effectiveSize = size * sizeof(int);
    }
    else if(type == STACK_UINT64){
        effectiveSize = size * sizeof(unsigned long long);
    }

    stack s = {
        .type = type,
        .size = size,
        .data = malloc(effectiveSize),
        .top = NULL
    };
    return s;
}

void stackDelete(stack* s){
    free(s->data);
    s->data = NULL;
}

int main(){
    stack s = stackCreate(10, STACK_INT);
    //when we want to read/write data to/from pointer, we have to cast it.
    //or else it will be dereferenced.
    ((int*)s.data)[0] = 64;
    s.top = ((int*)s.data) + 0;
    ((int*)s.data)[1] = 128;
    s.top = ((int*)s.data) + 1;

    stackDelete(&s);
    return 0;
}