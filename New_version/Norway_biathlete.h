#include"Biathlete.h"
#include"configure_norway_biathlete.h"
#include<iostream>

class NorwayBiathlete : public Biathlete
{
public:
	NorwayBiathlete() {
		speed = speed_;
	}
	void info() {
		std::cout << "NorwayBiathlete info" << std::endl;
		std::cout << "speed = " << speed << ". accuracy =" << accuracy << "energy = " << energy << std::endl;

	}
	void shoot() {
		std::cout << "Norway shoot!!!" << std::endl;
	}
private:
	const int accuracy = accuracy_;
};