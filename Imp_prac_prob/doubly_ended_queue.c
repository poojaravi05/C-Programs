//Double ended queue

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct circular_queue {
    int* arr;
    int size;
    int cnt;
    int rd_ptr;
    int wr_ptr;
}cq;

cq* init_queue(int size) {
    cq* queue = (cq*)malloc(sizeof(cq));
    queue->arr = (int*)malloc(sizeof(int)*size);
    queue->size = size;
    queue->cnt = 0;
    queue->rd_ptr = 0;
    queue->wr_ptr = 0;
    
    return queue;
}

bool isEmpty(cq* queue);
bool isFull(cq* queue);

void write_rear(cq* queue, int value) {
    if(isFull(queue)) {
        printf("Queue Full !\n");
        return;
    }
    queue->arr[queue->wr_ptr] = value;
    queue->wr_ptr = (queue->wr_ptr + 1) % queue->size;
    queue->cnt++;
}

void write_front(cq* queue, int value) {
    if (isFull(queue)) {
        printf("Queue Full!\n");
        return;
    }
    queue->rd_ptr = (queue->rd_ptr - 1 + queue->size) % queue->size;
    queue->arr[queue->rd_ptr] = value;
    queue->cnt++;
}

void read_front(cq* queue) {
    if(isEmpty(queue)) {
        printf("Queue Empty !\n");
        return;
    }
    int value = queue->arr[queue->rd_ptr];
    queue->rd_ptr = (queue->rd_ptr + 1) % queue->size;
    queue->cnt--;
    
    printf("Value read: %d\n", value);
}

void read_rear(cq* queue) {
    if (isEmpty(queue)) {
        printf("Queue Empty!\n");
        return;
    }
    queue->wr_ptr = (queue->wr_ptr - 1 + queue->size) % queue->size;
    int value = queue->arr[queue->wr_ptr];
    queue->cnt--;

    printf("Value read from rear: %d\n", value);
}

void display_queue(cq* queue) {
    if(isEmpty(queue)) {
        printf("Queue Empty !\n");
        return;
    }
    int i = queue->rd_ptr;
    int count = queue->cnt;
    
    printf("Queue Elements are: ");
    while(count) {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % queue->size;
        count--;
    }
    printf("\n");
}

bool isEmpty(cq* queue) {
    return queue->cnt == 0;
}

bool isFull(cq* queue) {
    return queue->cnt == queue->size;
}

int main() {
    cq* queue = init_queue(5);
    
    write_rear(queue, 1);
    write_rear(queue, 2);
    write_rear(queue, 3);
    write_rear(queue, 4);
    write_rear(queue, 5);
    
    display_queue(queue);

    read_front(queue);
    read_front(queue);
    
    display_queue(queue);

    write_front(queue, 6);
    
    display_queue(queue);

    read_rear(queue);
    
    display_queue(queue);

    write_rear(queue, 7);
    
    display_queue(queue);

    free(queue->arr);
    free(queue);
    
    return 0;
}