#pragma once
#include"AthleteFactory.h"
#include"Norway_hockey_player.h"
#include"Norway_figure_skater.h"
#include"Norway_biathlete.h"
#include"Composite.h"
#include "Decorator.h"

// ������� ��� �������� ����������� ��������
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
	Figure_skater* createFigureOlympicChempion() {
		return new OlympicChempion(new(NorwaySkater)); // ���������, ������� �� ������ ���������, � ������� ������������ �������, �������� ������ ������ ������
	}
	Figure_skater* createFigureSometimesOlympicChempion() {
		return new OlympicChempion(new OlympicChempion(new(NorwaySkater))); // ������������ ����������� �������
	}

};

