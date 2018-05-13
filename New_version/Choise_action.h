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
/*
Command* choice(string action, Team* my, Team* enemy) {
	if (action == "shoot") {
		Command_shoot* s = new Command_shoot(my, enemy);
		return new s;
	}
	else if (action == "score_biathlete") {
		cout << "***" << endl;
		cout << my->score_biathlete();
	}
	else if (action == "score_hockey") {
		cout << "***" << endl;
		cout << my->score_hockey_player();
	}
	else if (action == "score_figure") {
		cout << "***" << endl;
		cout << my->score_figure_skater();
	}
	else if (action == "score_all") {
		cout << "***" << endl;
		cout << my->score_all();
	}
	else if (action == "accelerate") {
		cout << "Who will accelerate?" << endl;
		int index;
		cin >> index;
		my->accelerate(index);

	}
	else if (action == "slow_down") {
		cout << "Who will slow down?" << endl;
		int index;
		cin >> index;
		my->slow_down(index);
	}
	else if (action == "help") {
		cout << "FOR BIATHLETE" << endl;
	}
	else if (action == "perform1") {
		cout << "Who will do it?" << endl;
		int index;
		cin >> index;
		my->perform_base_easy(index);
	}
	else if (action == "perform3") {
		cout << "Who will do it?" << endl;
		int index;
		cin >> index;
		my->perform_national_middle(index);
	}
	else if (action == "perform2") {
		cout << "Who will do it?" << endl;
		int index;
		cin >> index;
		my->perform_base_middle(index);
	}
	else if (action == "perform4") {
		cout << "Who will do it?" << endl;
		int index;
		cin >> index;
		my->perform_national_hard(index);
	}
	else if (action == "score_goal") {
		int count = 0;
		cout << "How many people will do it?" << endl;
		cin >> count;
		vector<int> players;
		cout << "Who will do it? Write with space. (For example: 0 2 5)" << endl;
		for (int i = 0; i < count; i++) {
			int index;
			cin >> index;
			players.push_back(index);
		}
		my->score_goal(players);

	};

	*/