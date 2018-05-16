#pragma once
#include"Hockey_player.h"
#include <iostream>
#include"configure_norway_hockey.h"
#include <random>
class NorwayHockey : public Hockey_player
{
public:
	void info() {
		std::cout << "NorwayHockey info" << std::endl;
		std::cout << "endurance = " << endurance << ". score =" << score << "energy = " << energy << std::endl;
	}
	void score_goal() {
		if (energy > minus_energy) {
			if (energy / 10 + accuracy*0.5 + endurance*0.5 > 15) {
				std::cout << " goal!NORWAY!!!" << endl;
				score += 1;
			}
			else if (energy / 10 + accuracy*0.5 + endurance*0.5 >= 11) {
				int score_now = rand() % (2);
				score += score_now;
			}
			else {
				cout << "OUUU, the puck flew past. :(( " << endl;
			}

		energy -= minus_energy;
		}
		else {
			cout << "'I'm falling! I can't do it :(' " << endl;
			energy = -1;

		}
		
	}
private:
	const int accuracy = accuracy_;
	const int endurance = endurance_;

};

