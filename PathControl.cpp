
#include "RobotControl.h"
#include "NaoRobotAPI.h"
#include "Path.h"
#include "pose.h"
#include "iostream"



RobotControl* nao1;
Pose* RobotControl::position = new Pose();

int main() {
	Path* P = new Path();
	nao1 = new RobotControl();

	nao1->connect();
	nao1->moveLeft();
	Sleep(8000);
	nao1->moveRight();
	Sleep(8000);
	nao1->turnLeft();
	Sleep(8000);
	nao1->turnRight();
	Sleep(8000);
	nao1->print();
	nao1->forward();
	Sleep(8000);
	P->addPos(nao1->givePose());
	nao1->forward();
	Sleep(8000);
	P->addPos(nao1->givePose());
	nao1->turnRight();
	Sleep(8000);
	nao1->forward();
	Sleep(8000);
	P->addPos(nao1->givePose());
	nao1->backward();
	Sleep(8000);
	P->addPos(nao1->givePose());
	P->removePos(3);
	nao1->moveRight();
	Sleep(8000);
	nao1->forward();
	Sleep(8000);
	Pose pose1 = *nao1->givePose();
	P->insertPos(3, pose1);
	delete nao1;
	std::cout << *P;
	std::cin >> *P;
	nao1->moveRight();
	Sleep(7000);
	std::cout << *P;

	delete nao1;

	return 0;
}