#include "Figure_skater.h"
#include <iostream>
class RussianSkater : public Figure_skater
{
public:
	RussianSkater() {
		skills = 10;
		endurance = 8;
	}
	void info() {
		std::cout << "RussianSkater info" << std::endl;
		std::cout << "endurance = " << endurance << "skills =" << skills << "energy = " << energy << std::endl;
	}
};
