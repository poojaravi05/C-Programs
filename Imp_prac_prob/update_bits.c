//update bits in register with new val
/*
  update register bits 4-7
  clear any bits in register in that positions - (*reg & ~mask)
  extract the val bits - (val & 0x0F) << 4
  OR them.
*/

void set_bits(uint32_t *reg, uint8_t val) {
    uint32_t mask = (0x0F << 4);
    *reg = (*reg & ~mask) | ((val & 0x0F) << 4);
}
