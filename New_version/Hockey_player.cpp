#include "stdafx.h"
#include"Hockey_player.h"
int Hockey_player::get_score() {
	return score;
}
bool Hockey_player::isenergy() {
	if (energy > 0) {
		return true;
	}
	else return false;

}