#pragma once
#include "Pose.h"
class Node
{
public:
	Node* next;
	Pose pose;
	Node(const Pose&);
	Node();

};