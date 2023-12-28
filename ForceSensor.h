#ifndef FORCESENSOR_H
#define FORCESENSOR_H
#include "NaoRobotAPI.h"
#include <iostream>

class ForceSensor {
private:
	double force;
	NaoRobotAPI* RobotAPI;
public:
	void updateSensor(double);
	double getForce() const;
	bool CheckFall() const;
};
#endif