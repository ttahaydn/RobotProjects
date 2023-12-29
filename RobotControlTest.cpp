//
//#include "RobotControl.h"
//#include "NaoRobotAPI.h"
//#include "Path.h"
//#include "pose.h"
//#include "iostream"
//
//
//
//RobotControl* nao1; 
//Pose* RobotControl::position = new Pose();
//
//int main() {
//	Path* P = new Path();
//	nao1 = new RobotControl();
//
//	nao1->connect();
//	nao1->forward();
//	Sleep(5000);
//	nao1->forward();
//	Sleep(4000);
//	P->addPos(nao1->givePose());
//	nao1->forward();
//	Sleep(5000);
//	P->print();
//	nao1->turnLeft();
//	Sleep(5000);
//	nao1->forward();
//	Sleep(5000);
//	std::cin >> *P;
//	Sleep(2000);
//	nao1->backward();
//	Sleep(5000);
//	std::cout << *P;
//	nao1->backward();
//	Sleep(2000);
//	nao1->stop();
//
//	delete nao1;
//
//
//	return 0;
//}