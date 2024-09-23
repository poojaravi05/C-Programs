//Stack with array

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int *arr;
    int arrSz;
    int top;
}stack_t;

stack_t* init_buffer(int arrSz) {
    stack_t* stack = (stack_t*)malloc(sizeof(stack_t));
    if(stack == NULL)
        return NULL;
    stack->arr = (int*)malloc(sizeof(int)*arrSz);
    if(stack->arr == NULL) {
        free(stack);
        return NULL;
    }
    stack->arrSz = arrSz;
    stack->top = -1;
    
    return stack;
}

void push(stack_t* stack, int val) {
    if(stack->top == stack->arrSz-1) {
        printf("Stack full\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = val;
}

void pop(stack_t* stack) {
    if(stack->top == -1) {
        printf("Stack empty\n");
        return;
    }
    int val = stack->arr[stack->top];
    stack->top--;
    printf("Popped element: %d\n", val);
    return;
}

void displayStack(stack_t* stack) {
    if(stack->top == -1) {
        printf("Stack empty\n");
        return;
    }
    int i = stack->top;
    printf("Stack elements are: ");
    while(i != -1) {
        printf("%d ", stack->arr[i]);
        i--;
    }
    printf("\n");
    return;
}

void deinit_stack(stack_t* stack)
{
    if (stack)
    {
        if (stack->arr)
            free(stack->arr);
        free(stack);
    }
}

int main() {
    int arrSz = 4;
    stack_t* stack = init_buffer(arrSz);
    if(stack == NULL) {
        return NULL;
    }
    
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5); //stack full
    
    displayStack(stack); //4 3 2 1
    
    pop(stack); //4
    pop(stack); //3
    
    displayStack(stack); //2 1
    
    pop(stack); //2
    pop(stack); //1
    
    displayStack(stack); //empty
    
    deinit_stack(stack);
    
    return 0;
}