#include"Biathlete.h"
#include <iostream>
class RussianBiathlete : public Biathlete
{
public:
	RussianBiathlete() {
		speed = 9;
	}
	void info() {
		std::cout << "RussianBiathlete info:" << std::endl;
		std::cout << "speed = " << speed << ". accuracy =" << accuracy << "energy = " << energy << std::endl;
	}
	void shoot() {
		std::cout << "Russia shoot!!!" << std::endl;
	}

private:
	const int accuracy = 8;
};
