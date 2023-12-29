#include "SonarSensor.h"

double SonarSensor::getRange(int index) const{
	robotAPI->getSonarRange(ranges[0], ranges[1]);
	if ((index != 1) && (index != 0)) {
		cerr << "\nError: Invalid index." << endl;
		exit(1);
	}
	return ranges[index];
}

double SonarSensor::getMax(int& index) {
    robotAPI->getSonarRange(ranges[0], ranges[1]);
    if (ranges[0] > ranges[1]) {
        index = 0;
        return ranges[0];
    }
    else {
        index = 1;
        return ranges[1];
    }
}

double SonarSensor::getMin(int& index)  {
    robotAPI->getSonarRange(ranges[0], ranges[1]);
    if (ranges[0] > ranges[1]) {
        index = 1;
        return ranges[1];
    }
    else {
        index = 0;
        return ranges[0];
    }
}

void SonarSensor::updateSensor() {
    robotAPI->getSonarRange(ranges[0], ranges[1]);
}

double SonarSensor::operator[](int i) {
    if ((i != 1) && (i != 0)) {
        cerr << "\nError: Subscript out of range" << endl;
        exit(1);
    }
    return ranges[i];
}
