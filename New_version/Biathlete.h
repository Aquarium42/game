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
	int get_score();
	virtual void shoot() = 0;
	bool isenergy();
	void accelerate();
	void slow_down();
	virtual void info() = 0;
	virtual ~Biathlete() {}
};
