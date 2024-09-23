#include <stdio.h>
#include <stdint.h>

//uintptr cannot be used to dereference
//it canbe best to play with byte addresses

struct __attribute__((packed)) test {
	// Unsigned integer member x
	unsigned int x;
	// Bit-field member y with 33 bits
	//long int y : 33; //error
	// Unsigned integer member z
	unsigned int z;
};

int main()
{
	// Declare a variable t of type struct test
	struct test t;
	printf("sizeof t = %lu\n", sizeof(t));
	// Pointer to unsigned int, pointing to member x
	uintptr_t ptr1 =(uintptr_t)&t.x;
	printf("x address: %ld\n", ptr1);
	// Pointer to unsigned int, pointing to member z
	uintptr_t ptr2 = (uintptr_t)&t.z;
	//printf("y address: %p\n", (int *)&t.y);
	printf("z address: %ld\n", ptr2);

	// Print the difference between the two pointers
	printf("%ld", ptr2 - ptr1);

	return 0;
}
