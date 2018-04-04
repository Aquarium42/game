#include "Hockey_player.h"
#include <iostream>
class RussianHockey : public Hockey_player
{
public:
	RussianHockey() {
		accuracy = 8;
		endurance = 10;
	}
	void info() {
		std::cout << "RussianHockey info" << std::endl;
		std::cout << "endurance = " << endurance << ". accuracy =" << accuracy << "energy = " << energy << std::endl;

	}
	void score_goal() {
		std::cout << "EEeee, you score a goal! RUSSIA!!!";//потом ее надо будет доработать
	}
};
