#include <stdio.h>

// Function to perform left rotation on a number
unsigned int leftRotate(unsigned int num, unsigned int rotations) {
    return (num << rotations) | (num >> (32 - rotations));
}

// Function to perform right rotation on a number
unsigned int rightRotate(unsigned int num, unsigned int rotations) {
    return (num >> rotations) | (num << (32 - rotations));
}

int main() {
    unsigned int num, rotations;

    printf("Enter a number: ");
    scanf("%u", &num);

    printf("Enter the number of rotations: ");
    scanf("%u", &rotations);

    printf("Left rotation of %u by %u bits: %u\n", num, rotations, leftRotate(num, rotations));
    printf("Right rotation of %u by %u bits: %u\n", num, rotations, rightRotate(num, rotations));

    return 0;
}

/*
#include <stdio.h>
#include <stdint.h>

// Function to perform left rotation on a number
uint32_t leftRotate(uint32_t num, uint32_t rotations) {
    return (num << rotations) | (num >> (32 - rotations));
}

// Function to perform right rotation on a number
uint32_t rightRotate(uint32_t num, uint32_t rotations) {
    return (num >> rotations) | (num << (32 - rotations));
}

int main() {
    uint32_t num, rotations;

    num = 0x1110;
    rotations = 2;

    printf("Left rotation of %x by %d bits: %X\n", num, rotations, leftRotate(num, rotations));
    printf("Right rotation of %x by %d bits: %x\n", num, rotations, rightRotate(num, rotations));

    return 0;
}
*/