#include "Record.h"

using namespace std;

Record::Record() {
    // Constructor logic
}

Record::~Record() {
    // Destructor logic
    closeFile();
}

bool Record::openFile() {
    file.open(fileName, ios::in | ios::out | ios::app);
    if (!file.is_open()) {
        cerr << "Error opening file: " << fileName << endl;
        return false;
    }
    return true;
}

bool Record::closeFile() {
    if (file.is_open()) {
        file.close();
        return true;
    }
    return false;
}

void Record::setFileName(const string& filename) {
    closeFile();
    fileName = filename;
    openFile();
}

string Record::readLine() {
    string line;
    getline(file, line);
    return line;
}

bool Record::writeLine(const string& data) {
    if (file.is_open()) {
        file << data << endl;
        return true;
    }
    return false;
}

Record& Record::operator<<(const string& data) {
    writeLine(data);
    return *this;
}

Record& Record::operator>>(string& data) {
    data = readLine();
    return *this;
}