//memdup is not a part of C library. It is similar to strdup().

void* memdup(const void* mem, size_t size) {
    // 1. Allocate a new block of memory
    void* out = malloc(size);
    
    // 2. If allocation succeeded, copy the original data
    if (out != NULL) {
        memcpy(out, mem, size);
    }
    
    // 3. Return the pointer to the new copy
    return out;
}
