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

void Path::addPos(Pose* pos) {
    Node* newnode = new Node;
    newnode->pose = (*pos);
    newnode->next = nullptr;
    if (tail == nullptr) {
        head = newnode;
    }
    else {
        tail->next = newnode;
    }

    tail = newnode;
    number++;         
}

void Path::print() const {
    Node* current = head;
    while (current != nullptr) {
        // Her Node'daki Pose nesnesinin �zelliklerini manuel olarak yazd�r�yoruz.
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

    // �stenen indekse kadar ilerle.
    while (current != nullptr && count < index) {
        current = current->next;
        count++;
    }

    // E�er indeks ge�erliyse ve Node bulunmu�sa, Pose'u d�nd�r.
    if (current != nullptr) {
        return &(current->pose);
    }
    else {
        // E�er indeks ge�erli de�ilse veya liste yeterince uzun de�ilse,
        Pose* p = new Pose();
        // varsay�lan bir Pose d�nd�r.
        return p;
    }
}

bool Path::removePos(int index) {
    // E�er liste bo�sa veya index negatifse
    if (head == nullptr || index < 0) {
        return false;
    }

    Node* current = head;
    Node* prev = nullptr;

    // �lk eleman� silmek istiyorsak
    if (index == 0) {
        head = current->next; // head'i ikinci elemana ta��
        delete current; // Eski head'i sil
        return true;
    }

    // Silinecek Node'a kadar ilerle
    for (int i = 0; current != nullptr && i < index; ++i) {
        prev = current;
        current = current->next;
    }

    // E�er current null ise, index liste boyutunu a��yor demektir
    if (current == nullptr) {
        return false;
    }

    // current'i listeden ��kar
    prev->next = current->next;
    delete current; // Node'u bellekten sil

    return true;
}


bool Path::insertPos(int index, const Pose& pose) {
    if (index < 0) {
        return false; // Negatif indeks ge�ersizdir.
    }

    Node* current = head;
    for (int i = 0; current != nullptr && i < index; ++i) {
        current = current->next;
    }

    if (current == nullptr) {
        return false; // Indeks liste boyutunu a��yorsa
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
    // Klavyeden okunacak Pose nesnesi i�in yerel de�i�kenler
    float x, y, theta;

    // Kullan�c�dan Pose bilgilerini al
    std::cout << "Enter Pose x :";
    is >> x;
    std::cout << "Enter Pose y :";
    is >> y;
    std::cout << "Enter Pose th :";
    is >> theta;

    // Yeni Pose nesnesi olu�tur
    Pose pose(x, y, theta);

    // Yeni Pose nesnesini Path'e ekle
    path.addPos(&pose);

    // ��lem ba�ar�l�ysa istream'i d�nd�r
    return is;
}



