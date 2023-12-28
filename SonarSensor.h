#ifndef SONARSENSOR_H
#define SONARSENSOR_H
#include "NaoRobotAPI.h"
#include <iostream>

class SonarSensor {
private:
	double* ranges = new double[2];
	NaoRobotAPI* robotAPI;
public:
	double getRange(int) const;
	double getMax(int&) const;
	double getMin(int&) const;
	void updateSensor(double*);
	double operator[](int);
};
#endif