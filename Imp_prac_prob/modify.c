#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_arr(int* arr, int n) {
    printf("Array = ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void modify_arr(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        arr[i] += 1;
    }
    printf("\n");
}

void print_str(char* str) {
    printf("Name = ");
    for(int i = 0; str[i] != '\0'; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}

void modify_str(char* str) {
    for(int i = 0; str[i] != '\0'; i++) {
        str[i] += 1;
    }
    printf("\n");
}

void print_char(char args) {
    printf("Given char = %c\n", args);
}

void modify_char(char* args) {
    *args += 1;
    printf("Modified char = %c\n", *args);
}

int main() {
    int new_arr[] = {1, 2, 3, 4, 5};
    int *arr = new_arr;
    int arr_sz = sizeof(new_arr)/sizeof(new_arr[0]);
    
    print_arr(arr, arr_sz);
    modify_arr(arr, arr_sz);
    print_arr(arr, arr_sz);
    
    char name[6] = "Pooja";
    
    print_str(name);
    modify_str(name);
    print_str(name);
    
    char single = 'C';
    
    print_char(single);
    modify_char(&single);
    print_char(single);
    
    
    return 0;
}
