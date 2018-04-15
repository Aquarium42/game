#pragma once
#include "Unit.h"
class Hockey_player: public Unit
{
protected:
	int energy = 100;
	int score = 0;
	
public:
	int get_score() {
		return score;
	}
	bool isenergy() {
		if (energy > 0) {
			return true;
		}
		else return false;

	}

	virtual void score_goal() = 0;
	virtual void info() = 0;
	virtual ~Hockey_player()
	{}
};


