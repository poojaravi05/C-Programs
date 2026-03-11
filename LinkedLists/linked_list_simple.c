#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}node_t;

node_t* insert_node(node_t* head, int val, int pos) {
    if(!head) {
        return NULL;
    }
    node_t* tmp = head;

    node_t* new_node = malloc(sizeof(node_t));
    if(!new_node) {
        return NULL;
    }

    new_node->val = val;

    while(pos > 1 && tmp->next != NULL) {
        pos--;
        tmp = tmp->next;
    }
    new_node->next = tmp->next;
    tmp->next = new_node;

    return head;
}

node_t* delete_node(node_t* head, int val) {
    if(!head) {
        return NULL;
    }

    node_t* tmp = head->next;
    node_t* prev = head;

    while(tmp != NULL) {
        if(tmp->val == val) {
            prev->next = tmp->next;
            free(tmp);
            return head;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    
    return head;
}

void display_node(node_t* head) {
    if(!head) {
        return;
    }

    node_t* tmp = head->next;
    while(tmp != NULL) {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
}

void destroy_node(node_t* head) {
    if(!head) {
        return;
    }

    node_t* tmp = head->next;
    while(tmp != NULL) {
        head->next = tmp->next;
        free(tmp);
        tmp = head->next;
    }
}

int count_nodes(node_t* head) {
    if(!head) {
        return -1;
    }

    int cnt = 0;
    node_t* tmp = head->next;
    while(tmp != NULL) {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}

node_t* reverse_list(node_t* head) {
    if(!head) {
        return NULL;
    }

    node_t* tmp = head->next;
    node_t* curr = tmp;
    node_t* prev = NULL;

    while(curr != NULL) {
        curr = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = curr;
    }
    head->next = prev;

    return head;
}

int main() {
    node_t head;
    head.next = NULL;

    int cnt = 0;

    insert_node(&head, 11, 1);
    insert_node(&head, 12, 2);
    insert_node(&head, 13, 3);
    insert_node(&head, 14, 4);
    display_node(&head);
    
    reverse_list(&head);
    display_node(&head);
    printf("\n");

    insert_node(&head, 15, 1);
    display_node(&head);
    
    reverse_list(&head);
    display_node(&head);
    printf("\n");

    insert_node(&head,16, 6);
    display_node(&head);
    
    reverse_list(&head);
    display_node(&head);
    printf("\n");

    cnt = count_nodes(&head);
    printf("Total number of nodes: %d\n", cnt);
    
    printf("\n");

    delete_node(&head, 12);
    display_node(&head);
    
    reverse_list(&head);
    display_node(&head);
    printf("\n");

    delete_node(&head, 15);
    display_node(&head);

    reverse_list(&head);
    display_node(&head);
    printf("\n");

    delete_node(&head, 11);
    display_node(&head);
    
    reverse_list(&head);
    display_node(&head);
    
    printf("\n");

    cnt = count_nodes(&head);
    printf("Total number of nodes: %d\n", cnt);

    destroy_node(&head);
    free(&head);

    return 0;
}