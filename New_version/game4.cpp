#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include "Game.h"
#include "RussianAthleteFactory.h"
#include "NorwayAthleteFactory.h"
#include"Choise_action.h"
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
		action_(my, enemy, action);
			cout << "Write next action, please. " << endl;
			cin >> action;
	}
	my->info_();
	enemy->info_();
	return 0;
}