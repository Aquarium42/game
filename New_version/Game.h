#pragma once
#include "Team.h"
#include"AthleteFactory.h"
#include<iostream>
using namespace std;
// Здесь создается команда той или иной страны
class Game
{
public:
	Team * createTeam(AthleteFactory& factory) {
		Team* p = new Team;
		int count;
		cout << "Please enter the number of hockey players. MAX count = 25" << endl;
		cin >> count;
		if (count > 25) {
			cout << "You've entered too much. Therefore, the count will be 1";
			count = 1;
		}
		for (int i = 0; i < count; i++) {
			p->hockey_player.push_back(factory.createHockey());
		}
		cout << "Please enter the number of figure skaters. MAX count = 15" << endl;
		cin >> count;
		if (count > 15) {
			cout << "You've entered too much. Therefore, the count will be 1";
			count = 1;
		}
		for (int i = 0; i < count; i++) {
			p->figure_skater.push_back(factory.createSkater());
		}
		cout << "Please enter the number of biathletes. MAX count = 20" << endl;
		cin >> count;
		if (count > 20) {
			cout << "You've entered too much. Therefore, the count will be 1";
			count = 1;
		}
		for (int i = 0; i < count; i++) {
			p->biathlete.push_back(factory.createBiathlete());
		}
		return p;
	}
};
