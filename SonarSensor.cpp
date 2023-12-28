#include "SonarSensor.h"

double SonarSensor::getRange(int index) const{
	robotAPI->getSonarRange(ranges[0], ranges[1]);
	if (index < 0 || index > 1) {
		throw std::exception("Out of range");
	}
	return ranges[index];
}

double SonarSensor::getMax(int& index) const {
	robotAPI->getSonarRange(ranges[0], ranges[1]);
	if (ranges[0] > ranges[1]) return ranges[0];
	else return ranges[1];
}

double SonarSensor::getMin(int& index) const {
	robotAPI->getSonarRange(ranges[0], ranges[1]);
	if (ranges[0] > ranges[1]) return ranges[1];
	else return ranges[0];
}

void SonarSensor::updateSensor(double* _ranges) {
	ranges[0] = _ranges[0];
	ranges[1] = _ranges[1];
}

double SonarSensor::operator[](int i) {
	return ranges[i];
}