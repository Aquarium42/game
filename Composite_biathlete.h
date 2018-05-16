#pragma once
#include <list>
#include<algorithm>
#include "Norway_biathlete.h"
#include "Russian_biathlete.h"
using namespace std;
class Composite_biathlete : public NorwayBiathlete, public RussianBiathlete
{
public:
	void add(Biathlete* player) {
		children.push_back(player);
	}
	void remove(Biathlete* player) {
		children.remove(player);
	}
	void shoot() {
		for (Biathlete* player : children) {
			cout << "*" << endl;
			player->shoot();
		}
	}
private:
	list < Biathlete*> children;
};