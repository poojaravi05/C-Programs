#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* top = NULL;

void push(int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        printf("Stack overflow\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = top;
    top = new_node;
}

int isEmtpy(){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int pop(){
    Node* temp = top;
    if(isEmtpy()){
        printf("Stack underflow\n");
        exit(1);
    }
    int val = temp->data;
    printf("Popped element: %d\n", val);
    top = temp->next;
    free(temp);
    temp = top;
    return val;
}

void count_node(){
    int cnt = 0;
    Node* temp = top;
    while(temp != NULL){
        temp = temp->next;
        cnt++;
    }
    printf("Count = %d\n", cnt);
}

//return the data of top most node
int peek(){
    if(isEmtpy()){
        printf("Stach underflow\n");
        exit(1);
    }
    int num = top->data;
    printf("Top element: %d\n", num);
    return top->data;
}

void display(){
    Node* temp = top;
    if(isEmtpy()){
        printf("Stach underflow\n");
        exit(1);
    }
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    display();
    
    pop();
    pop();
    display();
    
    peek();
    
    count_node();
    
    display();
    
    return 0;
}

