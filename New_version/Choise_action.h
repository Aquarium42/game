#pragma once
#include"Command.h"
void action_(Team* my, Team* enemy, string action) {
	
	if (action == "shoot") {
		vector<Command*> v;
		v.push_back(new Command_shoot(my, enemy));
		v[0]->execute();

	}
	else if (action == "help") {
		cout << "Write one of functions:" << endl;
		cout << "shoot; score;accelerate; slow_down; perform; goal; "<<endl;
	}
	else if (action == "slow_down") {
		vector<Command*> v;
		v.push_back(new Command_slow_down(my, enemy));
		v[0]->execute();

	}
	else if (action == "perform") {
		vector<Command*>v;
		v.push_back(new Command_perform(my, enemy));
		v[0]->execute();
	}
	else if (action == "score") {
		vector<Command*>v;
		v.push_back(new Command_score(my, enemy));
		v[0]->execute();
	}
	else if (action == "accelerate") {
		vector<Command*>v;
		v.push_back(new Command_accelerate(my, enemy));
		v[0]->execute();
	}
	else if (action == "goal") {
		vector<Command*>v;
		v.push_back(new Command_goal(my, enemy));
		v[0]->execute();
	}
}