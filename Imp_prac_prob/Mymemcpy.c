#include <stdio.h>
#include <string.h>

void mymemcpy(void* dest, void* src, size_t n) {
    char* csrc = (char*)src;
    char* cdest = (char*)dest;
    
    for(int i = 0; i < n; i++) {
        cdest[i] = csrc[i];
    }
}
//memcpy() leads to problems when source and destination addresses overlap as
//memcpy() simply copies data one by one from one location to another.

int main()
{
    char csrc[] = "Something";
    //char cdest[20];
    char cdest[20] = "Copied";
    int size = strlen(csrc) + 1;
    
    printf("Before: csrc = %s, cdest = %s\n", csrc, cdest);
    //mymemcpy(cdest, csrc, size); //Something
    mymemcpy(cdest+6, csrc, size); //CopiedSomething
    printf("After: csrc = %s, cdest = %s\n", csrc, cdest);
    printf("Copied string is %s\n", cdest);
    
    int isrc[] = {10, 20, 30, 40};
    int idest[10];
    int n = sizeof(isrc) / sizeof(isrc[0]);
    
    mymemcpy(idest, isrc, sizeof(isrc));
    printf("\nCopied array is "); 
    for (int i = 0; i < n; i++) 
        printf("%d ", idest[i]); 
    return 0; 
}