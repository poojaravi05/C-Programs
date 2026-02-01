#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* link;
    struct Node* prev;
}Node;

int add_node(Node* head, int data, int pos) {
    if(head == NULL) {
        return -1;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        return -1;
    }
    Node* tmp = head;
    newNode->data = data;
    newNode->link = NULL;
    newNode->prev = NULL;
    
    pos--;
    while(pos > 0 && tmp->link != NULL) {
        tmp = tmp->link;
        pos--;
    }
    newNode->link = tmp->link;
    newNode->prev = tmp;
    
    if(tmp->link != NULL)
        tmp->link->prev = newNode;
    tmp->link = newNode;
    
    return 0;
}

int add_front(Node* head, int data) {
    if(head == NULL) {
        return -1;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        return -1;
    }
    Node* tmp = head;
    newNode->data = data;
    newNode->prev = head;
    newNode->link = tmp->link;
    
    if (head->link != NULL)
        tmp->link->prev = newNode;
    tmp->link = newNode;
    
    return 0;
}

int add_tail(Node* head, int data) {
    if(head == NULL) {
        return -1;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        return -1;
    }
    newNode->data = data;
    newNode->link = NULL;
    Node* tmp = head;
    while(tmp->link != NULL) {
        tmp = tmp->link;
    }
    tmp->link = newNode;
    newNode->prev = tmp;
    return 0;
}

int delete_node(Node* head, int data) {
    if(head == NULL) {
        return -1;
    }
    Node* tmp = head;
    Node* curr = head->link;
    
    while(curr != NULL) {
        if(curr->data == data) {
            tmp->link = curr->link;
            if(curr->link != NULL)
                curr->link->prev = tmp;
            free(curr);
            return 0;
        }
        tmp = curr;
        curr = curr->link;
    }
    printf("%d not found in list\n", data);
    return 0;
}

int delete_front(Node* head) {
    if(head == NULL) {
        return -1;
    }
    Node* tmp = head->link;
    head->link = tmp->link;
    if (tmp->link != NULL)
        tmp->link->prev = head;
    free(tmp);
    return 0;
}

int delete_tail(Node* head) {
    if(head == NULL || head->link == NULL) {
        return -1;
    }
    Node* tmp = head;
    Node* curr = head->link;
    while(curr->link != NULL) {
        tmp = curr;
        curr = tmp->link;
    }
    tmp->link = NULL;
    free(curr);
    return 0;
}

int display_ll(Node* head) {
    if(head == NULL) {
        return -1;
    }
    Node* tmp = head->link;
    printf("Linked List elements are: ");
    while(tmp != NULL) {
        printf("%d <-> ", tmp->data);
        tmp = tmp->link;
    }
    printf("\n");
    return 0;
}

int count_node(Node* head) {
    if(head == NULL) {
        return -1;
    }
    int cnt = 0;
    Node* tmp = head->link;
    while(tmp != NULL) {
        cnt++;
        tmp = tmp->link;
    }
    printf("Number of nodes = %d\n", cnt);
    return 0;
}

int reverse_ll(Node* head) {
    if(head == NULL) {
        return -1;
    }
    Node* tmp = head->link;
    Node* curr = tmp;
    Node* prev = NULL;
    
    while(curr != NULL) {
        curr = tmp->link;
        tmp->link = prev;
        tmp->prev = curr;
        prev = tmp;
        tmp = curr;
    }
    head->link = prev;
    if (prev != NULL)
        prev->prev = head;
    return 0;
}

int destroy_ll(Node* head) {
    if(head == NULL) {
        return -1;
    }
    Node* tmp = head->link;
    while(tmp != NULL) {
        head->link = tmp->link;
        free(tmp);
        tmp = head->link;
    }
    return 0;
}

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    head->link = NULL;
    head->prev = NULL;
    
    add_front(head, 1);
    add_front(head, 2);
    add_front(head, 3);
    display_ll(head);
    
    add_tail(head, 4);
    add_tail(head, 5);
    add_tail(head, 6);
    display_ll(head);
    
    add_node(head, 7, 4);
    display_ll(head);
    
    count_node(head);
    reverse_ll(head);
    display_ll(head);
    
    delete_node(head, 3);
    display_ll(head);
    delete_node(head, 8);
    
    delete_front(head);
    display_ll(head);
    
    delete_tail(head);
    display_ll(head);
    
    count_node(head);
    reverse_ll(head);
    display_ll(head);
    
    destroy_ll(head);
    
    return 0;
}
