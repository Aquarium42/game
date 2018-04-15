#pragma once
#include <list>
#include<algorithm>
#include "Unit.h"

using namespace std;
class Composite : public Unit
{
public:
	void add(Unit* player) {
		children.push_back(player);
	}
	 void remove(Unit* player) {
		children.remove(player);
	}
	int get_score() {
		int score = 0;
		for (Unit* player: children) {
			score += player->get_score();
		}
		return score;
	}
private:
	list < Unit*> children;
};
