#include "RobotOperator.h"
#include <iostream>

using namespace std;

RobotOperator::RobotOperator(string n, string s, int code, Encryption& encryption)
    : name(n), surname(s), accessCode(encryption.encrypt(code)), accessState(false) {}

bool RobotOperator::checkAccessCode(int enteredCode) {
    accessState = (accessCode == enteredCode);
    return accessState;
}

void RobotOperator::print() const {
    cout << "Operator: " << name << " " << surname << endl;
    cout << "Access Granted: " << (accessState ? "Yes" : "No") << endl;
}

int RobotOperator::encryptCode(int codeToEncrypt, Encryption& encryption) {
    accessCode = encryption.encrypt(codeToEncrypt);
    return accessCode;
}

int RobotOperator::decryptCode(int encryptedCode, Encryption& encryption) {
    int decryptedCode = encryption.decrypt(encryptedCode);
    return decryptedCode;
}