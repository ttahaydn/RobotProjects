#include "Encryption.h"

int Encryption::encrypt(int number) {
    
    int encryptedNumber = ((number % 10) + 7) % 10 * 1000 + (((number / 10) % 10) + 7) % 10 * 100 + (((number / 100) % 10) + 7) % 10 * 10 + ((number / 1000) + 7) % 10;
    encryptedNumber = (encryptedNumber / 1000) * 1000 + ((encryptedNumber / 100) % 10) * 100 + ((encryptedNumber / 10) % 10) * 10 + (encryptedNumber % 10);
    encryptedNumber = ((encryptedNumber / 1000) * 1000) + ((encryptedNumber % 10) * 100) + ((encryptedNumber / 10) % 10) * 10 + ((encryptedNumber / 100) % 10);
    return encryptedNumber;
}

int Encryption::decrypt(int encryptedNumber) {
    int decryptedNumber = ((encryptedNumber / 1000) + 3) % 10 * 1000 + (((encryptedNumber / 100) % 10) + 3) % 10 * 100 + (((encryptedNumber / 10) % 10) + 3) % 10 * 10 + ((encryptedNumber % 10) + 3) % 10;
    return decryptedNumber;
}