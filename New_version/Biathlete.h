#pragma once
#include<memory>
#include"Unit.h"
class Biathlete: public Unit
{
protected:
	int speed;
	int energy = 100;
	int score = 0;
	
public:
	int get_score() {
		return score;
	}
	virtual void shoot() = 0;
	bool isenergy() {
		if (energy > 0)
			return true;
		else return false;
	}
	void accelerate() {
		if (energy >= 10) {
			speed += 5;
			energy -= 10;
		}
	}
	void slow_down() {
		speed -= 5;
		energy += 5;
	}
	virtual void info() = 0;
	virtual ~Biathlete() {}
};
