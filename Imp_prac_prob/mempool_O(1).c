#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <pthread.h>

#define BLOCKS 32
#define SIZE   64

typedef struct mempool {
    uint8_t buff[BLOCKS][SIZE];      // Actual memory bytes
    void* free_mem[BLOCKS];          // Buffer of available addresses
    bool is_used[BLOCKS];            // NEW: O(1) double-free tracker
    int wr_ptr;                      // Write index -> for freeing
    int rd_ptr;                      // Read index -> for allocating
    int cnt;                         // To keep track of available blocks
} mempool;

mempool pool;
pthread_mutex_t mutex;

void pool_init(void) {
    pool.cnt = BLOCKS;
    pool.rd_ptr = 0;
    pool.wr_ptr = 0;

    for (int i = 0; i < BLOCKS; i++) {
        pool.free_mem[i] = &pool.buff[i][0];
        pool.is_used[i] = false; // Initially, nothing is in use
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
    
    // Calculate index to mark it as "used"
    int index = ((uint8_t*)ptr - &pool.buff[0][0]) / SIZE;
    pool.is_used[index] = true;

    // Move the read pointer
    pool.rd_ptr = (pool.rd_ptr + 1) % BLOCKS;
    pool.cnt--;

    pthread_mutex_unlock(&mutex);
    return ptr;
}

int pool_free(void* ptr) {
    if (ptr == NULL) return -1;

    pthread_mutex_lock(&mutex);

    // 1. Calculate the block index using pointer math
    // (Target Address - Start Address) / Block Size
    uintptr_t offset = (uint8_t*)ptr - &pool.buff[0][0];
    int index = offset / SIZE;

    // 2. Safety: Is it within our buffer range and correctly aligned?
    if (index < 0 || index >= BLOCKS || (offset % SIZE != 0)) {
        pthread_mutex_unlock(&mutex);
        return -1; 
    }

    // 3. O(1) Double-free check using our flag array
    if (pool.is_used[index] == false) {
        pthread_mutex_unlock(&mutex);
        return -1; // Already free!
    }

    // 4. Mark as no longer used and return to free buffer
    pool.is_used[index] = false;
    pool.free_mem[pool.wr_ptr] = ptr;
    pool.wr_ptr = (pool.wr_ptr + 1) % BLOCKS;
    pool.cnt++;

    pthread_mutex_unlock(&mutex);
    return 0;
}

uint32_t pool_available(void) {
    return (uint32_t)pool.cnt;
}

int main() {
    pthread_mutex_init(&mutex, NULL);
    pool_init();
    
    printf("Initial blocks: %u\n", pool_available());

    void* b1 = pool_alloc();
    void* b2 = pool_alloc();
    printf("Allocated 2. Available: %u\n", pool_available());

    if (pool_free(b1) == 0) printf("Block 1 freed successfully.\n");
    
    // This now returns -1 instantly without a loop!
    if (pool_free(b1) == -1) printf("Double free on Block 1 detected!\n");

    pthread_mutex_destroy(&mutex);
    return 0;
}
