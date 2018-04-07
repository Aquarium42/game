#include"Biathlete.h"
#include <iostream>
#include "configure_russian_biathlete.h"
class RussianBiathlete : public Biathlete
{
public:
	RussianBiathlete() {
		speed = speed_;
	}
	void info() {
		std::cout << "RussianBiathlete info:" << std::endl;
		std::cout << "speed = " << speed << ". accuracy =" << accuracy << "energy = " << energy << std::endl;
	}
	void shoot() {
		std::cout << "Russia shoot!!!" << std::endl;
	}

private:
	const int accuracy = accuracy_;
};
