#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include "Game.h"
#include "RussianAthleteFactory.h"
#include "NorwayAthleteFactory.h"
using namespace std;

//Обеспечим корректный ввод страны
string cin_() {
	string country = "Country";
	cin >> country;
	while (country != "Russia" && country != "Norway") {
		cout << "Other countries are all busy! choose from these" << endl;
		cin >> country;
	}
	return country;
}

int main()
{
	Game game;
	cout << "Welcome to the Olympic games!" << endl;
	cout << "Select a country : Russia or Norway(write the name of one of them)" << endl;
	string country;
	country = cin_();
	Team* my;
	Team* enemy;
	if (country == "Russia") {

		NorwayAthleteFactory enemy_factory;
		enemy = game.create_enemy_Team(enemy_factory);
		RussianAthleteFactory my_factory;
		my = game.create_your_Team(my_factory);
	}
	else {
		RussianAthleteFactory enemy_factory;
		enemy = game.create_enemy_Team(enemy_factory);
		NorwayAthleteFactory my_factory;
		my = game.create_your_Team(my_factory);

	}
	
	cout << endl;
	string action;
	cout << "action" << endl;
	cin >> action;
	int index_enemy = 0;
	while (action != "stop") {
		if (action == "shoot") {
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
			my->shoot(players);
		}
		else if (action == "score_biathlete") {
			cout << "***" << endl;
			cout<<my->score_biathlete();
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
		}
		
			cout << "Write next action, please. " << endl;
			cin >> action;
	}
	my->info_();
	return 0;
}