#include"Hockey_player.h"
#include <iostream>
class NorwayHockey : public Hockey_player
{
public:
	NorwayHockey() {
		accuracy = 7;
		endurance = 7;
	};
	void info() {
		std::cout << "NorwayHockey info" << std::endl;
		std::cout << "endurance = " << endurance << ". accuracy =" << accuracy << "energy = " << energy << std::endl;
	}
	void score_goal() {
		std::cout << "EEeee, you score a goal!NORWAY!!!";//потом ее надо будет доработать
	}


};

