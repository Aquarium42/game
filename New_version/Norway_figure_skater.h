#include<iostream>
#include"Figure_skater.h"
class NorwaySkater : public Figure_skater
{
public:
	NorwaySkater() {
		skills = 10;
		endurance = 8;
	}
	void info() {
		std::cout << "NorwaySkater info" << std::endl;
		std::cout << "endurance = " << endurance << "skills =" << skills << "energy = " << energy << std::endl;
	}
};
