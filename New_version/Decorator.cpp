#include "stdafx.h"
#include "Decorator.h"
Decorator::Decorator(Figure_skater* man) {
		skater = man;
	}
	void Decorator::perform_national_middle() {
		skater->perform_national_middle();
	}
	void Decorator::perform_national_hard() {
		skater->perform_national_hard();
	}
	void Decorator::info() {
		skater->info();
	}
	bool Decorator::isenergy() {
		return skater->isenergy();
	}
	void Decorator::increase_score_middle() {
		skater->score += 10;
	}
	void Decorator::increase_score_hard() {
		skater->score += 20;
	}
	int Decorator::get_score() {
		return skater->score;
	}
void OlympicChempion::perform_national_middle() {
		Decorator::perform_national_middle();
		cout << "AND Beautiful JAMP" << endl;
		increase_score_middle();
		}
	void OlympicChempion::perform_national_hard() {
		Decorator::perform_national_middle();
		cout << "triple toe loop! Splits in the air!!!" << endl;
		increase_score_hard();
			}