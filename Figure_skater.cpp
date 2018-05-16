#include "stdafx.h"
#include "Figure_skater.h"
int Figure_skater::get_score() {
	return score;
}
bool Figure_skater:: isenergy() {
	if (energy > 0) {
		return true;
	}
	else return false;

}

void Figure_skater:: perform_base_easy() {
	if (energy >= 5) {
		score += 5;
		energy -= 5;
	}
	else cout << "The sportsmen is tired! He can't do it. " << endl;
}
void Figure_skater::perform_base_middle() {
	if (energy >= 10) {
		score += 10;
		energy -= 10;
	}
	else {
		cout << "It is too difficult for me! " << endl;
	}
}