#pragma once
#include "Figure_skater.h"
#include <random>
class Decorator :public Figure_skater
{
	Figure_skater* skater;
public:
	Decorator(Figure_skater* man) {
		skater = man;
	}
	void perform_national_middle() {
		skater->perform_national_middle();
	}
	void perform_national_hard() {
		skater->perform_national_hard();
	}
	void info() {
		skater->info();
	}
	bool isenergy(){
		return skater->isenergy();
	}
	void increase_score_middle() {
		skater->score += 10;
	}
	void increase_score_hard() {
		skater->score += 20;
	}
	int get_score() {
		return skater->score;
	}
};
class OlympicChempion :public Decorator
{
public:
	OlympicChempion(Figure_skater *skater): Decorator(skater){}
	void perform_national_middle() {
		Decorator::perform_national_middle();
		cout << "AND Beautiful JAMP"<<endl;
		cout << get_score() << endl;
		increase_score_middle();
		cout << get_score() << endl;
	}
	void perform_national_hard() {
		Decorator::perform_national_middle();
		cout << "triple toe loop! Splits in the air!!!" << endl;
		cout << get_score() << endl;
		increase_score_hard();
		cout << get_score() << endl;
	}
	
};

