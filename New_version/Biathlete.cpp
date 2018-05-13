#include "stdafx.h"
#include "Biathlete.h"
int Biathlete::get_score() {
	return score;
}
bool Biathlete::isenergy() {
	if (energy > 0)
		return true;
	else return false;
}
void Biathlete::accelerate() {
	if (energy >= 10) {
		speed += 5;
		energy -= 10;
	}
}
void Biathlete::slow_down() {
	speed -= 5;
	energy += 5;
}