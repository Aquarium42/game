#pragma once
class Hockey_player
{
protected:
	int energy = 100;
public:
	virtual void score_goal() = 0;
	virtual void info() = 0;
	virtual ~Hockey_player()
	{}
};


