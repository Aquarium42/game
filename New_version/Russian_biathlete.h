#pragma once
#include"Biathlete.h"
#include <iostream>
#include<random>
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
		std::mt19937 twister(23);
		int min_can = min(accuracy / 4 + energy / 40, 4) - 1;
		int max_can = min(min_can, 4);
		std::uniform_int_distribution<int> uniformInt(min_can, max_can);
		std::cout << "Russia shoot!!!" << std::endl;
		int score_now = uniformInt(twister);
		score += score_now;
		cout << "new_score " << score << endl;
		energy -= score_now * 5;
	}
private:
	const int accuracy = accuracy_;
};
