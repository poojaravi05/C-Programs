#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdalign.h>
#include <assert.h>

void * aligned_malloc(size_t align, size_t size);
void aligned_free(void * ptr);

// Convenience macro for memalign, the POSIX API
#define memalign(align, size) aligned_malloc(align, size)

typedef uint16_t offset_t; // Number of bytes we're using for storing the aligned pointer offset
#define PTR_OFFSET_SZ sizeof(offset_t)

#ifndef align_up
#define align_up(num, align) \
    (((num) + ((align) - 1)) & ~((align) - 1))
#endif

void * aligned_malloc(size_t align, size_t size)
{
    void * ptr = NULL;
    
    // We want it to be a power of two since
    // align_up operates on powers of two
    assert((align & (align - 1)) == 0);

    if(align && size)
    {
        /*
         * We know we have to fit an offset value
         * We also allocate extra bytes to ensure we 
         * can meet the alignment
         */
        uint32_t hdr_size = PTR_OFFSET_SZ + (align - 1);
        printf("hdr_size = %u\n",hdr_size);
        void * p = malloc(size + hdr_size);

        if(p)
        {
            printf("Actual malloc pointer p = %p Is aligned to %d ? %s\n", p, align, ((uintptr_t)p % align) == 0 ? "YES" : "NO");
            /*
             * Add the offset size to malloc's pointer 
             * (we will always store that)
             * Then align the resulting value to the 
             * target alignment
             */
            ptr = (void *) align_up(((uintptr_t)p + PTR_OFFSET_SZ), align);
            printf("After align up. ptr = %p. Is aligned to %d ? %s\n", ptr, align, ((uintptr_t)ptr % align) == 0 ? "YES" : "NO");

            // Calculate the offset and store it 
            // behind our aligned pointer
            offset_t *offset_ptr = (offset_t *)ptr - 1;
            printf("Offset store pointer. offset_ptr = %p\n", offset_ptr);
            *(offset_ptr) = (offset_t)((uintptr_t)ptr - (uintptr_t)p);
            printf("Offset value stored = %d\n", *(offset_ptr));

        } // else NULL, could not malloc
    } //else NULL, invalid arguments

    printf("Aligned memory allocated: ( %p )\n", ptr);
    return ptr;
}

void aligned_free(void * ptr)
{
    assert(ptr);

    /*
    * Walk backwards from the passed-in pointer 
    * to get the pointer offset. We convert to an offset_t 
    * pointer and rely on pointer math to get the data
    */
    offset_t offset = *((offset_t *)ptr - 1);
    printf("Offset value = %d\n", offset);

    /*
    * Once we have the offset, we can get our 
    * original pointer and call free
    */
    void * p = (void *)((uint8_t *)ptr - offset);
    printf("Actual pointer to be freed : ( %p )\n", p);
    free(p);
}

int main()
{
    int align = 16, size = 10;
    printf("Align = %d, Size = %d\n", align, size);
    char *c_ptr = (char *)aligned_malloc(align, size);
    if (c_ptr == NULL)
    {
        printf("Memory allocation error\n");
        return -1;
    }
    
    printf("c_ptr: %p Is aligned to %d ? %s\n", c_ptr, align, ((uintptr_t)c_ptr % align) == 0 ? "YES" : "NO");
    
    
    
    for (int i = 0; i < size; i++)
        c_ptr[i] = 'A' + i;
    
    for (int i = 0; i < size; i++)
        printf("%c ", c_ptr[i]);
        
    printf("\n");
    aligned_free(c_ptr);
}

