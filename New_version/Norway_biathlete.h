#pragma once
#include"Biathlete.h"
#include"configure_norway_biathlete.h"
#include<iostream>
#include <random>

class NorwayBiathlete : public Biathlete
{
public:
	NorwayBiathlete() {
		speed = speed_;
	}

	void info() {
		std::cout << "NorwayBiathlete info" << std::endl;
		std::cout << "speed = " << speed << "score"<<score<< " energy "<<energy<< std::endl;

	}
void shoot() {
		std::mt19937 twister(42);
		int min_can = min(accuracy/4 + energy / 40, 4) - 1;
		int max_can = min(min_can , 4);
		std::uniform_int_distribution<int> uniformInt(min_can, max_can);
		std::cout << "Norway shoot!!!" << std::endl;
		int score_now = uniformInt(twister);
		score += score_now;
		cout << "new_score " << score << endl;
		energy -= score_now * 5;
	}
private:
	const int accuracy = accuracy_;
};