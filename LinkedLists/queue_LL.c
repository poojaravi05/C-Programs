#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;
/*
Queue:
Enqueue(x) = rear end = right side of LL = insertion
Dequeue = front end = left side of LL = deletion
*/

Node* rear = NULL;
Node* front = NULL;

void enqueue(int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        printf("Queue overflow\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    if(rear == NULL && front == NULL){
        rear = front = new_node;
    }
    rear->next = new_node;
    rear = new_node;
}

int isEmtpy(){
    if(front == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void dequeue(){
    Node* temp = front;
    if(isEmtpy()){
        printf("Queue underflow\n");
        exit(1);
    }
    if(front == NULL){
        return;
    }
    if(front == rear){
        front = rear = NULL;
    }
    else{
        front = front->next;
    }
    free(temp);
}

void count_node(){
    int cnt = 0;
    Node* temp = front;
    while(temp != NULL){
        temp = temp->next;
        cnt++;
    }
    printf("Count = %d\n", cnt);
}

//return the data of top most node
int front_ele(){
    if(isEmtpy()){
        printf("Queue underflow\n");
        exit(1);
    }
    int num = front->data;
    printf("Front element: %d\n", num);
    return front->data;
}

void display(){
    Node* temp = front;
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
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    
    dequeue();
    dequeue();
    display();
    
    front_ele();
    
    count_node();
    
    return 0;
}

