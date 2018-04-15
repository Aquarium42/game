#pragma once
#include <iostream>
#include "Figure_skater.h"
#include "configure_russian_figure_skater.h"
#include <random>
using namespace std;
class RussianSkater : public Figure_skater
{
public:
	void perform_national_middle() {
		if (energy > 0) {
			std::mt19937 twister(12);
			int min_can = 0;
			int max_can = min(skills / 5 + endurance / 5 + energy / 15, 10);
			std::uniform_int_distribution<int> uniformInt(min_can, max_can);
			std::cout << "WAAAYY!!! Russia!!!" << std::endl;
			int score_now = uniformInt(twister);
			score += score_now * 2;
			energy -= 15;
		}
		else {
			cout << "'I'm tide!!!! It is too difficult for me!' " << endl;
		}
	}
	void perform_national_hard() {
		if (energy > 0) {
			std::mt19937 twister(52);
			int min_can = skills / 7 + endurance / 7 + energy / 85;
			int max_can = min(skills / 3 + endurance / 3 + energy / 25, 10);
			std::uniform_int_distribution<int> uniformInt(min_can, max_can);
			std::cout << "WAAAYY!!!R U S S I A !!!"<<endl;
				cout<<"AMAZING!!!!! PERFECT!!!" << std::endl;
			int score_now = uniformInt(twister);
			score += score_now * 5;
			energy -= 30;
		}
		else {
			cout << "'I'm falling! I can't do it :(' " << endl;
		}
	}
	void info() {
		std::cout << "RussianSkater info" << std::endl;
		std::cout << "endurance = " << endurance << "score =" << score << "energy = " << energy << std::endl;
	}
protected:
	const int skills = skills_;
	const int endurance = endurance_;
};