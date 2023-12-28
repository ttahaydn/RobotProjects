#pragma once
#define POSE_H

class Pose {
private:
    double x;
    double y;
    double th;

public:
    Pose();
    Pose(double _x, double _y, double _th);

    double getX() const;
    void setX(double _x);

    double getY() const;
    void setY(double _y);

    double getTh() const;
    void setTh(double _th);

    bool operator==(const Pose& other) const;

    Pose operator+(const Pose& other) const;

    Pose operator-(const Pose& other) const;

    Pose& operator+=(const Pose& other);

    Pose& operator-=(const Pose& other);

    bool operator<(const Pose& other) const;

    void getPose(double& _x, double& _y, double& _th) const;

    void setPose(double _x, double _y, double _th);

    double findDistanceTo(const Pose& pos) const;

    double findAngleTo(const Pose& pos) const;
};


