//Implement a fast ISR that receives a data packet from a serial interface and sets a flag for the main application to handle.

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdatomic.h>

#define sz 5

volatile uint8_t buff[sz];
volatile uint8_t wr_ptr = 0;
volatile uint8_t rd_ptr = 0;
atomic_uint cnt = 0;

volatile bool packet_ready = false;

volatile uint8_t UART_DATA_REG;

void isr() {
    int data = UART_DATA_REG;
    if(atomic_load(&cnt) < sz) {
        buff[wr_ptr] = data;
        wr_ptr = (wr_ptr + 1) % sz;
        atomic_fetch_add(&cnt, 1);
    }
    if(data == '\n') {
        packet_ready = true;
    }
    return;
}

void process_packet() {
    while(atomic_load(&cnt)) {
        uint8_t data = buff[rd_ptr];
        rd_ptr = (rd_ptr + 1) % sz;
        atomic_fetch_sub(&cnt, 1);
        printf("%c", data);
    }
    return;
}

/*
/* ISR */
void UART_RX_ISR(void)
{
    uint8_t data = UART_DATA_REGISTER;

    uint16_t next_head = (head + 1) % BUFFER_SIZE;

    /* Prevent overflow */
    if (next_head != tail)
    {
        rx_buffer[head] = data;
        head = next_head;
    }

    /* Example: newline indicates packet complete */
    if (data == '\n')
    {
        packet_ready = true;
    }
}

/* Main application */
void process_packet(void)
{
    while (tail != head)
    {
        uint8_t data = rx_buffer[tail];
        tail = (tail + 1) % BUFFER_SIZE;

        printf("%c", data);
    }
}
*/

int main() {
    UART_DATA_REG = 'H';
    isr();

    UART_DATA_REG = 'i';
    isr();

    UART_DATA_REG = '\n';
    isr();

    if (packet_ready)
    {
        process_packet();
        packet_ready = false;
    }

    return 0;
}
