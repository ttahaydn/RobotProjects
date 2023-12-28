
#include "Pose.h"
#include <iostream>
#include <cmath>

using namespace std;
Pose::Pose() : x(0), y(0), th(0) {}

Pose::Pose(double _x, double _y, double _th) : x(_x), y(_y), th(_th) {}

double Pose::getX() const {
    return x;
}

void Pose::setX(double _x) {
    x = _x;

}

double Pose::getY() const {
    return y;
}

void Pose::setY(double _y) {
    y = _y;
}

double Pose::getTh() const {
    return th;
}

void Pose::setTh(double _th) {
    th = _th;
}

bool Pose::operator==(const Pose& other) const {
    return x == other.x && y == other.y && th == other.th;
}

Pose Pose::operator+(const Pose& other) const {
    return Pose(x + other.x, y + other.y, th + other.th);
}

Pose Pose::operator-(const Pose& other) const {
    return Pose(x - other.x, y - other.y, th - other.th);
}

Pose& Pose::operator+=(const Pose& other) {
    x += other.x;
    y += other.y;
    th += other.th;
    return *this;
}

Pose& Pose::operator-=(const Pose& other) {
    x -= other.x;
    y -= other.y;
    th -= other.th;
    return *this;
}

bool Pose::operator<(const Pose& other) const {
    return x < other.x || (x == other.x && (y < other.y || (y == other.y && th < other.th)));
}

void Pose::getPose(double& _x, double& _y, double& _th) const {
    _x = x;
    _y = y;
    _th = th;
}

void Pose::setPose(double _x, double _y, double _th) {
    x = _x;
    y = _y;
    th = _th;
}

double Pose::findDistanceTo(const Pose& pos) const {
    return sqrt(pow(x - pos.x, 2) + pow(y - pos.y, 2));
}

double Pose::findAngleTo(const Pose& pos) const {
    return atan2(pos.y - y, pos.x - x) - th;
}
