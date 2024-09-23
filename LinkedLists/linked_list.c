#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int data;
    struct Node* link;
}Node;

int add_node(Node* head, int data, int pos){
    if(head == NULL){
        return -1;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        return -1;
    }
    Node* temp = head->link;
    new_node->data = data;
    new_node->link = NULL;
    
    pos--;
    while(pos != 1){
        temp = temp->link;
        pos--;
    }
    new_node->link = temp->link;
    temp->link = new_node;
    
    return 0;
}

int add_front(Node* head, int data){
    if(head == NULL){
        return -1;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        return -1;
    }
    new_node->data = data;
    new_node->link = head->link;
    head->link = new_node;
    
    return 0;
}

int add_tail(Node* head, int data){
    if(head == NULL){
        return -1;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        return -1;
    }
    Node* temp = head;
    new_node->data = data;
    new_node->link = NULL;
    while(temp->link != NULL){
        temp = temp->link;
    }
    temp->link = new_node;
    
    return 0;
}

int del_node(Node* head, int data){
    if(head == NULL){
        return -1;
    }
    Node* temp = head->link;
    while(temp != NULL){
        if(temp->data == data){
            head->link = temp->link;
            free(temp);
            return 0;
        }
        head = temp;
        temp = temp->link;
    }
    printf("Element %d not found to delete\n", data);
    return 0;
}

int del_front(Node* head){
    if(head == NULL){
        return -1;
    }
    Node* temp = head->link;
    head->link = temp->link;
    free(temp);
    return 0;
}

int del_tail(Node* head){
    if(head == NULL){
        return -1;
    }
    Node* temp = head->link;
    while(temp->link != NULL){
        head = temp;
        temp = temp->link;
    }
    free(temp);
    head->link = NULL;
    return 0;
}

int reverse(Node* head){
    if(head == NULL){
        return -1;
    }
    Node* temp = head->link;
    Node* prev = NULL;
    Node* curr = temp;
    
    while(curr != NULL){
        curr = temp->link;
        temp->link = prev;
        prev = temp;
        temp = curr;
    }
    head->link = prev;
    return 0;
}

int display(Node* head){
    if(head == NULL){
        return -1;
    }
    Node *temp = head->link;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
    return 0;
}

int count_node(Node* head){
    if(head == NULL){
        return -1;
    }
    int cnt = 0;
    Node* temp = head->link;
    while(temp != NULL){
        cnt++;
        temp = temp->link;
    }
    printf("Count = %d\n", cnt);
    return 0;
}

int destroy(Node* head){
    if(head == NULL){
        return -1;
    }
    Node* temp = head->link;
    while(temp != NULL){
        head->link = temp->link;
        free(temp);
        temp = head->link;
    }
    return 0;
}

int main(){
    Node* head = (Node*)malloc(sizeof(Node));
    head->link = NULL;
    
    add_front(head, 1);
    add_front(head, 2);
    add_front(head, 3);
    add_front(head, 4);
    add_tail(head, 5);
    add_tail(head, 6);
    add_tail(head, 7);
    add_node(head, 12, 4);
    display(head);
    
    count_node(head);
    
    del_front(head);
    del_tail(head);
    display(head);
    
    del_node(head, 5);
    del_node(head, 8);
    display(head);
    
    reverse(head);
    display(head);
    
    destroy(head);
    free(head);
    return 0;
}
