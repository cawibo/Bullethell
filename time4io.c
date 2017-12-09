#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"

int getsw() {
	return (PORTD & 0x0f00) >> 8;
}

int getbtns() {
	return (PORTD & 0x00e0) >> 5;
}