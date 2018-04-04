#pragma once
#include "Hockey_player.h"
#include "Figure_skater.h"
#include "Biathlete.h"
#include <vector>
// Класс, содержащий всех спортсменов
class Team
{
public:
	~Team() {
		int i;
		for (i = 0; i<hockey_player.size(); ++i)  delete hockey_player[i];
		for (i = 0; i<figure_skater.size(); ++i)  delete figure_skater[i];
		for (i = 0; i<biathlete.size(); ++i)  delete biathlete[i];
	}
	void info_() {
		int i;
		for (i = 0; i<hockey_player.size(); ++i)  hockey_player[i]->info();
		for (i = 0; i<figure_skater.size(); ++i)  figure_skater[i]->info();
		for (i = 0; i<biathlete.size(); ++i)  biathlete[i]->info();
	}
	void score_goal(int number_of_player) {
		hockey_player[number_of_player]->score_goal();
	}
	void perform_a(int number_of_player) {
		figure_skater[number_of_player]->perform_a();
	}
	void perform_b(int number_of_player) {
		figure_skater[number_of_player]->perform_b();
	}
	void shoot(int number_of_player){
		biathlete[number_of_player]->shoot();
	}
	void accelerate(int number_of_player) {
		biathlete[number_of_player]->accelerate();
	}
	void slow_down(int number_of_player) {
		biathlete[number_of_player]->slow_down();
	}
	std::vector<Hockey_player*> hockey_player;//хоккеисты
	std::vector<Figure_skater*> figure_skater;//фигуристы
	std::vector<Biathlete*> biathlete;//биатлонисты
};

