#include <Template.h>

void driveBack();
void makeModi();
void drive(char dir);

const unsigned char MODI[] = {LEFT + RIGHT, LEFT, LEFT, LEFT + RIGHT, RIGHT, RIGHT, LEFT + RIGHT, LEFT};

unsigned char activ = 1;

char isActiv() {
	return activ;
}

void makeModi() {
	if (havePlace() == 0) {
		if (activ == 1) {
			driveBack();
			reverseEntrys(); // calculate the way back.
			activ = 2;
		} else if (activ == 2) {
			drive(RIGHT + LEFT);
			reverseEntrys();
			activ = 0;
		}
	}
}

void initMuster() {
	int i;
	while (havePlace() == 1) {
		for (i = 0; i < 8; i++) {
			if (havePlace() == 1) {
				addMovement(MODI[i]);
			}
		}
	}
	drive(RIGHT + LEFT);
}

void nextMove() {
	drive(getMovement());
	incrementIndex();
	makeModi();
}

void obstacle() {
	changeCurrentMovement(LEFT);
	drive(LEFT);
	makeModi();
}

void driveBack() {
	drive(RIGHT);
	drive(RIGHT);
	drive(RIGHT);
	drive(LEFT);
}

void drive(char dir) {
	MOTOR = dir;
	delay();
}