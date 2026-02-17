#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <pthread.h>

#define BLOCKS 32
#define SIZE  64

typedef struct mempool {
    uint8_t buff[BLOCKS][SIZE]; // complete memory bytes
    void* free_mem[BLOCKS]; // buffer of available addresses
    int wr_ptr; // Write index -> for freeing
    int rd_ptr; // Read index -> for allocating
    int cnt; // to keep track of allocation space
} mempool;

mempool pool;

pthread_mutex_t mutex;

void pool_init(void) {
    pool.cnt = BLOCKS;
    pool.rd_ptr = 0;
    pool.wr_ptr = 0;

    //Before initializing any memory, all blocks will be free. So storing all available address in the buffer.
    for (int i = 0; i < BLOCKS; i++) {
        pool.free_mem[i] = &pool.buff[i][0];
    }
}

void* pool_alloc(void) {
    pthread_mutex_lock(&mutex);

    if (pool.cnt == 0) {
        printf("Pool is empty!!\n");
        pthread_mutex_unlock(&mutex);
        return NULL;
    }

    // Get the address from the current read position
    void* ptr = pool.free_mem[pool.rd_ptr];
    
    // Move the read pointer, wrap around if at the end -> like a circular buffer
    pool.rd_ptr = (pool.rd_ptr + 1) % BLOCKS;
    pool.cnt--;

    pthread_mutex_unlock(&mutex);
    return ptr;
}

int pool_free(void* ptr) {
    if (ptr == NULL) {
        return -1;
    }

    pthread_mutex_lock(&mutex);

    // Check if the ptr exists or not within the buffer
    if (ptr < (void*)pool.buff || ptr >= (void*)(pool.buff + BLOCKS)) {
        pthread_mutex_unlock(&mutex);
        return -1;
    }

    // check for double free: search the free_mem to see if this address is already there
    for (int i = 0; i < BLOCKS; i++) {
        // check for slots currently in free buffer
        if (pool.cnt > 0 && pool.free_mem[(pool.rd_ptr + i) % BLOCKS] == ptr) {
            pthread_mutex_unlock(&mutex);
            return -1; // present in free list, so it's a double free.
        }
    }

    // Put the address back into the free buffer after freeing
    pool.free_mem[pool.wr_ptr] = ptr;
    pool.wr_ptr = (pool.wr_ptr + 1) % BLOCKS;
    pool.cnt++;

    pthread_mutex_unlock(&mutex);
    return 0;
}

int pool_available(void) {
    return pool.cnt;
}

int main() {
    pthread_mutex_init(&mutex, NULL);

    pool_init();
    //printf("Total blocks available: %u\n", pool_available());
    
    void* block1 = pool_alloc();
    void* block2 = pool_alloc();
    //printf("Total blocks available after allocating 2 blocks: %u\n", pool_available());
    
    pool_free(block1);
    int res = pool_free(block1); // This returns -1, as double free was detected.

    /*
    if (res == -1) {
        printf("Detected double free for same block!\n");
    }
    */

    pthread_mutex_destroy(&mutex);
    
    return 0;
}