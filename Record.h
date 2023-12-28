#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Record {
private:
    string fileName;
    fstream file;

public:
    Record();
    ~Record();

    bool openFile();
    bool closeFile();
    void setFileName(const string& filename);

    string readLine();
    bool writeLine(const string& data);

    Record& operator<<(const std::string& data);
    Record& operator>>(std::string& data);
};