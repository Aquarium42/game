#pragma once
#include "Hockey_player.h"
#include "Figure_skater.h"
#include "Biathlete.h"
#include <vector>
#include "Composite.h"
#include "Composite_hockey.h"
#include "Composite_biathlete.h"
#include "Sport_id.h"
// �����, ���������� ���� �����������
class Team
{
private:
	std::vector<class Observer *> views;

public:

	Team() { sport_without_energy.resize(count_kind_of_sport, false); }

	~Team();
	void info_();
	void attach(Observer *obs);
	void notify();
	void score_goal(vector <int> index);
	void perform_base_easy(int number_of_player);
	void perform_base_middle(int number_of_player);
	void perform_national_middle(int number_of_player);
	void perform_national_hard(int number_of_player);
	void shoot(vector <int> index);
	void accelerate(int number_of_player);
	void slow_down(int number_of_player);
	int score_biathlete();
	int score_hockey_player();
	int score_figure_skater();
	int score_all();
	int score_one_biathlete(int index);
	void get_energy_biathlete(vector<int>& index);
	void get_energy_figure_skater(vector<int>& index);
	void get_energy_hockey_player(vector<int>& index);
	void show_player_not_energy_in_sport(int sport_id);
	std::vector<Hockey_player*> hockey_player;//���������
	std::vector<Figure_skater*> figure_skater;//���������
	std::vector<Biathlete*> biathlete;//�����������
	vector<bool> sport_without_energy;
};

