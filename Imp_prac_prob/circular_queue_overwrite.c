#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cq {
    int* arr;
    int sz;
    int cnt;
    int rd_ptr;
    int wr_ptr;
}cq;

cq* init_buffer(int sz) {
    cq* queue = (cq*)malloc(sizeof(cq));
    queue->arr = (int*)malloc(sz * sizeof(int));
    queue->sz = sz;
    queue->cnt = 0;
    queue->rd_ptr = 0;
    queue->wr_ptr = 0;

    return queue;
}

void write_queue(cq* queue, int data) {
    /*
    if(queue->cnt == queue->sz) {
        printf("Queue full!\n");
        return;
    }
    */
    //overwrite case
    if(queue->cnt == queue->sz) {
        queue->rd_ptr = (queue->rd_ptr + 1) % queue->sz;
    }
    else {
        queue->cnt++;
    }
    queue->arr[queue->wr_ptr] = data;
    queue->wr_ptr = (queue->wr_ptr + 1) % queue->sz;
    //queue->cnt++;
    
    return;
}

void read_queue(cq* queue) {
    if(queue->cnt == 0) {
        printf("Queue empty!\n");
        return;
    }
    int data = queue->arr[queue->rd_ptr];
    queue->rd_ptr = (queue->rd_ptr + 1) % queue->sz;
    queue->cnt--;
    printf("Data read = %d\n", data);
    return;
}

void display_queue(cq* queue) {
    if(queue->cnt == 0) {
        printf("Queue empty!\n");
        return;
    }
    int n = queue->cnt;
    int rd = queue->rd_ptr;
    printf("Queue elements are: ");
    while(n) {
        printf("%d ", queue->arr[rd]);
        n--;
        rd = (rd + 1) % queue->sz;
    }
    printf("\n");
    return;
}

int main() {
    int size = 6;
    cq* queue = init_buffer(size);

    write_queue(queue, 1);
    write_queue(queue, 2);
    write_queue(queue, 3);
    write_queue(queue, 4);
    write_queue(queue, 5);
    write_queue(queue, 6);
    write_queue(queue, 7);

    display_queue(queue);

    read_queue(queue);
    read_queue(queue);

    display_queue(queue);
    
    write_queue(queue, 7);
    
    display_queue(queue);
    
    return 0;
}
