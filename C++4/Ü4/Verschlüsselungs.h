#pragma once
#include <string>

class Verschl�sselungs {
public:
    Verschl�sselungs(); // Standardkonstruktor mit Schl�ssel "+2"
    explicit Verschl�sselungs(int shiftKey); // Parametrisierter Konstruktor f�r benutzerdefinierten Schl�ssel

    std::string encrypt(const std::string& plaintext) const;
    std::string decrypt(const std::string& ciphertext) const;
    bool compare(const std::string& text1, const std::string& text2) const;
    int findKey(const std::string& plaintext, const std::string& ciphertext) const;

private:
    int shiftKey;
};

