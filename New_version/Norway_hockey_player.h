#include"Hockey_player.h"
#include <iostream>
class NorwayHockey : public Hockey_player
{
public:
	void info() {
		std::cout << "NorwayHockey info" << std::endl;
		std::cout << "endurance = " << endurance << ". accuracy =" << accuracy << "energy = " << energy << std::endl;
	}
	void score_goal() {
		std::cout << "EEeee, you score a goal!NORWAY!!!";//����� �� ���� ����� ����������
	}
private:
	const int accuracy = 7;
	const int endurance = 7;

};

