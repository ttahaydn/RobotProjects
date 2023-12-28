#include "ForceSensor.h"

void ForceSensor::updateSensor(double force){
	force = RobotAPI->getFootForce();
}

double ForceSensor::getForce() const {
	return force;
}

bool ForceSensor::CheckFall() const {
	if (force < 0.09) return true;
	else return false;
}