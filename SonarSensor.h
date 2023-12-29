#ifndef SONARSENSOR_H
#define SONARSENSOR_H
#include "NaoRobotAPI.h"
#include <iostream>

class SonarSensor {
private:
	double* ranges = new double[2];
	NaoRobotAPI* robotAPI;
public:
	SonarSensor(NaoRobotAPI* nao) : robotAPI(nao) {
		for (int i = 0; i < 2; i++) {
			ranges[i] = 0.0;
		}
	}
	double getRange(int) const;
	double getMax(int&);
	double getMin(int&);
	void updateSensor();
	double operator[](int);
};
#endif