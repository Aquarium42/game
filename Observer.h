#pragma once
class Observer {
	Team* model;
	int count_died;
public:
	Observer(Team* team_) {
		model = team_;
		count_died = 0;
		model->attach(this);
	}

	bool is_any_live() {
		if (count_died != 3) {
			return true;
		}
		else return false;
	}
	virtual void update() = 0;
protected:
	Team * getSubject() {
		return model;
	}
	void increase_count_died() {
		count_died++;
	}
};

class Lived_player : public Observer {
public: 
	Lived_player(Team* team_): Observer(team_){}
	void update() {
		increase_count_died();
	}
};