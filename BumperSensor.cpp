#include "BumperSensor.h"

bool BumperSensor::getState(int index) const {
	return states[index];
}

void BumperSensor::updateSensor() {
	bool leftFoot_left, leftFoot_right, rightFoot_left, rightFoot_right;
	RobotAPI->getFootBumpers(leftFoot_left, leftFoot_right, rightFoot_left, rightFoot_right);
	states[0] = leftFoot_left;
	states[1] = leftFoot_right;
	states[2] = rightFoot_left;
	states[3] = rightFoot_right;
};

bool BumperSensor::checkTouch() const {
	for (int i = 0;i < 3; i++) {
		if (states[i]) return true;
	}
	return false;
}

