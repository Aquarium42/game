#pragma once
#include <iostream>
#include "Unit.h"
using namespace std;
class Figure_skater:public Unit
{public:
	int energy = 100;
	int score = 0;
	int get_score();
	bool isenergy();
	void perform_base_easy();
	void perform_base_middle();
	virtual void perform_national_middle() = 0;
	virtual void perform_national_hard() = 0;
	virtual void info() = 0;
	virtual ~Figure_skater() {}
};