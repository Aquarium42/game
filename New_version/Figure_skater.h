#pragma once
class Figure_skater
{
protected:
	int score = 0; //������������ ����
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
	}//� ���� ��������. ��������� ������� ������ �������� �� �������
	virtual void info() = 0;
	virtual ~Figure_skater() {}
};