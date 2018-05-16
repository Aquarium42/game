#include "stdafx.h"
#include "Team.h"
#include "Observer.h"
Team::~Team() {
	int i;
	for (i = 0; i<hockey_player.size(); ++i)  delete hockey_player[i];
	for (i = 0; i<figure_skater.size(); ++i)  delete figure_skater[i];
	for (i = 0; i<biathlete.size(); ++i)  delete biathlete[i];
}
void Team::info_() {
	int i;
	for (i = 0; i<hockey_player.size(); ++i)  hockey_player[i]->info();
	for (i = 0; i<figure_skater.size(); ++i)  figure_skater[i]->info();
	for (i = 0; i<biathlete.size(); ++i)  biathlete[i]->info();
}
void Team::score_goal(vector <int> index) {

	Composite_hockey hockey_man;
	for (int i = 0; i <index.size(); i++) {
		hockey_man.add(hockey_player[index[i]]);
	}
	hockey_man.score_goal();
}
void Team::perform_base_easy(int number_of_player) {
	if (figure_skater[number_of_player]->isenergy()) {
		figure_skater[number_of_player]->perform_base_easy();
	}
	else cout << "I can't do it" << endl;
}
void Team::perform_base_middle(int number_of_player) {
	if (figure_skater[number_of_player]->isenergy())
		figure_skater[number_of_player]->perform_base_middle();
}
void Team::perform_national_middle(int number_of_player) {

	if (figure_skater[number_of_player]->isenergy())
		figure_skater[number_of_player]->perform_national_middle();
}
void Team::perform_national_hard(int number_of_player) {
	if (figure_skater[number_of_player]->isenergy())
		figure_skater[number_of_player]->perform_national_hard();
}
void Team::shoot(vector <int> index) {
	Composite_biathlete man;
	for (int i = 0; i <index.size(); i++) {
		man.add(biathlete[index[i]]);
			}
	man.shoot();
}
void Team::accelerate(int number_of_player) {
	if (biathlete[number_of_player]->isenergy())
		biathlete[number_of_player]->accelerate();
}
void Team::slow_down(int number_of_player) {
	if (biathlete[number_of_player]->isenergy())
		biathlete[number_of_player]->slow_down();
}
int Team::score_biathlete() {
	Composite athletes;
	for (int i = 0; i < biathlete.size(); i++) {
		athletes.add(biathlete[i]);
	}
	return(athletes.get_score());
}
int Team::score_hockey_player() {
	Composite athletes;
	for (int i = 0; i < hockey_player.size(); i++) {
		athletes.add(hockey_player[i]);
	}
	return(athletes.get_score());
}
int Team::score_figure_skater() {
	Composite athletes;
	for (int i = 0; i <figure_skater.size(); i++) {
		athletes.add(figure_skater[i]);
	}
	return(athletes.get_score());
}
void Team::get_energy_biathlete(vector<int>& index) {
	for (int i = 0; i < biathlete.size(); i++) {
		if (biathlete[i]->isenergy()) {
			index.push_back(i);
		}
	}
}


void Team::get_energy_hockey_player(vector<int>& index) {
	for (int i = 0; i < hockey_player.size(); i++) {
		if (hockey_player[i]->isenergy()) {
			index.push_back(i);
		}
	}
}
void Team::get_energy_figure_skater(vector<int>& index) {
	for (int i = 0; i < figure_skater.size(); i++) {
		if (figure_skater[i]->isenergy()) {
			index.push_back(i);
		}
	}
}
//можно добавить спортсмена каждого вида по отдельность и потом вызвать общую get_score
//оно будет работать, так как они все Unit. Но мне кажется, тут можно проще сложить и всё. 
//А сам компановщик нужен, так как потом можно будет что=то поменять, как зохочу. Для этого тут надо написать какую-то новую функцию. 
int Team::score_all() {
	return(score_biathlete() + score_figure_skater() + score_hockey_player());
}
int Team::score_one_biathlete(int index) {
	return biathlete[index]->get_score();
}

void Team::notify() {
	for (int i = 0; i < views.size(); i++) {
		views[i]->update();
	}
}
void Team::attach(Observer *model) {
	views.push_back(model);
}

void Team::show_player_not_energy_in_sport(int sport_id) {
	if (sport_without_energy[sport_id] == false) {
		sport_without_energy[sport_id] = true;
		notify();
	}
	cout << "Oy,  players have not energy!" << endl;
}