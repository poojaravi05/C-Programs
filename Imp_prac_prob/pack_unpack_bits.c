// Assume Temp High bits are [10:13] and Low bits are [2:5]
uint32_t pack_bits(uint8_t high, uint8_t low) {
    uint32_t reg = 0;
    reg |= (uint32_t)(high & 0x0F) << 10;
    reg |= (uint32_t)(low & 0x0F) << 2;
    return reg;
}

uint16_t unpack_temp(uint32_t reg) {
    uint8_t high = (reg >> 10) & 0x0F;
    uint8_t low = (reg >> 2) & 0x0F;
    return (high << 4) | low;
}
