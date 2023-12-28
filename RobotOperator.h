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
	int encryptCode(int codeToEncrypt);
	int decryptCode(int encryptedCode);
	Encryption* encryption;
public:
	RobotOperator(string n, string s, int code);
	bool checkAccessCode(int);
	void print() const;
};