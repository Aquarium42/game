#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include "Game.h"
#include "RussianAthleteFactory.h"
#include "NorwayAthleteFactory.h"
#include"Choise_action.h"
#include "Observer.h"
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
void show_winner_and_loser(int my_score, int enemy_score) {
	if (my_score > enemy_score) {
		cout << "Greetings! You win!" << endl;
		cout << "Your score: " << my_score << ". Computer score: " << enemy_score << endl;
	}
	else if (my_score == enemy_score) {
		cout << "The score is equal: " << my_score << endl;
	}
	else {
		cout << "Unfortunately, you've lost!" << endl;
		cout << "Your score: " << my_score << ". Computer score: " << enemy_score << endl;
	}
}
void show_result(Team* my, Team* enemy) {
	cout << "IN THIS GAME: " << endl;
	cout << endl;
	int my_score = my->score_all(), enemy_score = enemy->score_all();
	show_winner_and_loser(my_score, enemy_score);
	cout << endl;
	cout << "In biathlete: " << endl;
	my_score = my->score_biathlete(), enemy_score = enemy->score_biathlete();
	show_winner_and_loser(my_score, enemy_score);
	cout << endl;
	cout << "In figure skater: " << endl;
	my_score = my->score_figure_skater(), enemy_score = enemy->score_figure_skater();
	show_winner_and_loser(my_score, enemy_score);
	cout << endl;
	cout << "In hockey: " << endl;
	my_score = my->score_hockey_player(), enemy_score = enemy->score_hockey_player();
	show_winner_and_loser(my_score, enemy_score);
}
int main()
{
	std::mt19937 twister(time(nullptr));
	std::uniform_int_distribution<int> uniformInt(0, 1);

	Game model;
	cout << "Welcome to the Olympic games!" << endl;
	cout << "Select a country : Russia or Norway(write the name of one of them)" << endl;
	string country;
	country = cin_();
	Team* my;
	Team* enemy;
	if (country == "Russia") {

		NorwayAthleteFactory enemy_factory;
		enemy = model.create_enemy_Team(enemy_factory);
		RussianAthleteFactory my_factory;
		my = model.create_your_Team(my_factory);
	}
	else {
		RussianAthleteFactory enemy_factory;
		enemy = model.create_enemy_Team(enemy_factory);
		NorwayAthleteFactory my_factory;
		my = model.create_your_Team(my_factory);

	}
	
	cout << endl;
	string action;
	cout << "Enter action. If you don't know kind of actions, enter 'help'. " << endl;
	action = "...";
	Lived_player users_players(my); //...
	Lived_player enemy_players(enemy); //будут наблюдать, когда стоит остановить игру
	while (action != "stop" && users_players.is_any_live() && enemy_players.is_any_live()) {
		cin >> action;
		action_(my, enemy, action);
			cout << "Write next action, please. " << endl;
			
	}
	show_result(my, enemy);
	//my->info_();
	//enemy->info_();
	system("pause");
	return 0;
}