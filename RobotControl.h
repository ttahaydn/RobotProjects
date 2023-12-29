
#pragma once
#include "Pose.h"

class NaoRobotAPI; 

class RobotControl{    
private:
        static Pose* position;
        NaoRobotAPI* robotAPI;
        int state;
public:
        //RobotControl(Pose* pose, NaoRobotAPI* api) : position(pose), robotAPI(api), state(0) {}
        RobotControl() : robotAPI(nullptr), state(0) {}
        ~RobotControl() {}

        void connect();
        void disconnect();
        void turnLeft();
        void turnRight();
        void forward();
        void print();
        void backward();
        Pose getPose();
        void moveLeft();
        void moveRight();
        void stop();
        Pose* givePose();

    };


