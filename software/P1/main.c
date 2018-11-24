#include <unistd.h>
#include "sys/alt_stdio.h"
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "lcd.h"
#include "uart.h"

int main() {
	lcd_init();

	uart_send(WIFI_MODE);
	uart_send(WIFI_CONNECT);


	char opcoes[5][7]   = {"Menu 01", "Menu 02", "Menu 03", "Menu 04", "Menu 05"};
	char submenu[5][11] = {"Mensagem 01", "Mensagem 02", "Mensagem 03", "Mensagem 04", "Mensagem 05"};

	int isSubMenu = 0;
	int estadoBotao = 0;
	int estado = 0;
	int menu = 0;

	while(1){
		estadoBotao = IORD(PI_BASE,0);
		usleep(100000);

		switch(estadoBotao){
			case 7:
				if(!isSubMenu) {
					if(menu < 4) menu += 1;
					else         menu  = 1;

					estado = 1;
				}

				break;

			case 11:
				if(!isSubMenu){
					if(menu > 0) menu -= 1;
					else  		 menu  = 4;

					estado = 1;
				}

				break;

			case 13:
				if(!isSubMenu) {
					isSubMenu = 1;
					estado    = 1;
				}

				break;

			case 14:
				if(isSubMenu) {
					isSubMenu = 0;
					estado    = 1;
				}

				break;
		}

		if(estado) {
			if(isSubMenu) {
				lcd_print(submenu[menu], 11);
				IOWR(PO_BASE, 0, menu);

				uart_send(TCP_CONNECT);
				usleep(100000);

				uart_send(MQTT_CONNECT_SIZE); uart_send(MQTT_CONNECT);
				usleep(100000);

				uart_send(MESSAGE_SIZE);
				if(menu == 0)      uart_send(MESSAGE_0);
				else if(menu == 1) uart_send(MESSAGE_1);
				else if(menu == 2) uart_send(MESSAGE_2);
				else if(menu == 3) uart_send(MESSAGE_3);
				else 			   uart_send(MESSAGE_4);
				usleep(100000);

				uart_send(MQTT_DISCONNECT_SIZE); uart_send(MQTT_DISCONNECT);
				usleep(100000);

				uart_send(TCP_DISCONNECT);

			}else {
				lcd_print(opcoes[menu], 7);
				IOWR(PO_BASE, 0, 15);
			}

			estado = 0;
		}
	}

	return 0;
}
