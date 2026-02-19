uint32_t reverse32_no_loops(uint32_t x) {
    x = ((x >> 1) & 0x55555555) | ((x & 0x55555555) << 1); // Swap bits
    x = ((x >> 2) & 0x33333333) | ((x & 0x33333333) << 2); // Swap 2-bit chunks
    x = ((x >> 4) & 0x0F0F0F0F) | ((x & 0x0F0F0F0F) << 4); // Swap nibbles
    x = ((x >> 8) & 0x00FF00FF) | ((x & 0x00FF00FF) << 8); // Swap bytes
    x = ( x >> 16             ) | ( x << 16             ); // Swap half-words
    return x;
}
