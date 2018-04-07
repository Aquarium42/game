#include"Hockey_player.h"
#include <iostream>
#include"configure_norway_hockey.h"
class NorwayHockey : public Hockey_player
{
public:
	void info() {
		std::cout << "NorwayHockey info" << std::endl;
		std::cout << "endurance = " << endurance << ". accuracy =" << accuracy << "energy = " << energy << std::endl;
	}
	void score_goal() {
		std::cout << "EEeee, you score a goal!NORWAY!!!";//потом ее надо будет доработать
	}
private:
	const int accuracy = accuracy_;
	const int endurance = endurance_;

};

