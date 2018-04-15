#pragma once
#include "Team.h"
#include"AthleteFactory.h"
#include<iostream>
#include "max_count_athlete.h"
using namespace std;
// Здесь создается команда той или иной страны
class Game
{
public:
	Team * create_your_Team(AthleteFactory& factory) {
		Team* p = new Team;
		int count;
		cout << "Please enter the number of hockey players. MAX count = " << max_count_hockey_player << endl;
		cin >> count;
		if (count > max_count_hockey_player) {
			cout << "You've entered too much. Therefore, the count will be 1";
			count = 1;
		}
		for (int i = 0; i < count; i++) {
			p->hockey_player.push_back(factory.createHockey());
		}
		cout << "Please enter the number of figure skaters. MAX count = " << max_count_figure_skater << endl;
		cin >> count;
		if (count > max_count_figure_skater) {
			cout << "You've entered too much. Therefore, the count will be 1";
			count = 1;
		}
		for (int i = 0; i < count; i++) {
			cout << "Please, choose level of skater: 1 - First on Olympic Games, 2 - He has experience,  3 - He was Olympic Chempion sometimes" << endl;
			int level = 0;
			cin >> level;
			if (level > 3 || level < 1) level = 1;
			else {
			if (level == 1)	p->figure_skater.push_back(factory.createSkater());
			else if (level == 2) p->figure_skater.push_back(factory.createFigureOlympicChempion());
			else if (level == 3) p->figure_skater.push_back(factory.createFigureSometimesOlympicChempion());
			}
		}
		cout << "Please enter the number of biathletes. MAX count = " << max_count_biathlete << endl;
		cin >> count;
		if (count > max_count_biathlete) {
			cout << "You've entered too much. Therefore, the count will be 1";
			count = 1;
		}
		for (int i = 0; i < count; i++) {
			p->biathlete.push_back(factory.createBiathlete());
		}
		return p;
	}
	Team* create_enemy_Team(AthleteFactory& factory) {
		Team* p = new Team;
		int level, count_biathlete, count_hockey, count_figure;
		cout << "Please, choose the difficulty level: 3 - hard, 2 - medium difficulty, 1-easy" << endl;
		cin >> level;
		if (level < 1 || level > 3) {
			level = 1;
		}
		if (level == 1) {
			count_biathlete = count_biathlete_easy;
			count_figure = count_figure_skater_easy; 
			count_hockey = count_hockey_player_easy;
		}
		if (level == 2) {
			count_biathlete = count_biathlete_middle;
			count_figure = count_figure_skater_middle;
			count_hockey = count_hockey_player_middle;
		}
		if (level == 3) {
			count_biathlete = count_biathlete_hard;
			count_figure = count_figure_skater_hard;
			count_hockey = count_hockey_player_hard;
		}

		for (int i = 0; i < count_hockey; i++) {
			p->hockey_player.push_back(factory.createHockey());
		}
		for (int i = 0; i < count_figure; i++) {
			p->figure_skater.push_back(factory.createSkater());
		}
		for (int i = 0; i < count_biathlete; i++) {
			p->biathlete.push_back(factory.createBiathlete());
		}
		return p;
	}
};
