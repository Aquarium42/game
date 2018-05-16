#include "stdafx.h"
#include <iostream>
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
		std::cout << "Ohh, I'm faster !!!" << std::endl;
	}
}
void Biathlete::slow_down() {
	speed -= 5;
	energy += 5;

	std::cout << "EE, energy is increasing!!!" << std::endl;
}