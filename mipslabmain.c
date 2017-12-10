/* mipslabmain.c

   This file written 2015 by Axel Isaksson,
   modified 2015 by F Lundevall

   Latest update 2015-08-28 by F Lundevall

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <stdlib.h>
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */
#include "project.h"

int main(void) {
	/* Set up peripheral bus clock */
    /* OSCCONbits.PBDIV = 1; */
    OSCCONCLR = 0x100000; /* clear PBDIV bit 1 */
	OSCCONSET = 0x080000; /* set PBDIV bit 0 */
	
	/* Set up output pins */
	AD1PCFG = 0xFFFF;
	ODCE = 0x0;
	TRISECLR = 0xFF;
	PORTE = 0x0;
	
	/* Output pins for display signals */
	PORTF = 0xFFFF;
	PORTG = (1 << 9);
	ODCF = 0x0;
	ODCG = 0x0;
	TRISFCLR = 0x70;
	TRISGCLR = 0x200;
	
	/* Set up input pins */
	TRISDSET = (1 << 8);
	TRISFSET = (1 << 1);
	
	/* Set up SPI as master */
	SPI2CON = 0;
	SPI2BRG = 4;
	/* SPI2STAT bit SPIROV = 0; */
	SPI2STATCLR = 0x40;
	/* SPI2CON bit CKP = 1; */
    SPI2CONSET = 0x40;
	/* SPI2CON bit MSTEN = 1; */
	SPI2CONSET = 0x20;
	/* SPI2CON bit ON = 1; */
	SPI2CONSET = 0x8000;
	
	display_init();
	display_update();
	
	// display_image(0, icon);
	// display_image(32, icon);
	// display_image(64, icon);
	// display_image(96, icon);
	// enable_pixel(0, 0);
	// enable_pixel(32, 0);
	// enable_pixel(64, 0);
	// enable_pixel(96, 0);
	// enable_pixel(0, 16);
	// enable_pixel(32, 16);
	// enable_pixel(64, 16);
	// enable_pixel(96, 16);

	// int i;
	// for(i = 0; i < 128; i++) enable_pixel(i, 0);
	// for(i = 0; i < 128; i++) enable_pixel(i, 8);
	// for(i = 0; i < 128; i++) enable_pixel(i, 16);
	// for(i = 0; i < 128; i++) enable_pixel(i, 31);

	display_screen(screen);
	display_update();

	// display_update();
	

	labinit(); /* Do any lab-specific initialization */
	
	// int btns = getbtns();
	// char buf[8];
	// display_string(1, buf);

	State state = MENU;

	run();
	return 0;
}
