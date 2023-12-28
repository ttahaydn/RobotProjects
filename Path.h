#pragma once
#include <ostream>
#include <iostream>
#include "Node.h"
#include <vector>
#include "Pose.h"

using namespace std;
class Path {
private:
	Node* tail;
	Node* head;
	int number;
public:
    Path() : tail(nullptr), head(nullptr), number(0) {};
    ~Path();
    void addPos(Pose*);
    void print() const;
    vector<Pose> operator[](int i) const;
    Pose* getPos(int index) const;
    bool removePos(int index);
    bool insertPos(int index,const Pose& pose);
    friend ostream& operator<<(ostream& os, const Path& path);
    friend istream& operator>>(istream& is, Path& path);
};

