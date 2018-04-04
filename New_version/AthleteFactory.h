#pragma once
#include "Hockey_player.h"
#include "Figure_skater.h"
#include "Biathlete.h"


// јбстрактна€ фабрика дл€ производства спортсменов
class AthleteFactory
{
public:
	virtual Hockey_player* createHockey() = 0;
	virtual Figure_skater* createSkater() = 0;
	virtual Biathlete* createBiathlete() = 0;
	virtual ~AthleteFactory() {}
};
