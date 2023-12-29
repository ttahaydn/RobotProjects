#include "Path.h"
#include "Node.h"
#include "RobotControl.h"



Path::~Path() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

/**
 * @brief Adds a new position to the path.
 *
 * This method creates a new node in the path, setting its pose to the provided
 * Pose object and appending it to the end of the linked list. If the list is
 * empty (tail is nullptr), the new node becomes the head of the list. Otherwise,
 * it is appended after the current tail and the tail pointer is updated to the
 * new node. The number of nodes in the path is incremented.
 *
 * @param pos Pointer to the Pose object to add to the path.
 */
void Path::addPos(Pose* pos) {
    Node* newnode = new Node;  // Creates a new Node object dynamically.
    newnode->pose = (*pos);    // Dereferences the pos pointer and assigns the pose to the new node.
    newnode->next = nullptr;   // Sets the next pointer of the new node to nullptr.

    if (tail == nullptr) {     // Checks if the list is currently empty.
        head = newnode;        // If empty, the new node becomes the head of the list.
    }
    else {
        tail->next = newnode;  // If not empty, appends the new node after the current tail.
    }

    tail = newnode;            // Updates the tail pointer to the new node.
    number++;                  // Increments the number of nodes in the path.
}

void Path::print() const {
    Node* current = head;
    while (current != nullptr) {
        /*!We manually print the properties of the Pose object in each Node.*/
        std::cout << "Pose: x=" << current->pose.getX()
        << ", y=" << current->pose.getY()
            << ", theta=" << current->pose.getTh() << std::endl;
        current = current->next;
    }
}

vector<Pose> Path::operator[](int i) const
{
    return vector<Pose>(i);
}

Pose* Path::getPos(int index) const {
    Node* current = head;
    int count = 0;

    /*!Scroll to the desired index.*/
    while (current != nullptr && count < index) {
        current = current->next;
        count++;
    }

    /*!If the index is valid and Node is found, return Pose.*/
    if (current != nullptr) {
        return &(current->pose);
    }
    else {
        /*!If the index is not valid or the list is not long enough,*/
        Pose* p = new Pose();
        /*!Return a default Pose.*/
        return p;
    }
}

bool Path::removePos(int index) {
    /*!If the list is empty or the index is negative*/
    if (head == nullptr || index < 0) {
        return false;
    }

    Node* current = head;
    Node* prev = nullptr;

    /*!If we want to delete the first element*/
    if (index == 0) {
        head = current->next; /*!Move head to second element.*/
        delete current; /*!Delete old head.*/
        return true;
    }

    /*!Scroll down to the Node to delete.*/
    for (int i = 0; current != nullptr && i < index; ++i) {
        prev = current;
        current = current->next;
    }

    /*!If current is null, the index exceeds the list size.*/
    if (current == nullptr) {
        return false;
    }

    /*!Remove Current from the list.*/
    prev->next = current->next;
    delete current; /*!Delete the node from memory.*/

    return true;
}


bool Path::insertPos(int index, const Pose& pose) {
    if (index < 0) {
        return false; /*! A negative index is invalid.*/
    }

    Node* current = head;
    for (int i = 0; current != nullptr && i < index; ++i) {
        current = current->next;
    }

    if (current == nullptr) {
        return false; /*!If the index exceeds the list size.*/
    }

    Node* newNode = new Node(pose);
    newNode->next = current->next;
    current->next = newNode;

    return true;
}

std::ostream& operator<<(std::ostream& os, const Path& path) {
    Node* current = path.head;
    while (current != nullptr) {
        os << "Pose: x=" << current->pose.getX()
            << ", y=" << current->pose.getY()
            << ", theta=" << current->pose.getTh() << std::endl;
        current = current->next;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Path& path) {
    /*!Local variables for the Pose object to be read from the keyboard.*/
    float x, y, theta;

    /*!Get Pose information from the user.*/
    std::cout << "Enter Pose x :";
    is >> x;
    std::cout << "Enter Pose y :";
    is >> y;
    std::cout << "Enter Pose th :";
    is >> theta;

    /*!Create a new Pose object.*/
    Pose pose(x, y, theta);

    /*!Add the new Pose object to Path.*/
    path.addPos(&pose);

    /*!Return the stream if the operation was successful.*/
    return is;
}



