#include <Template.h>

void rasenmaeher();

void main() {
	initMuster();
	initTimer();
	rasenmaeher();
}

void rasenmaeher() {
	while (1) {
		if (DISTANCE < 100) {
			obstacle();
			makeModi();
		} else {
			MOTOR = getMotorSettings();
			delay();
			makeModi();
		}
	}
}