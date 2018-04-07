#include "Hockey_player.h"
#include <iostream>
#include"configure_russian_hockey.h"

class RussianHockey : public Hockey_player
{
public:
	void info() {
		std::cout << "RussianHockey info" << std::endl;
		std::cout << "endurance = " << endurance << ". accuracy =" << accuracy << "energy = " << energy << std::endl;

	}
	void score_goal() {
		std::cout << "EEeee, you score a goal! RUSSIA!!!";//потом ее надо будет доработать
	}
private:
	const int accuracy = accuracy_;
	const int endurance = endurance_;
};
