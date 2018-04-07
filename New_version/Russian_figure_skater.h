#include "Figure_skater.h"
#include "configure_russian_figure_skater.h"
#include <iostream>
class RussianSkater : public Figure_skater
{
public:
	void info() {
		std::cout << "RussianSkater info" << std::endl;
		std::cout << "endurance = " << endurance << "skills =" << skills << "energy = " << energy << std::endl;
	}
private:
	const int skills = skills_;
	const int endurance = endurance_;
};