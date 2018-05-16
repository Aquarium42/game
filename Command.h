#pragma once
#include <string>
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>   
#include <random>
#include <cstdlib>
#include"Sport_id.h"
bool in_plobably_players(const vector<int>& probably_players, int index) {
	for (int i = 0; i < probably_players.size(); i++) {
		if (probably_players[i] == index) {
			return true;
		}
	}
	return false;
}
class Command {
public:
	virtual ~Command() {};

	virtual void execute() = 0;
protected :
	Command(Team* my, Team* enemy): my_game(my), en_game(enemy){}
	int choose_user_one_sportsman(const vector<int>& probably_players);
	void choose_user_sportsmans(const vector<int>& probably_players, vector<int>& players);
	void choose_enemy_sportsmans(vector<int> & probably_players, vector<int>& players);
	int choose_enemy_one_sportsman(vector<int>& probably_players);

	Team* my_game;
	Team* en_game;

};
void Command::choose_user_sportsmans(const vector<int>& probably_players, vector<int>& players) {
	cout << "How many people will do it? We can choose " << probably_players.size() << endl;
	int count = cin_integer();
	if (count <= probably_players.size() && count >= 1) {
		cout << "Who will do it? Write with space. (For example: 0 2 5). You can enter some of ";
		for (int i = 0; i < probably_players.size(); i++) {
			cout << probably_players[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < count; i++) {
			int index = cin_integer();
			if (in_plobably_players(probably_players, index)) {
				players.push_back(index);
			}
			else { show_incorrect_without(); }
		}
	}
	else { show_incorrect_without(); }
}


int myrandom(int i) { return std::rand() % i; }

void Command::choose_enemy_sportsmans( vector<int> & probably_players, vector<int>& players) {
	mt19937 gen(time(nullptr)); 
	std::uniform_int_distribution<> uniformInt(0, probably_players.size());
	std::random_shuffle(probably_players.begin(), probably_players.end());
	std::random_shuffle(probably_players.begin(), probably_players.end(), myrandom);
	for (int i = 0; i < uniformInt(gen); i++) {
		players.push_back(probably_players[i]);
	}
}
int Command::choose_enemy_one_sportsman(vector<int>& probably_players) {
	mt19937 gen(time(nullptr));
	std::uniform_int_distribution<> uniformInt(0, probably_players.size() - 1);
	return uniformInt(gen);
}
int Command::choose_user_one_sportsman(const vector<int>& probably_players) {
		cout << "Who will do it? Write with space. (For example: 0 2 5). You can enter some of ";
		for (int i = 0; i < probably_players.size(); i++) {
			cout << probably_players[i] << " ";
		}cout << endl;
		int index = cin_integer();
		return index;
}
class Command_shoot : public Command {
public:
	Command_shoot(Team* my, Team* enemy) : Command(my, enemy ) {
	}
	void execute() {
		vector<int> probably_players;
		my_game->get_energy_biathlete(probably_players);
		if (probably_players.size() == 0) {
			my_game->show_player_not_energy_in_sport(biathlete_id);
		}
		else {
			vector<int> players;
			choose_user_sportsmans(probably_players, players);
			cout << "You:" << endl;
			my_game->shoot(players);
			probably_players.clear();
			players.clear();
			en_game->get_energy_biathlete(probably_players);
			if (probably_players.size() == 0) {
				en_game->show_player_not_energy_in_sport(biathlete_id);
			}
			else {
				cout << "Computer:" << endl;
				choose_enemy_sportsmans(probably_players, players);
				en_game->shoot(players);
			}
		}
	}
};


class Command_slow_down : public Command {
public:
	Command_slow_down(Team* my, Team* enemy) : Command(my, enemy) {
	}
	void execute() {
		vector<int> probably_players;
		my_game->get_energy_biathlete(probably_players);
		if (probably_players.size() <= 0) {
			my_game->show_player_not_energy_in_sport(biathlete_id);
		}
		else {
			int index = choose_user_one_sportsman(probably_players);
			if (in_plobably_players(probably_players, index)) {
				cout << "You:" << endl;
				my_game->slow_down(index);
			}
			else { show_incorrect_without(); }
		}
	}
};

class Command_accelerate : public Command {
public:
	Command_accelerate(Team* my, Team* enemy) : Command(my, enemy) {
	}
	void execute() {
		vector<int> probably_players;
		my_game->get_energy_biathlete(probably_players);
		int index = choose_user_one_sportsman(probably_players);
		if (in_plobably_players(probably_players, index)) {
			cout << "You:" << endl;
			my_game->accelerate(index);
		}
		else { show_incorrect_without(); }

	}
};

class Command_perform : public Command {
public:
	Command_perform(Team* my, Team* enemy) : Command(my, enemy) {
	}
	void execute() {
		vector<int> probably_players;
		my_game->get_energy_figure_skater(probably_players);
		if (probably_players.size() == 0) {
			my_game->show_player_not_energy_in_sport(figure_skater_id);
		}
		else {
			int id = choose_user_one_sportsman(probably_players);
			cout << "Enter 1 if to perform light database" << endl;
			cout << "Enter 2 to perform medium base" << endl;
			cout << "Enter 3 to perform the national average exercise " << endl;
			cout << "Enter 4 to perform a complex national exercise" << endl;
			int index = cin_integer();
			if (in_plobably_players(probably_players, id)) {

				probably_players.clear();
				en_game->get_energy_figure_skater(probably_players);

				switch (index) {
				case 1:
					cout << "You:" << endl;
					my_game->perform_base_easy(id);
					cout << "Computer:" << endl;
					if (probably_players.size() == 0) {
						en_game->show_player_not_energy_in_sport(hockey_id);
					}
					else{
						en_game->perform_base_easy(choose_enemy_one_sportsman(probably_players));
					}
					break;
				case 2:
					cout << "You:" << endl;
					my_game->perform_national_middle(id);
					cout << "Computer:" << endl; 
					if (probably_players.size() == 0) {
						en_game->show_player_not_energy_in_sport(hockey_id);
					}
					else {
						en_game->perform_base_middle(choose_enemy_one_sportsman(probably_players));
					}
					break;
				case 3:
					cout << "You:" << endl;
					my_game->perform_base_middle(id);
					cout << "Computer:" << endl;
					if (probably_players.size() == 0) {
						en_game->show_player_not_energy_in_sport(hockey_id);
					}
					else {
						en_game->perform_national_middle(choose_enemy_one_sportsman(probably_players));
					}
					break;
				case 4:
					cout << "You:" << endl;
					my_game->perform_national_hard(id);
					cout << "Computer:" << endl;
					if (probably_players.size() == 0) {
						en_game->show_player_not_energy_in_sport(hockey_id);
					}
					else {
						en_game->perform_national_hard(choose_enemy_one_sportsman(probably_players));
					}
					break;
				}

			}

			else { show_incorrect_without(); }
		}
	}
};

class Command_goal : public Command {
public:
	Command_goal(Team* my, Team* enemy) : Command(my, enemy) {
	}
	void execute() {
		vector<int> probably_players;
		my_game->get_energy_hockey_player(probably_players);
		if (probably_players.size() == 0) {
			my_game->show_player_not_energy_in_sport(hockey_id);
		}
		else {
			vector<int> players;
			choose_user_sportsmans(probably_players, players);
			cout << "You:" << endl;
			my_game->score_goal(players);
			
			probably_players.clear();
			players.clear();
			cout << "Computer:" << endl;
			en_game->get_energy_hockey_player(probably_players);
			if (probably_players.size() == 0) {
				en_game->show_player_not_energy_in_sport(hockey_id);
			}
			else {
				choose_enemy_sportsmans(probably_players, players);
				en_game->score_goal(players);
			}


		}
	}
};

class Command_score: public Command {
public:
	Command_score(Team* my, Team* enemy) : Command(my, enemy) {
	}
	void execute() {
		cout << "Enter 1 to take account of the whole team" << endl;
		cout << "Enter 2 to take account of the biathlon"<<endl;
		cout << "Enter 3 to take account of the hockey players" << endl;
		cout << "Enter 4 to take account of the skaters" << endl;
		int index = cin_integer();
		switch (index)
		{
		case 1:

			cout<<"Your: "<<my_game->score_all()<<endl;
			cout << "Computer: " << en_game->score_all()<<endl;
			break;
		case 2:
			cout <<"Your: "<< my_game->score_biathlete()<<endl;

			cout << "Computer: " << en_game->score_biathlete()<<endl;
			break;
		case 3:
			cout << "Your: " << my_game->score_hockey_player() << endl;
			cout << "Computer" << en_game->score_hockey_player() << endl;
			break;
		case 4:
			cout <<"Your: "<< my_game->score_figure_skater()<<endl;
			cout << "Computer: " << en_game->score_figure_skater()<<endl;
			break;
		}	
	}
};
