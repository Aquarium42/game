#pragma once
#include <iostream>
#include "Unit.h"
using namespace std;
class Figure_skater:public Unit
{public:
	int energy = 100;
	int score = 0;
	int get_score() {
		return score;
	}
	bool isenergy() {
		if (energy > 0) {
				return true;
			}
				else return false;

		}

	void perform_base_easy() {
		if (energy >= 5) {
			score += 5;
			energy -= 5;
		}
		else cout << "The sportsmen is tired! He can't do it. " << endl;
	}
	void perform_base_middle() {
		if (energy >= 10) {
			score += 10;
			energy -= 10;
		}
		else {
			cout << "It is too difficult for me! " << endl;
		}
	}
	virtual void perform_national_middle() = 0;
	virtual void perform_national_hard() = 0;
	virtual void info() = 0;
	virtual ~Figure_skater() {}
};