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
			if (energy / 10 + accuracy*0.5 + endurance*0.5 > 18) {
				std::cout << "GOAL RUSSIA!!!" << endl;
				score += 1;
			}
			else  {
				int score_now = rand() % (2);
				score += score_now;
				if (score_now == 0)
				{
					cout << "OUUU, the puck flew past. :(( " << endl;
				}
				else { cout << "goal!" << endl; }
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
