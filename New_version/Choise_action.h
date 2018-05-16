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
		cout << "shoot  -  your biathletes will shoot. " << endl;
		cout << "accelerate  -  your biathlete will increase speed. It gives more points, but energy will decrease." << endl;
		cout << "slow_down  -  your biathlete will decrease speed, but his energy will increase." << endl;
		cout << "perform  -  your figure skater will perform something. They can do 4 different exercises." << endl;
		cout << "goal  -  your hockey_player will goal. " << endl;
		cout << "score  -  get score. We can choose what kind of sport you want to get score."<<endl;
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