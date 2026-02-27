#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>

void *aligned_malloc(size_t sz, uint32_t alignment)
{
    /*
     * sz: actual size requested by user
     * alignment: extra space to accommadate alignment
     * 1 : Additional 1 byte to store the offset 
     */
    
    uint8_t *ptr = (uint8_t *) malloc(sz + alignment + 1);
    assert(ptr);
    
    // Always leave 1 byte space to store offset
    uint8_t *aligned = ptr + 1;
    
    /*
     * treat aligned as a number and check if it is aligned with the alignment requested.
     * if not, keep moving by one byte until it becomes aligned prefectly
     */
    while ((uintptr_t)aligned % alignment != 0)
    {
        aligned++;
    }
    
    //Once aligned calculate the offset.
    //distance between aligned ptr and actual allocated memory ptr
    uint8_t offset = aligned - ptr;
    
    //Store the offset just 1 byte before the aligned mem address.
    *(aligned - 1) = offset;
    
    printf("%s: Initially assigned mem: %p, aligned: %p, alignment: %d, offset: %d\n",
                        __func__, ptr, aligned, alignment, offset);

    //Typecast to void * and send the aligned memory ptr.
    return (void *)aligned;
}

void aligned_free(void *i_ptr)
{
    //type cast the received input void ptr to byte type for easy ptr opetations.
    uint8_t *ptr = (uint8_t*) i_ptr;
    
    //We know that the previous byte stores the offset.
    uint8_t offset = *(ptr - 1); 
    
    //Calculate the actual allocated memory ptr, which needs to be freed.
    uint8_t *actual_mem_ptr = (ptr - offset);
    
    printf("%s: Aligned ptr: %p, actual mem ptr: %p, offset: %d\n", __func__, ptr, actual_mem_ptr, offset);
    free((void *)(actual_mem_ptr)); 
}

int main()
{
    int sz = 10, alignment = 32; //user input
    int *arr = (int *)aligned_malloc(sz, alignment);
    assert(arr);
    
    if ((uintptr_t)arr % alignment == 0)
    {
        printf("%s: Array: %p in perfect alignment: %d\n", __func__, arr, alignment);
    }
    else
    {
        printf("%s: Array: %p NOT IN alignment: %d\n", __func__, arr, alignment);
    }
    
    for (int i = 0; i < sz; i++)
    {
        arr[i] = i + 1;
        printf("arr[%d]: %d\n", i, arr[i]);
    }

    aligned_free(arr);
    
    return 0;
}
