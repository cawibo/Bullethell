/* mipslabwork.c

   This file written 2015 by F Lundevall

   This file should be changed by YOU! So add something here:

   This file modified 2015-12-24 by Ture Teknolog 

   Latest update 2015-08-28 by F Lundevall

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */


int mytime = 0x5957;


char textstring[] = "text, more text, and even more text!";

/* Interrupt Service Routine */
void user_isr( void )
{
  return;
}

/* Lab-specific initialization goes here */
void labinit( void )
{
  TRISE &= ~0xff;
  TRISD = TRISD | 0x0fe0;

  PORTE = 0;
}

/* This function is called repetitively from the main program */
void labwork( void )
{
  delay( 1000 );

  int btns = getbtns();
  if( btns != 0 ) {
    int sw = getsw();
    if( ( (btns & 0x4) >> 2) == 1 ) {
      mytime = (mytime & 0x0fff) + (sw << 12);
    }
    if( ( (btns & 0x2) >> 1) == 1 ) {
      mytime = (mytime & 0xf0ff) + (sw << 8);
    }
    if( (btns & 0x1) == 1 ) {
      mytime = (mytime & 0xff0f) + (sw << 4);
    }
  }

  time2string( textstring, mytime );
  display_string( 3, textstring );
  display_update();
  tick( &mytime );
  PORTE += 1;
  display_image(96, icon);
}
