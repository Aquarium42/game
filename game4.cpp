#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Абстрактные базовые классы всех возможных видов спортсменов
class Hockey_player
{
protected:
	int energy = 100;
	int accuracy = 0;
	int endurance = 0;
public:
	virtual void score_goal() = 0;
	virtual void info() = 0;
	virtual ~Hockey_player() {}
};

class Figure_skater
{
protected:
	int score = 0; //заработанные очки
	int energy = 100;
	int skills = 0;
	int endurance = 0;
public:
	void perform_a() {
		score += 5;
		energy -= 5;
	}
	void perform_b() {
		score += 10;
		energy -= 10;
	}//и тому подобное. Некоторые функции должны зависеть от энергии
	virtual void info() = 0;
	virtual ~Figure_skater() {}
};

class Biathlete
{
protected:
	int speed = 0;
	int energy = 100;
	int accuracy = 0;
public:
	virtual void shoot() = 0;
	void accelerate() {
		speed += 5;
		energy -= 10;
	}
	void slow_down() {
		speed -= 5;
		energy += 5;
	}
	virtual void info() = 0;
	virtual ~Biathlete() {}
};


// Классы всех видов спортсменов Российской команды
class RussianHockey : public Hockey_player
{
public:
	RussianHockey() {
		accuracy = 8;
		endurance = 10;
	}
	void info() {
		cout << "RussianHockey info" << endl;
		cout << "endurance = " << endurance << ". accuracy =" << accuracy << "energy = " << energy << endl;

	}
	void score_goal() {
		cout << "EEeee, you score a goal! RUSSIA!!!";//потом ее надо будет доработать
	}
};

class RussianSkater : public Figure_skater
{
public:
	RussianSkater() {
		skills = 10;
		endurance = 8;
	}
	void info() {
		cout << "RussianSkater info" << endl;
		cout << "endurance = " << endurance << "skills =" << skills << "energy = " << energy << endl;
	}
};

class RussianBiathlete : public Biathlete
{
public:
	RussianBiathlete() {
		speed = 9;
		accuracy = 8;
	}
	void info() {
		cout << "RussianBiathlete info:" <<endl;
		cout << "speed = " << speed << ". accuracy =" << accuracy << "energy = " << energy << endl;
	}
	void shoot() {
		cout << "Russia shoot!!!" << endl;
	}
};


// Классы всех видов спортменов Норвегии
class NorwayHockey : public Hockey_player
{
public:
	NorwayHockey() {
		accuracy = 7;
		endurance = 7;
	};
	void info() {
		cout << "NorwayHockey info" << endl;
		cout << "endurance = " << endurance << ". accuracy =" << accuracy << "energy = " << energy << endl;
	}
	void score_goal() {
		cout << "EEeee, you score a goal!NORWAY!!!";//потом ее надо будет доработать
	}

};

class NorwaySkater : public Figure_skater
{
public:
	NorwaySkater() {
		skills = 10;
		endurance = 8;
	}
	void info() {
		cout << "NorwaySkater info" << endl;
		cout << "endurance = " << endurance << "skills =" << skills << "energy = " << energy << endl;
	}
};

class NorwayBiathlete : public Biathlete
{
public:
	NorwayBiathlete() {
		speed = 9;
		accuracy = 8;
	}
	void info() {
		cout << "NorwayBiathlete info" << endl;
		cout << "speed = " << speed << ". accuracy =" << accuracy << "energy = " << energy << endl;

	}
	void shoot() {
		cout << "Norway shoot!!!" << endl;
	}
};


// Абстрактная фабрика для производства спортсменов
class AthleteFactory
{
public:
	virtual Hockey_player* createHockey() = 0;
	virtual Figure_skater* createSkater() = 0;
	virtual Biathlete* createBiathlete() = 0;
	virtual ~AthleteFactory() {}
};


// Фабрика для создания Русских спортсменов
class RussianAthleteFactory : public AthleteFactory
{
public:
	Hockey_player * createHockey() {
		return new RussianHockey;
	}
	Figure_skater* createSkater() {
		return new RussianSkater;
	}
	Biathlete* createBiathlete() {
		return new RussianBiathlete;
	}
};


// Фабрика для создания спортсменов Норвегии
class NorwayAthleteFactory : public AthleteFactory
{
public:
	Hockey_player * createHockey() {
		return new NorwayHockey;
	}
	Figure_skater* createSkater() {
		return new NorwaySkater;
	}
	Biathlete* createBiathlete() {
		return new NorwayBiathlete;
	}
};


// Класс, содержащий всех спортсменов
class Team
{
public:
	~Team() {
		int i;
		for (i = 0; i<vi.size(); ++i)  delete vi[i];
		for (i = 0; i<va.size(); ++i)  delete va[i];
		for (i = 0; i<vh.size(); ++i)  delete vh[i];
	}
	void info_() {
		int i;
		for (i = 0; i<vi.size(); ++i)  vi[i]->info();
		for (i = 0; i<va.size(); ++i)  va[i]->info();
		for (i = 0; i<vh.size(); ++i)  vh[i]->info();
	}
	vector<Hockey_player*> vi;//хоккеисты
	vector<Figure_skater*> va;//фигуристы
	vector<Biathlete*> vh;//биатлонисты
};


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
			p->vi.push_back(factory.createHockey());
		}
		cout << "Please enter the number of figure skaters. MAX count = 15" << endl;
		cin >> count;
		if (count > 15) {
			cout << "You've entered too much. Therefore, the count will be 1";
			count = 1;
		}
		for (int i = 0; i < count; i++) {
			p->va.push_back(factory.createSkater());
		}
		cout << "Please enter the number of biathletes. MAX count = 20" << endl;
		cin >> count;
		if (count > 20) {
			cout << "You've entered too much. Therefore, the count will be 1";
			count = 1;
		}
		for (int i = 0; i < count; i++) {
			p->vh.push_back(factory.createBiathlete());
		}
		return p;
	}
};
//Обеспечим корректный ввод страны
string cin_() {
	string country;
	cin >> country;
	if (country == "Russia" || country == "Norway") {
		return country;
	}
	else {
		cout << "Other countries are all busy! choose from these" << endl;
		cin_();
	}
}

int main()
{
	Game game;
	cout << "Welcome to the Olympic games!" << endl;
	cout << "Select a country : Russia or Norway(write the name of one of them)" << endl;
	string country;
	country = cin_();
	if (country == "Russia") {
		RussianAthleteFactory my_factory;
		Team * my = game.createTeam(my_factory);
		my->info_();
	}
	else {
		NorwayAthleteFactory my_factory;
		Team * my = game.createTeam(my_factory);
		my->info_();
	}
	return 0;
}