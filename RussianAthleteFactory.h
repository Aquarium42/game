#pragma once
#include"AthleteFactory.h"
#include"Russian_hockey_player.h"
#include"Russian_figure_skater.h"
#include"Russian_biathlete.h"
#include "Decorator.h"

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
	Figure_skater* createFigureOlympicChempion() {
		return new OlympicChempion(new(RussianSkater)); // декоратор, сделали не просто фигуриста, а бывшего олимпийского чемиона, умеющего делать крутые прыжки
	}
	Figure_skater* createFigureSometimesOlympicChempion() {
		return new OlympicChempion( new OlympicChempion(new(RussianSkater))); // многократный олимпийский чемпион
	}

};

