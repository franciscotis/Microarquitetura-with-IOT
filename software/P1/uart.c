#include "sys/alt_stdio.h"
#include "system.h"
#include "altera_avalon_jtag_uart_regs.h"
#include "altera_avalon_uart_regs.h"

#define CR_LF "\r\n"

void uart_send(char *data) {
	alt_putstr(data);
	alt_putstr(CR_LF);

	char r;

    while(1){
    	if(IORD_ALTERA_AVALON_UART_STATUS(RS232_BASE) & 0x80) {
    		r = IORD_ALTERA_AVALON_UART_RXDATA(RS232_BASE);
    		IOWR_ALTERA_AVALON_JTAG_UART_DATA(JTAG_BASE, r);

    		if(r == 'K') {
    		    return;
    	    }
    	}
    }
}
