// C program to demonstrate that the pointers cannot point
// to bit field members
#include <stdio.h>
struct test {
	unsigned int x : 5;
	unsigned int y : 5;
	unsigned int z;
};
int main()
{
	struct test t;

	// Uncommenting the following line will make
	// the program compile and run
	//printf("Address of t.x is %p", &t.x);

	// The below line works fine as z is not a
	// bit field member
	printf("Address of t.z is %p", &t.z);
	return 0;
}

/*
// C Program to show what happends when out of range value
// is assigned to bit field member
#include <stdio.h>

struct test {
	// Bit-field member x with 2 bits
	unsigned int x : 2;
	// Bit-field member y with 2 bits
	unsigned int y : 2;
	// Bit-field member z with 2 bits
	unsigned int z : 2;
};

int main()
{
	// Declare a variable t of type struct test
	struct test t;
	// Assign the value 5 to x (2 bits)
	t.x = 5;

	// Print the value of x
	printf("%d", t.x); //implementation-dependent

	return 0;
}
*/

/*
// C Program to illustrate that we cannot have array bit
// field members
#include <stdio.h>
 
// structure with array bit field
struct test {
    unsigned int x[10] : 5;
};
 
int main() {}
*/
