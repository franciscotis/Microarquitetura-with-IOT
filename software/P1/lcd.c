#include <unistd.h>
#include "system.h"

void lcd_init() {
	usleep(15000);
	ALT_CI_LCD(0,0x38);

	usleep(4100);
	ALT_CI_LCD(0,0x38);

	usleep(100);
	ALT_CI_LCD(0,0x38);

	usleep(5000);
	ALT_CI_LCD(0,0x38);

	usleep(100);
	ALT_CI_LCD(0,0x08);

	usleep(100);
	ALT_CI_LCD(0,0x0C);

	usleep(100);
	ALT_CI_LCD(0,0x06);

	usleep(100);
	ALT_CI_LCD(0,0x02);

	usleep(2000);
	ALT_CI_LCD(0,0x01);

	usleep(2000);
}

void lcd_print(char m[16], int n) {
	usleep(2000);
	ALT_CI_LCD(0,0x02);

	usleep(2000);
	ALT_CI_LCD(0,0x01);

	for(int i = 0; i < n; i++) {
		usleep(2000);
		ALT_CI_LCD(1,m[i]);
	}

	usleep(2000);
	ALT_CI_LCD(0,0x00);
}
