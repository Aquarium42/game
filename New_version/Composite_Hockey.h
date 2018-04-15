#pragma once
#include <list>
#include<algorithm>
#include "Norway_hockey_player.h"

#include "Russian_hockey_player.h"
using namespace std;
class Composite_hockey : public NorwayHockey, public RussianHockey
{
public:
	void add(Hockey_player* player) {
		children.push_back(player);
	}
	void remove(Hockey_player* player) {
		children.remove(player);
	}
	void score_goal() {
		for (Hockey_player* player : children) {
			cout << "I" << endl;
			 player->score_goal();
		}
	}
private:
	list < Hockey_player*> children;
};
