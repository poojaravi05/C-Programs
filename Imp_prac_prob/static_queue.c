#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define QUEUE_SIZE 4
#define MASK (QUEUE_SIZE - 1)

typedef enum ERRORS {
    QUEUE_OK = 0,
    QUEUE_FULL = 1,
    QUEUE_EMPTY = 2
}ERRORS;

typedef struct queue {
    uint32_t arr[QUEUE_SIZE];
    int wr_ptr;
    int rd_ptr;
    int cnt;
}queue;

//queue my_queue;

void init_queue(queue* my_queue) {
    my_queue->wr_ptr = 0;
    my_queue->rd_ptr = 0;
    my_queue->cnt = 0;
}

bool isFull(queue* my_queue) {
    return my_queue->cnt == QUEUE_SIZE;
}

bool isEmpty(queue* my_queue) {
    return my_queue->cnt == 0;
}

ERRORS write_queue(queue* my_queue, uint32_t val) {
    if(isFull(my_queue)) {
        //printf("Queue is full\n");
        return QUEUE_FULL;
    }

    // //overwrite case
    // if(isFull(my_queue)) {
    //     my_queue->rd_ptr = (my_queue->rd_ptr + 1) & MASK;
    // }
    // else {
    //     my_queue->cnt++;
    // }

    my_queue->arr[my_queue->wr_ptr] = val;
    my_queue->wr_ptr = (my_queue->wr_ptr + 1) & MASK;
    my_queue->cnt++;
    
    return QUEUE_OK;
}

ERRORS read_queue(queue* my_queue, uint32_t* val) {
    if(isEmpty(my_queue)) {
        //printf("Queue is empty\n");
        return QUEUE_EMPTY;
    }
    *val = my_queue->arr[my_queue->rd_ptr];
    my_queue->rd_ptr = (my_queue->rd_ptr + 1) & MASK;
    my_queue->cnt--;

    return QUEUE_OK;
}

void display_queue(queue* my_queue) {
    int i = my_queue->rd_ptr;
    int cnt = my_queue->cnt;
    printf("Queue elements: ");
    while(cnt > 0) {
        printf("%d ", my_queue->arr[i]);
        i = (i + 1) & MASK;
        cnt--;
    }
    printf("\n");
    return;
}

int main() {
    queue my_queue;
    uint32_t val;

    init_queue(&my_queue);

    ERRORS status = read_queue(&my_queue, &val);
    if(status == QUEUE_EMPTY) {
        printf("QUEUE is EMPTY\n");
    }
    else {
        printf("Read value = %d\n", val);
    }
    display_queue(&my_queue);

    write_queue(&my_queue, 1);
    write_queue(&my_queue, 2);
    write_queue(&my_queue, 3);
    write_queue(&my_queue, 4);
    display_queue(&my_queue);

    //write_queue(&my_queue, 5);
    status = write_queue(&my_queue, 5);
    if(status == QUEUE_FULL) {
        printf("QUEUE is FULL\n");
    }
    display_queue(&my_queue);

    //read_queue(&my_queue, &val);
    status = read_queue(&my_queue, &val);
    if(status == QUEUE_EMPTY) {
        printf("QUEUE is EMPTY\n");
    }
    else {
        printf("Read value = %d\n", val);
    }
    display_queue(&my_queue);

    write_queue(&my_queue, 6);
    display_queue(&my_queue);

    read_queue(&my_queue, &val);
    display_queue(&my_queue);

    return 0;
}