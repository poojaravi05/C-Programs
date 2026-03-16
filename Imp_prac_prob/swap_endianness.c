#include <stdio.h>

//swap endianness for 32-bit num
int swap_Endians(int value)
{
	int leftmost_byte;
	int left_middle_byte;
	int right_middle_byte;
	int rightmost_byte;
	int result;

	leftmost_byte = (value & 0x000000FF) >> 0;
	left_middle_byte = (value & 0x0000FF00) >> 8;
	right_middle_byte = (value & 0x00FF0000) >> 16;
	rightmost_byte = (value & 0xFF000000) >> 24;
	
	leftmost_byte <<= 24;
	left_middle_byte <<= 16;
	right_middle_byte <<= 8;
	rightmost_byte <<= 0;

	result = (leftmost_byte | left_middle_byte
			| right_middle_byte | rightmost_byte);

	return result;

	/*
	n = ((n << 8) & 0xFF00FF00) | ((n >> 8) & 0x00FF00FF);
    return (n << 16) | (n >> 16);
	*/

	/*
	leftmost_byte   = (n & 0x000000FF) << 24;
    leftmiddle_byte = (n & 0x0000FF00) << 8;
    rightmiddle_byte= (n & 0x00FF0000) >> 8;
    rightmost_byte  = (n & 0xFF000000) >> 24;
	
	return leftmost_byte | leftmiddle_byte | rightmiddle_byte | rightmost_byte;
	*/
}

//Function to swap bytes of a 16-bit unsigned integer
uint16_t swap_uint16(uint16_t val) {
    return (val << 8) | (val >> 8);
}

//swap bytes of a 64-bit number
uint64_t swap_uint64(uint64_t val) {
    val = ((val << 8)  & 0xFF00FF00FF00FF00ULL) | ((val >> 8)  & 0x00FF00FF00FF00FFULL);
    val = ((val << 16) & 0xFFFF0000FFFF0000ULL) | ((val >> 16) & 0x0000FFFF0000FFFFULL);
    return (val << 32) | (val >> 32);
}

//Alternate swap bytes of a 64-bit number
uint64_t swap_uint64_verbose(uint64_t val) {
    return ( (val & 0x00000000000000FFULL) << 56 ) |
           ( (val & 0x000000000000FF00ULL) << 40 ) |
           ( (val & 0x0000000000FF0000ULL) << 24 ) |
           ( (val & 0x00000000FF000000ULL) << 8  ) |
           ( (val & 0x000000FF00000000ULL) >> 8  ) |
           ( (val & 0x0000FF0000000000ULL) >> 24 ) |
           ( (val & 0x00FF000000000000ULL) >> 40 ) |
           ( (val & 0xFF00000000000000ULL) >> 56 );
}

void print_bits(uint64_t n) {
    int sz = (sizeof(n) * 8) + 1;
    char bits_array[sz];
    bits_array[sz-1] = '\0';
    uint64_t tmp = n;
    for(int i = sz-2; i >= 0; i--) {
        bits_array[i] = '0' + (n & 1);
        n >>= 1;
    }
    printf("%s: Bits: %s, num: 0x%llx\n", __func__, bits_array, tmp);
    return;
}

int main()
{
	int big_Endian = 0x12345678;
	int little_Endian = 0x78563412;

	int result1, result2;

	result1 = swap_Endians(big_Endian);

	result2 = swap_Endians(little_Endian);

	printf("big Endian to little: 0x%x\nlittle Endian to big: 0x%x\n",
		result1, result2);

	/*
	uint16_t n1 = 0x0102;
    uint64_t n1_cast = (uint64_t)n1;
    print_bits(n1_cast);
    uint16_t res1 = swap_endianness2(n1);
    uint64_t res1_cast = (uint64_t)res1;
    print_bits(res1_cast);
    printf("\n");
    
    uint32_t n2 = 0x01020304;
    uint64_t n2_cast = (uint64_t)n2;
    print_bits(n2_cast);
    uint32_t res2 = swap_endianness4(n2);
    uint64_t res2_cast = (uint64_t)res2;
    print_bits(res2_cast);
    printf("\n");
    
    uint64_t n3 = 0x0102030405060708;
    print_bits(n3);
    uint64_t res3 = swap_endianness8(n3);
    print_bits(res3);
	*/

	return 0;
}
