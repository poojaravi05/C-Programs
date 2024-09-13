#include <stdio.h>

int main()
{
    /*
    const char *ch_ptr;
    char ch_1 = 'A';
    char ch_2 = 'B';
    
    ch_ptr = &ch_1;
    printf("ch_ptr = %p, *ch_ptr = %c\n", ch_ptr, *ch_ptr);
    
    ch_ptr = &ch_2;
    printf("ch_ptr = %p, *ch_ptr = %c\n", ch_ptr, *ch_ptr);
    
    //*ch_ptr = 'C'; 
    //printf("ch_ptr = %p, *ch_ptr = %c\n", ch_ptr, *ch_ptr);
    */
    
    
    char ch_1 = 'A';
    char ch_2 = 'B';
    
    char *const ch_ptr = &ch_1;
    printf("ch_ptr = %p, *ch_ptr = %c\n", ch_ptr, *ch_ptr);
    
    //ch_ptr = &ch_2;
    //printf("ch_ptr = %p, *ch_ptr = %c\n", ch_ptr, *ch_ptr);
    
    *ch_ptr = 'C'; 
    printf("ch_ptr = %p, *ch_ptr = %c\n", ch_ptr, *ch_ptr);
    
    
    return 0;
}