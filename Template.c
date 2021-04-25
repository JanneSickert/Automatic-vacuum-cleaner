#include <Template.h>

#define SIZE_MUSTER 8

void driveBack();
void drive(char dir);

const unsigned char MODI[] = {LEFT + RIGHT, LEFT, LEFT, LEFT + RIGHT, RIGHT, RIGHT, LEFT + RIGHT, LEFT};

unsigned char muster[SIZE_MUSTER];
unsigned int index = 0;
unsigned char motorModi;

char getMotorSettings() {
	return motorModi;
}

void optimizeWay(char direction) {
		int i;
		for (i = 0; i < SIZE_MUSTER - 2; i++) {
			if (muster[i] == direction) {
				if (muster[i + 1] == direction) {
					if (muster[i + 2] == direction) {
						if (direction == LEFT) {
							muster[i] = RIGHT;
						} else {
							muster[i] = LEFT;
						}
						muster[i + 1] = LEFT + RIGHT;
						muster[i + 2] = LEFT + RIGHT;
					}
				}
			}
		}
}

void makeTheWay() {
	optimizeWay(LEFT);
	optimizeWay(RIGHT);
}

void makeModi() {
	if (index == SIZE_MUSTER) {
		index = index - 1;
		driveBack();
		makeTheWay();
		index = 0;
	}
	motorModi = muster[index];
	index++;
}

void initMuster() {
	int i;
	while (index < SIZE_MUSTER) {
		for (i = 0; i < 8; i++) {
			if (index < SIZE_MUSTER) {
				muster[index] = MODI[i];
				index = index + 1;
			}
		}
	}
	index = 0;
}

void obstacle() {
	MOTOR = LEFT;
	muster[index] = LEFT;
	delay();
}

void driveBack() {
	MOTOR = RIGHT;
	delay();
	delay();
	delay();
	MOTOR = LEFT;
	delay();
	while (index > (-1)) {
		if (muster[index] == LEFT) {
			drive(RIGHT);
		} else if (muster[index] == RIGHT) {
			drive(LEFT);
		} else {
			drive(LEFT + RIGHT);
		}
		index--;
	}
}

void drive(char dir) {
	MOTOR = dir;
	delay();
}