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
		STATE = isActiv();
	}
	MOTOR = 0;
	makeTheWay();
}