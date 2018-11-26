#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "sys/alt_stdio.h"
#include "system.h"
#include "altera_avalon_jtag_uart_regs.h"
#include "altera_avalon_uart_regs.h"

void uart_write(char *d, int c) {
	int l = strlen(d);

    while(IORD_ALTERA_AVALON_UART_STATUS(RS232_BASE) != 0x40);

    for (int i = 0; i < l; i++) {
    	IOWR_ALTERA_AVALON_UART_TXDATA(RS232_BASE, d[i]);
    	usleep(1000);
    }

    if(c) {
    	IOWR_ALTERA_AVALON_UART_TXDATA(RS232_BASE, '\r');
    	usleep(1000);

    	IOWR_ALTERA_AVALON_UART_TXDATA(RS232_BASE, '\n');
    	usleep(1000);
    }
}

void uart_read() {
	char d;

    while(1) {
    	if(IORD_ALTERA_AVALON_UART_STATUS(RS232_BASE) & 0x80) {
    		d = IORD_ALTERA_AVALON_UART_RXDATA(RS232_BASE);
	        printf("%c", d);

	        if(d == 'K') return;
    	}
	}
}
