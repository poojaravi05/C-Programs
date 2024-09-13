#include <stdio.h>
#include <string.h>

int main()
{
    char name1[30]; // stack
    //char name[20] = "Revanth";
    strcpy(name1, "Revanth");
    printf("%s\n", name1);
    name1[0] = 'H';
    printf("%s\n", name1);
    
    const char *name2; // Read-only - contents cannot be modified, only address can be chnaged
    //const char *name = "Pooja";
    name2 = "Pooja";
    printf("%s\n", name2);
    //name2[0] = 'R';
    //printf("%s", name2);
    name2 = "Manu";
    printf("%s", name2);
    
    return 0;
}