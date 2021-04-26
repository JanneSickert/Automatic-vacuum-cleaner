#include <Template.h>

void rasenmaeher();

void main() {
	initMuster();
	initTimer();
	rasenmaeher();
}

void rasenmaeher() {
	while (isActiv() > 0) {
		if (DISTANCE < 100) {
			obstacle();
		} else {
			nextMove();
		}
	}
	MOTOR = 0;
	makeTheWay();
}