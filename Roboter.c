#include <REG52.H>
#include <stdio.h>

#define MOTOR P0

#define RECHTS 1
#define LINKS 2
#define VORWAERTS 3
#define STOP 0

// Zeitverzögerung

const unsigned char LOOP_VALUE[] = {100, 50};
const unsigned char TR[] = {116, 0};

unsigned char loop[] = {0, 0};

void reloadLoop(char nr) {
	loop[nr] = LOOP_VALUE[nr];
}

void reload() {
	TH0 = TR[0];
	TL0 = TR[1];
}

void initTimer() {
	TMOD = 1;
	reload();
	IE = 0x82;
}

void restart() {
	TR0 = 0;
	reload();
	TR0 = 1;
}

void delay() {
	restart();
	while (loop[0] != 0);
	reloadLoop(0);
}

void timer_isr() interrupt 1 {
	TR0 = 0;
	TH0 = TR[0];
	TL0 = TR[1];
	if (loop[1] == 0) {
		loop[0] = loop[0] - 1;
		reloadLoop(1);
	}
	loop[1] = loop[1] - 1;
	if (loop[0] != 0) {
		TR0 = 1;
	}
}

// ---------------------

void vorwearts() {
    for (int i = 0; i < 5; ++i) {
        MOTOR = VORWAERTS;
        delay();
    }
    MOTOR = STOP;
}

void rechts() {
    MOTOR = RECHTS;
    delay();
    delay();
    MOTOR = STOP;
}

void links() {
    MOTOR = LINKS;
    delay();
    delay();
    MOTOR = STOP;
}

int main() {
    initTimer();
    while (true) {
        vorwearts();
        links();
        vorwearts();
        rechts();
    }
    return 0;
}