#pragma once
#include <string>

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
	Team* my_game;
	Team* en_game;
};

class Command_shoot : public Command {
public:
	Command_shoot(Team* my, Team* enemy) : Command(my, enemy ) {
	
	}
	void execute() {
		vector<int> probably_players;
		my_game->get_energy_hockey_player(probably_players);
		int count = 0;
		if (probably_players.size() == 0) {
			cout << "Oy, your players have not energy!" << endl;
		}
		else {
			cout << "How many people will do it? We can choose " << probably_players.size() << endl;
			int count = 0;
			cin >> count;
			if (count <= probably_players.size() && count > 1) {
				vector<int> players;
				cout << "Who will do it? Write with space. (For example: 0 2 5). You can enter some of ";
				for (int i = 0; i < probably_players.size(); i++) {
					cout << probably_players[i] << " ";
				}cout << endl;
				for (int i = 0; i < count; i++) {
					int index;
					cin >> index;
					if (in_plobably_players(probably_players, index)) {
						players.push_back(index);
					}

					else { cout << "Sorry, you entered bad data" << endl; }
					my_game->shoot(players);

				}
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
		my_game->get_energy_hockey_player(probably_players);

		cout << "Who will do it? Write with space. (For example: 0 2 5). You can enter some of ";
		for (int i = 0; i < probably_players.size(); i++) {
			cout << probably_players[i] << " ";
		}cout << endl;

		int index;
		cin >> index;
		if (in_plobably_players(probably_players, index)) {
			my_game->slow_down(index);
		}
		else { cout << "Sorry, you entered bad data" << endl; }
	}
};

class Command_accelerate : public Command {
public:
	Command_accelerate(Team* my, Team* enemy) : Command(my, enemy) {
	}
	void execute() {
		vector<int> probably_players;
		my_game->get_energy_hockey_player(probably_players);

		cout << "Who will do it? Write with space. (For example: 0 2 5). You can enter some of ";
		for (int i = 0; i < probably_players.size(); i++) {
			cout << probably_players[i] << " ";
		}cout << endl;
		int index;
		cin >> index;
		if (in_plobably_players(probably_players, index)) {
			my_game->accelerate(index);
		}
		else { cout << "Sorry, you entered bad data" << endl; }

	}
};

class Command_perform : public Command {
public:
	Command_perform(Team* my, Team* enemy) : Command(my, enemy) {
	}
	void execute() {
		vector<int> probably_players;
		my_game->get_energy_hockey_player(probably_players);
		int count = 0;
		cout << "You are goint to figure skate. Who will do it?" << endl;
		int id;
		cin >> id;
		cout<<"Enter 1 if to perform light database"<<endl;
		cout << "Enter 2 to perform medium base" << endl;
		cout<<"Enter 3 to perform the national average exercise "<< endl;
		cout<<"Enter 4 to perform a complex national exercise"<<endl;
		int index = 0;
		cin >> index;
		if (in_plobably_players(probably_players, index)) {

			switch (index) {
			case 1:
				my_game->perform_base_easy(id);
				break;
			case 2:

				my_game->perform_national_middle(id);
				break;
			case 3:
				my_game->perform_base_middle(id);
				break;
			case 4:
				my_game->perform_national_hard(id);
				break;
			}
		}

		else { cout << "Sorry, you entered bad data" << endl; }
	}
};
class Command_goal : public Command {
public:
	Command_goal(Team* my, Team* enemy) : Command(my, enemy) {
	}
	void execute() {
		vector<int> probably_players;
		my_game->get_energy_hockey_player(probably_players);
		int count = 0;
		if (probably_players.size() == 0) {
			cout << "Oy, your players have not energy!" << endl;
		}
		else {

			cout << "How many people will do it? We can choose " <<probably_players.size()<< endl;
			cin >> count; //потому что на нем стоит паттерн композит
			if (count > probably_players.size()) {
				cout << "We can not choose so many sportsman :/  I decide that you chose 1";
				count = 1;
			}
			vector<int> players;
			cout << "Who will do it? Write with space. (For example: 0 2 5). You can enter some of ";
			for (int i = 0; i < probably_players.size(); i++) {
				cout << probably_players[i] << " ";
			}cout << endl;
			for (int i = 0; i < count; i++) {
				int index;
				cin >> index;
				if (in_plobably_players(probably_players, index)) {
					players.push_back(index);
				}
				else { cout << "Sorry, you entered bad data" << endl; }
				
			}
			my_game->score_goal(players);
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
		int index;
		cin >> index;
		switch (index)
		{
		case 1:
			cout<<my_game->score_all();
			break;
		case 2:
			cout << my_game->score_biathlete();
			break;
		case 3:

			cout << my_game->score_hockey_player();
			break;
		case 4:
			cout << my_game->score_figure_skater();
			break;
		}	
	}
};
