#include "Verschl�sselungs.h"

Verschl�sselungs::Verschl�sselungs() : shiftKey(2) {}

Verschl�sselungs::Verschl�sselungs(int shiftKey) : shiftKey(shiftKey) {}

std::string Verschl�sselungs::encrypt(const std::string& plaintext) const {
    std::string ciphertext;
    for (char c : plaintext) {
        if (std::isalpha(c)) {
            char base = std::islower(c) ? 'a' : 'A';
            c = (c - base + shiftKey) % 26 + base;
        }
        ciphertext += c;
    }
    return ciphertext;
}

std::string Verschl�sselungs::decrypt(const std::string& ciphertext) const {
    return encrypt(ciphertext); 
}

bool Verschl�sselungs::compare(const std::string& text1, const std::string& text2) const {
    return encrypt(text1) == encrypt(text2);
}

int Verschl�sselungs::findKey(const std::string& plaintext, const std::string& ciphertext) const {
    int key = 0;
    while (encrypt(plaintext) != ciphertext) {
        key++;
    }
    return key;
}