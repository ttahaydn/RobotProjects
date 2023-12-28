#ifndef BUMPERSENSOR_H
#define BUMPERSENSOR_H
#include "NaoRobotAPI.h"
#include <iostream>

class BumperSensor {
private:
	bool* states = new bool[4];
	NaoRobotAPI* RobotAPI;
public:
	BumperSensor(NaoRobotAPI* nao) : RobotAPI(nao) {
		for (int i = 0;i < 4;i++) {
			states[i] = false;
		}
	}
	bool getState(int) const;
	void updateSensor();
	bool checkTouch() const;
};

#endif