#pragma once
#include "Figure_skater.h"
#include <random>
class Decorator :public Figure_skater
{
	Figure_skater* skater;
public:
	Decorator(Figure_skater* man);
	void perform_national_middle();
	void perform_national_hard();
	void info();
	bool isenergy();
	void increase_score_middle();
	void increase_score_hard();
	int get_score();
};
class OlympicChempion :public Decorator
{
public:
	OlympicChempion(Figure_skater *skater): Decorator(skater){}
	void perform_national_middle();
	void perform_national_hard();
	
};

