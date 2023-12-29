#include "RobotControl.h"
#include "NaoRobotAPI.h"
#include <iostream>


void RobotControl::connect()
{
    robotAPI->connect();
}

void RobotControl::disconnect()
{
    robotAPI->disconnect();
}

void RobotControl::turnLeft() {
    robotAPI->turnRobot(LEFT);
    RobotControl::getPose();
}

void RobotControl::turnRight() {
    robotAPI->turnRobot(RIGHT);
    RobotControl::getPose();
}

void RobotControl::forward() {
    robotAPI->moveRobot(FORWARD);
    RobotControl::getPose();
}

void RobotControl::print() {

    /*! Read sonar range values.*/
    double sonarLeft, sonarRight;
    robotAPI->getSonarRange(sonarLeft, sonarRight);

    /*! Read foot bumper values.*/
    bool leftFoot_left, leftFoot_right, rightFoot_left, rightFoot_right;
    robotAPI->getFootBumpers(leftFoot_left, leftFoot_right, rightFoot_left, rightFoot_right);

    cout << "--------------------SENSOR VALUES-------------------------------------" << endl;
    cout << "POSE         : (X) " << robotAPI->getX() << " meters, "
        << "(Y) " << robotAPI->getY() << " meters, "
        << "(Th) " << robotAPI->getTh() << " degrees" << endl << endl;
    cout << "SONAR RANGES : (LEFT) " << sonarLeft
        << " meters, (RIGHT) " << sonarRight << " meters" << endl << endl;
    cout << "FOOT FORCE   : " << robotAPI->getFootForce() << " kg.f" << endl;
    cout << "----------------------------------------------------------------------" << endl;
}

void RobotControl::backward() {
    robotAPI->moveRobot(BACKWARD);
    RobotControl::getPose();
}

Pose RobotControl::getPose() {
    position->setX(robotAPI->getX());
    position->setY(robotAPI->getY());
    position->setTh(robotAPI->getTh());

    return *position;
}

void RobotControl::moveLeft() {
    robotAPI->moveRobot(LEFT);
    RobotControl::getPose();
}

void RobotControl::moveRight() {
    robotAPI->moveRobot(RIGHT);
    RobotControl::getPose();
}

void RobotControl::stop() {
    robotAPI->stopRobot();
}

Pose* RobotControl::givePose()
{
    return position;
}

