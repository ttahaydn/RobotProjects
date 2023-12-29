#include "Encryption.h"
#include <iostream>

using namespace std;

int Encryption::encrypt(int num) {
    if (num < 1000 || num > 9999) {
        // Hata durumu: Sayý 4 basamaklý deðil
        cout << "Error: Input must be a 4-digit number." << endl;
        exit(1);
    }

    int d1 = (num % 10 + 7) % 10;
    int d2 = ((num / 10) % 10 + 7) % 10;
    int d3 = ((num / 100) % 10 + 7) % 10;
    int d4 = (num / 1000 + 7) % 10;

    int encryptedNum = d2 * 1000 + d1 * 100 + d4 * 10 + d3;
    return encryptedNum;
}


int Encryption::decrypt(int encryptedNum) {
    if (encryptedNum < 1000  ||  encryptedNum > 9999) {
        // Hata durumu: Sayý 4 basamaklý deðil
        cout << "Error: Input must be a 4-digit number." << endl;
        exit(1);
    }
    int d1 = (encryptedNum % 10 + 3) % 10;
    int d2 = ((encryptedNum / 10) % 10 + 3) % 10;
    int d3 = ((encryptedNum / 100) % 10 + 3) % 10;
    int d4 = (encryptedNum / 1000 + 3) % 10;


    int decryptedNum = d2 * 1000 + d1 * 100 + d4 * 10 + d3;

    return decryptedNum;
}