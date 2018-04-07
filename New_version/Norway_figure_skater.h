#include<iostream>
#include "configure_norway_figure_skater.h"
#include"Figure_skater.h"
class NorwaySkater : public Figure_skater
{
public:
	
	void info() {
		std::cout << "NorwaySkater info" << std::endl;
		std::cout << "endurance = " << endurance << "skills =" << skills << "energy = " << energy << std::endl;
	}
private:
	const int skills = skills_;
	const int endurance = endurance_;
};
