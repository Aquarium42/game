#pragma once
#include "Hockey_player.h"
#include <iostream>
#include"configure_russian_hockey.h"
#include <random>
class RussianHockey : public Hockey_player
{
public:
	void info() {
		std::cout << "RussianHockey info" << std::endl;
		std::cout << "endurance = " << endurance << ". score =" << score << "energy = " << energy << std::endl;

	}

	void score_goal() {
		if (energy > minus_energy) {
			if (energy / 10 + accuracy + endurance > 20) {
				std::cout << "EEeee, you score a goal!NORWAY!!!";
				score += 1;
			}
			else if (energy / 10 + accuracy + endurance > 10) {
				std::mt19937 twister(72);
				std::uniform_int_distribution<int> uniformInt(0, 1);
				int score_now = uniformInt(twister);
				score += score_now;
			}
			else {
				cout << "OUUU, the puck flew past. :(( " << endl;
			}

			energy -= minus_energy;
		}
		else {
			cout << "'I'm falling! I can't do it :(' " << endl;
		}

	}
private:
	const int accuracy = accuracy_;
	const int endurance = endurance_;
};
