#include <Storage.h>

void optimizeWay(char direction);

unsigned char index = 0;

struct {
	unsigned int way : 2;
} Entry[MAX];

void addMovement(char dir) {
	Entry[index].way = dir;
	index++;
}

char getMovement() {
	return (Entry[index].way);
}

void incrementIndex() {
	index++;
}

void changeCurrentMovement(char directionValue) {
	Entry[index].way = directionValue;
	index++;
}

char havePlace() {
	char b;
	if (index == MAX) {
		b = 0;
		index = 0;
	} else {
		b = 1;
	}
	return b;
}

void makeTheWay() {
	optimizeWay(LEFT);
	optimizeWay(RIGHT);
}

void optimizeWay(char direction) {
		int i;
		for (i = 0; i < MAX - 3; i++) {
			if (Entry[i].way == direction) {
				if (Entry[i + 1].way == direction) {
					if (Entry[i + 2].way == direction) {
						if (direction == LEFT) {
							Entry[i].way = RIGHT;
						} else {
							Entry[i].way = LEFT;
						}
						Entry[i + 1].way = LEFT + RIGHT;
						Entry[i + 2].way = LEFT + RIGHT;
					}
				}
			}
		}
}