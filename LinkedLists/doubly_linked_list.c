#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

void add_node(Node* head, int data, int pos){
    if(head == NULL){
        return;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        return;
    }
    Node* temp = head->next;
    pos--;
    new_node->data = data;
    while(pos != 1){
        temp = temp->next;
        pos--;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
}

void add_front(Node* head, int data){
    if(head == NULL){
        return;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        return;
    }
    new_node->data = data;
    new_node->next = head->next;
    new_node->prev = head;
    head->next = new_node;
}

void add_tail(Node* head, int data){
    if(head == NULL){
        return;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        return;
    }
    new_node->data = data;
    new_node->next = NULL;
    Node* temp = head->next;
    while(temp->next != NULL){
        temp = temp->next;
    }
    new_node->prev = temp;
    temp->next = new_node;
}

void del_node(Node* head, int data){
    if(head == NULL){
        return;
    }
    Node* temp = head->next;
    while(temp != NULL){
        if(temp->data == data){
            head->next = temp->next;
            free(temp);
            temp = head->next;
            temp->prev = head;
            return;
        }
        head = temp;
        temp = temp->next;
    }
    printf("Element %d not found to delete\n", data);
}

void del_front(Node* head){
    if(head == NULL){
        return;
    }
    Node* temp = head->next;
    head->next = temp->next;
    free(temp);
    temp = head->next;
    temp->prev = head;
}

void del_tail(Node* head){
    if(head == NULL){
        return;
    }
    Node* temp = head->next;
    while(temp->next != NULL){
        head = head->next;
        temp = temp->next;
    }
    free(temp);
    head->next = NULL;
}

void count_node(Node* head){
    if(head == NULL){
        return;
    }
    int cnt = 0;
    Node* temp = head->next;
    while(temp != NULL){
        temp = temp->next;
        cnt++;
    }
    printf("Count = %d\n", cnt);
}

void display(Node* head){
    if(head == NULL){
        return;
    }
    Node* temp = head->next;
    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void destroy(Node* head){
    if(head == NULL){
        return;
    }
    Node* temp = head->next;
    while(head != NULL){
        free(head);
        head = temp;
        temp = temp->next;
    }
    return;
}

int main(){
    Node* head = (Node*)malloc(sizeof(Node));
    head->prev = NULL;
    head->next = NULL;

    add_front(head, 1);
    add_front(head, 2);
    add_front(head, 3);
    add_node(head, 15, 3);
    add_tail(head, 4);
    add_tail(head, 5);
    display(head);
    
    del_front(head);
    del_tail(head);
    del_node(head, 15);
    del_node(head, 6);
    display(head);
    
    count_node(head);
    
    destroy(head);
    free(head);
    display(head);
    
    return 0;
}

