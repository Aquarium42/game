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
	if (country == "Russia") {
		RussianAthleteFactory my_factory;
		my = game.createTeam(my_factory);
	}
	else {
		NorwayAthleteFactory my_factory;
		my = game.createTeam(my_factory);
	}
	my->info_();
	return 0;
}