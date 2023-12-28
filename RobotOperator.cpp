#include "RobotOperator.h"
#include <iostream>
#include "Encryption.h"

RobotOperator::RobotOperator(string n,string s, int code)
	: name(n), surname(s), accessCode(encryption->encrypt(code)), accessState(false) {}

bool RobotOperator::checkAccessCode(int enteredCode) {
	accessState = (accessCode == enteredCode);
	return accessState;
}

void RobotOperator::print() const{
	cout << "Operator: " << name << " " << surname << endl;
	cout << "Access Granted: " << (accessState ? "Yes" : "No") << endl;
}

int RobotOperator::encryptCode(int codeToEncrypt) {
	accessCode = encryption->encrypt(codeToEncrypt);
	return accessCode;
}

int RobotOperator::decryptCode(int encryptedCode) {
	accessCode = encryption->decrypt(accessCode);
	return accessCode;
}