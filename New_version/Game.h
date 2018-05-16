#pragma once
#include "Team.h"
#include"AthleteFactory.h"
#include<iostream>
#include "max_count_athlete.h"
#include <numeric>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <functional>
#include "correct_input.h"
using namespace std;
// Здесь создаются команды страны игрока и его противника
class Game
{
public:
	void create_figure(Team* p,AthleteFactory& factory){
		int count;
		cout << "Please enter the number of figure skaters. MAX count = " << max_count_figure_skater << endl;
		count = cin_integer();
		if (count > max_count_figure_skater || count < 0) {
			count = 1;
			show_error();
		}
		for (int i = 0; i < count; i++) {
			cout << "Please, choose level of skater: 1 - First on Olympic Games, 2 - He has experience,  3 - He was Olympic Chempion sometimes" << endl;
			int level = cin_integer();
				if (level == 1)	p->figure_skater.push_back(factory.createSkater());
				else if (level == 2) p->figure_skater.push_back(factory.createFigureOlympicChempion());
				else if (level == 3) p->figure_skater.push_back(factory.createFigureSometimesOlympicChempion());
				else { level = 1; 	p->figure_skater.push_back(factory.createSkater());
					show_error();
				}
		}
	}

	void create_hockey_player(Team*p, AthleteFactory& factory) {
		cout << "Please enter the number of hockey players. MAX count = " << max_count_hockey_player << endl;
		int count = cin_integer();
		if (count > max_count_hockey_player || count <0) {
			show_error();
			count = 1;
		}
		for (int i = 0; i < count; i++) {
			p->hockey_player.push_back(factory.createHockey());
		}
	}
	void create_biathlete(Team*p, AthleteFactory& factory) {
		cout << "Please enter the number of biathletes. MAX count = " << max_count_biathlete << endl;
		int count = cin_integer();
		if (count > max_count_biathlete || count < 0) {
			show_error();
			count = 1;
		}
		for (int i = 0; i < count; i++) {
			p->biathlete.push_back(factory.createBiathlete());
		}
	}
	Team * create_your_Team(AthleteFactory& factory) {
		Team* p = new Team;
		create_hockey_player(p, factory);
		create_figure(p, factory);
		create_biathlete(p, factory);
		return p;
	}
	Team* create_enemy_Team(AthleteFactory& factory) {
		Team* p = new Team;
		int level, count_biathlete, count_hockey, count_figure;
		cout << "Please, choose the difficulty level: 3 - hard, 2 - medium difficulty, 1-easy" << endl;
		level = cin_integer();
		if (level == 1) {
			count_biathlete = count_biathlete_easy;
			count_figure = count_figure_skater_easy; 
			count_hockey = count_hockey_player_easy;
		}
		else if (level == 2) {
			count_biathlete = count_biathlete_middle;
			count_figure = count_figure_skater_middle;
			count_hockey = count_hockey_player_middle;
		}
		else if (level == 3) {
			count_biathlete = count_biathlete_hard;
			count_figure = count_figure_skater_hard;
			count_hockey = count_hockey_player_hard;
		}
		else {
				level = 1;
				count_biathlete = count_biathlete_easy;
				count_figure = count_figure_skater_easy;
				count_hockey = count_hockey_player_easy;
				show_error();
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
