#ifndef FORCESENSOR_H
#define FORCESENSOR_H
#include "NaoRobotAPI.h"
#include <iostream>

class ForceSensor {
private:
	double force;
	NaoRobotAPI* RobotAPI;
public:
	ForceSensor(NaoRobotAPI* nao) : RobotAPI(nao) {
		force = 0.0;
	}
	void updateSensor(double);
	double getForce() const;
	bool CheckFall() const;
};
#endif