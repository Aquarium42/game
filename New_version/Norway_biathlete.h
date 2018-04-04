#include"Biathlete.h"
#include<iostream>

class NorwayBiathlete : public Biathlete
{
public:
	
	void info() {
		std::cout << "NorwayBiathlete info" << std::endl;
		std::cout << "speed = " << speed << ". accuracy =" << accuracy << "energy = " << energy << std::endl;

	}
	void shoot() {
		std::cout << "Norway shoot!!!" << std::endl;
	}
};