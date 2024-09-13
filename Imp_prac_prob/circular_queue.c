#include <stdio.h>
#include <stdlib.h>

typedef struct circularQueue {
    int* arr;
    int size;
    int cnt;
    int wr_ptr;
    int rd_ptr;
}cq;

cq* init_buffer(int size) {
    cq* queue = (cq*)malloc(sizeof(cq)); // allocate memory for the circular queue structure
    queue->arr = (int*)malloc(size*sizeof(int)); // allocate memory for the array
    queue->size = size;
    queue->cnt = 0;
    queue->wr_ptr = 0;
    queue->rd_ptr = 0;
    return queue;
}

void write_queue(cq* queue, int value) {
    // check if queue is full
    if(queue->cnt == queue->size) {
        printf("Queue is full\n");
        return;
    }
    // insert value at the write index and increment cnt
    queue->arr[queue->wr_ptr] = value;
    queue->wr_ptr = (queue->wr_ptr + 1) % queue->size; // for circular queue write index
    queue->cnt++;
}

int read_queue(cq* queue) {
    // check if queue is empty
    if(queue->cnt == 0) {
        printf("Queue empty\n");
        return -1;
    }
    // read from the index and decrement cnt
    int value = queue->arr[queue->rd_ptr];
    queue->rd_ptr = (queue->rd_ptr + 1) % queue->size; // for circular queue read index
    queue->cnt--;
    return value;
}

void display_queue(cq* queue) {
    if(queue->cnt == 0) {
        printf("Queue empty\n");
        return;
    }
    // keeping local variables inorder to avoid miscalulations for other functions
    int i = queue->rd_ptr;
    int count = queue->cnt;
    printf("Queue elements are: \n");
    while(count) {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % queue->size;
        count--;
    }
    printf("\n");
}

int main() {
    int size = 6;
    cq* queue = init_buffer(size);
    
    write_queue(queue, 10);
    write_queue(queue, 20);
    write_queue(queue, 30);
    write_queue(queue, 40);
    write_queue(queue, 50);
    write_queue(queue, 60);
    
    display_queue(queue);
    
    printf("Read queue element: %d\n", read_queue(queue));
    printf("Read queue element: %d\n", read_queue(queue));
    printf("Read queue element: %d\n", read_queue(queue));
    
    display_queue(queue);
    
    write_queue(queue, 1);
    write_queue(queue, 2);
    write_queue(queue, 3);
    write_queue(queue, 4);
    write_queue(queue, 5);
    
    display_queue(queue);
    
    free(queue->arr);
    free(queue);
    
    return 0;
}

