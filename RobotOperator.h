#pragma once
#include <iostream>
#include <string>
#include "Encryption.h"

using namespace std;

class RobotOperator {
private:
    string name;
    string surname;
    unsigned int accessCode;
    bool accessState;

public:
    RobotOperator(string n, string s, int code, Encryption& encryption);
    bool checkAccessCode(int);
    void print() const;
    int encryptCode(int codeToEncrypt, Encryption& encryption);
    int decryptCode(int encryptedCode, Encryption& encryption);
};