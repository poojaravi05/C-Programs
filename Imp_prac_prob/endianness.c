#include <stdio.h>
/*
Address:   00   01   02   03
Data:      12   34   56   78
12 - MSB at lower address 00
78 - LSB at higher address 03

Little Endian - LSB is stored in smaller address - 78 56 34 12
Big Endian - LSB is stored in higher address - 12 34 56 78
*/
int main()
{
    int x = 0x43210;
    char* c = (char*)&x;
    printf("*c is: 0x%x\n", *c);
    if(*c == 0x10) {
        printf("Little Endian\n");
    }
    else{
        printf("Big Endian\n");
    }
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef enum {
    FALSE = 0,
    TRUE,
} BOOL;


BOOL is_small_endian() {
	uint32_t num = 1;
	uint8_t byte;
	
	// examine the first byte memory of the 4-byte uint32_t
	byte = *((uint8_t*) &num);

	return (byte == 1) ? TRUE : FALSE;
}

void mem_layout() {
	int num = 0x01234567;
	char *byte;
	int i;

	byte = (char*) &num;
	for (i = 0; i < sizeof(num); i++) {
		printf("Byte pos: %d, content: %02x\n", i, byte[i]);
	}
}

int main (int argc, char *argv[]) {

	mem_layout();

	if (is_small_endian())
		printf("Systen is of small endian!\n");
    else
		printf("Systen is of big endian!\n");

	return 0;
}
*/