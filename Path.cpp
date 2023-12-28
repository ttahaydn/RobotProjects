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
        // Her Node'daki Pose nesnesinin özelliklerini manuel olarak yazdýrýyoruz.
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

    // Ýstenen indekse kadar ilerle.
    while (current != nullptr && count < index) {
        current = current->next;
        count++;
    }

    // Eðer indeks geçerliyse ve Node bulunmuþsa, Pose'u döndür.
    if (current != nullptr) {
        return &(current->pose);
    }
    else {
        // Eðer indeks geçerli deðilse veya liste yeterince uzun deðilse,
        Pose* p = new Pose();
        // varsayýlan bir Pose döndür.
        return p;
    }
}

bool Path::removePos(int index) {
    // Eðer liste boþsa veya index negatifse
    if (head == nullptr || index < 0) {
        return false;
    }

    Node* current = head;
    Node* prev = nullptr;

    // Ýlk elemaný silmek istiyorsak
    if (index == 0) {
        head = current->next; // head'i ikinci elemana taþý
        delete current; // Eski head'i sil
        return true;
    }

    // Silinecek Node'a kadar ilerle
    for (int i = 0; current != nullptr && i < index; ++i) {
        prev = current;
        current = current->next;
    }

    // Eðer current null ise, index liste boyutunu aþýyor demektir
    if (current == nullptr) {
        return false;
    }

    // current'i listeden çýkar
    prev->next = current->next;
    delete current; // Node'u bellekten sil

    return true;
}


bool Path::insertPos(int index, const Pose& pose) {
    if (index < 0) {
        return false; // Negatif indeks geçersizdir.
    }

    Node* current = head;
    for (int i = 0; current != nullptr && i < index; ++i) {
        current = current->next;
    }

    if (current == nullptr) {
        return false; // Indeks liste boyutunu aþýyorsa
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
    // Klavyeden okunacak Pose nesnesi için yerel deðiþkenler
    float x, y, theta;

    // Kullanýcýdan Pose bilgilerini al
    std::cout << "Enter Pose x :";
    is >> x;
    std::cout << "Enter Pose y :";
    is >> y;
    std::cout << "Enter Pose th :";
    is >> theta;

    // Yeni Pose nesnesi oluþtur
    Pose pose(x, y, theta);

    // Yeni Pose nesnesini Path'e ekle
    path.addPos(&pose);

    // Ýþlem baþarýlýysa istream'i döndür
    return is;
}



