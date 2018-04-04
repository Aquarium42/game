#pragma once
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