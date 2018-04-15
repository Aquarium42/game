#pragma once
#include "Hockey_player.h"
#include "Figure_skater.h"
#include "Biathlete.h"
#include <vector>
#include "Composite.h"
#include "Composite_hockey.h"
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
	void score_goal(vector <int> index) {

		Composite_hockey hockey_man;
		for (int i = 0; i <index.size(); i++) {
			cout << index[i] << endl;
			cout << "P" << endl;
			hockey_man.add(hockey_player[index[i]]);
		}
		hockey_man.score_goal();
	}
	void perform_base_easy(int number_of_player) {
		if (figure_skater[number_of_player]->isenergy()) {
			figure_skater[number_of_player]->perform_base_easy();
		}
		else cout << "I can't do it" << endl;
		}
	void perform_base_middle(int number_of_player) {
		if (figure_skater[number_of_player]->isenergy())
		figure_skater[number_of_player]->perform_base_middle();
	}
	void perform_national_middle(int number_of_player) {
		
		if (figure_skater[number_of_player]->isenergy())
			figure_skater[number_of_player]->perform_national_middle();
	}
	void perform_national_hard(int number_of_player) {
		if (figure_skater[number_of_player]->isenergy())
			figure_skater[number_of_player]->perform_national_hard();
	}
	void shoot(int number_of_player){
		if (biathlete[number_of_player]->isenergy())
			biathlete[number_of_player]->shoot();
	}
	void accelerate(int number_of_player) {
		if (biathlete[number_of_player]->isenergy())
			biathlete[number_of_player]->accelerate();
	}
	void slow_down(int number_of_player) {
		if (biathlete[number_of_player]->isenergy())
			biathlete[number_of_player]->slow_down();
	}
	int score_biathlete() {
		Composite athletes;
		for (int i = 0; i < biathlete.size(); i++) {
			athletes.add(biathlete[i]);
		}
		return(athletes.get_score());
	}
	int score_hockey_player() {
		Composite athletes;
		for (int i = 0; i < hockey_player.size(); i++) {
			athletes.add(hockey_player[i]);
		}
		return(athletes.get_score());
	}
	int score_figure_skater() {
		Composite athletes;
		for (int i = 0; i <figure_skater.size(); i++) {
			athletes.add(figure_skater[i]);
		}
		return(athletes.get_score());
	} 
	//можно добавить спортсмена каждого вида по отдельность и потом вызвать общую get_score
	//оно будет работать, так как они все Unit. Но мне кажется, тут можно проще сложить и всё. 
	//А сам компановщик нужен, так как потом можно будет что=то поменять, как зохочу. Для этого тут надо написать какую-то новую функцию. 
	int score_all() {
		return(score_biathlete()+score_figure_skater()+ score_hockey_player());
	}
	int score_one_biathlete(int index) {
		return biathlete[index]->get_score();
	}
	std::vector<Hockey_player*> hockey_player;//хоккеисты
	std::vector<Figure_skater*> figure_skater;//фигуристы
	std::vector<Biathlete*> biathlete;//биатлонисты
};

