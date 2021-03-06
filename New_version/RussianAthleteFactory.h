#pragma once
#include"AthleteFactory.h"
#include"Russian_hockey_player.h"
#include"Russian_figure_skater.h"
#include"Russian_biathlete.h"
#include "Decorator.h"

// ������� ��� �������� ������� �����������
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
		return new OlympicChempion(new(RussianSkater)); // ���������, ������� �� ������ ���������, � ������� ������������ �������, �������� ������ ������ ������
	}
	Figure_skater* createFigureSometimesOlympicChempion() {
		return new OlympicChempion( new OlympicChempion(new(RussianSkater))); // ������������ ����������� �������
	}

};

