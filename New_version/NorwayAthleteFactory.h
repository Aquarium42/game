#pragma once
#include"AthleteFactory.h"
#include"Norway_hockey_player.h"
#include"Norway_figure_skater.h"
#include"Norway_biathlete.h"

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

