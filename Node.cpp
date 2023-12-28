#include "Node.h"
#include "Pose.h"
Node::Node(const Pose& pose) : next(nullptr), pose(pose) {}
Node::Node() : next(nullptr) {} 