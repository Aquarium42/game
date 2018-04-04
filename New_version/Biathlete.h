#pragma once
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
