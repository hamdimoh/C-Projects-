#include "Verschlüsselungs.h"

Verschlüsselungs::Verschlüsselungs() : shiftKey(2) {}

Verschlüsselungs::Verschlüsselungs(int shiftKey) : shiftKey(shiftKey) {}

std::string Verschlüsselungs::encrypt(const std::string& plaintext) const {
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

std::string Verschlüsselungs::decrypt(const std::string& ciphertext) const {
    return encrypt(ciphertext); 
}

bool Verschlüsselungs::compare(const std::string& text1, const std::string& text2) const {
    return encrypt(text1) == encrypt(text2);
}

int Verschlüsselungs::findKey(const std::string& plaintext, const std::string& ciphertext) const {
    int key = 0;
    while (encrypt(plaintext) != ciphertext) {
        key++;
    }
    return key;
}