#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

typedef struct minStack {
    int* arr;
    int size;
    int top;
    int min_val;
}minStack;

minStack* createStack(int size) {
    minStack* stack = (minStack*)malloc(sizeof(minStack));
    stack->arr = (int*)malloc(size * sizeof(int));
    stack->size = size;
    stack->top = -1;
    stack->min_val = INT_MAX;
    
    return stack;
}

void pushStack(minStack* stack, int val) {
    if(stack->top == stack->size-1) {
        printf("Stack full\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = val;
    stack->min_val = fmin(stack->min_val, val);
    //printf("Min value: %d\n", stack->min_val);
    return;
}

int popStack(minStack* stack) {
    int new_min = INT_MAX;
    if(stack->top == -1) {
        printf("Stack empty\n");
        return -1;
    }
    if(stack->arr[stack->top] == stack->min_val) {
        for(int i = stack->top - 1; i > -1; i--) {
            new_min = fmin(new_min, stack->arr[i]);
        }
        stack->min_val = new_min;
        //printf("New min value: %d\n", new_min);
    }
    int val = stack->arr[stack->top];
    stack->top--;
    printf("Popped element: %d\n", val);
    return 0;
}

int getMin(minStack* stack) {
    return stack->min_val;
}

void displayStack(minStack* stack) {
    if(stack->top == -1) {
        printf("Stack empty\n");
        return;
    }
    int i = stack->top;
    printf("Stack elements are: \n");
    while(i > -1) {
        printf("%d ", stack->arr[i]);
        i--;
    }
    printf("\n");
    return;
}

int main() {
    int size = 4;
    int min_val = INT_MAX;
    minStack* stack = createStack(size);
    
    pushStack(stack, 12);
    pushStack(stack, 21);
    
    min_val = getMin(stack);
    printf("Min Value of Stack = %d\n", min_val);
    
    pushStack(stack, 3);
    pushStack(stack, 1);
    pushStack(stack, 4);
    
    min_val = getMin(stack);
    printf("Min Value of Stack = %d\n", min_val);
    
    displayStack(stack);
    
    popStack(stack);
    popStack(stack);
    
    min_val = getMin(stack);
    printf("Min Value of Stack = %d\n", min_val);
    
    displayStack(stack);
    
    pushStack(stack, 5);
    
    displayStack(stack);
    
    min_val = getMin(stack);
    printf("Min Value of Stack = %d\n", min_val);
    
    return 0;
}