#pragma once
#include <string>

class Verschlüsselungs {
public:
    Verschlüsselungs(); // Standardkonstruktor mit Schlüssel "+2"
    explicit Verschlüsselungs(int shiftKey); // Parametrisierter Konstruktor für benutzerdefinierten Schlüssel

    std::string encrypt(const std::string& plaintext) const;
    std::string decrypt(const std::string& ciphertext) const;
    bool compare(const std::string& text1, const std::string& text2) const;
    int findKey(const std::string& plaintext, const std::string& ciphertext) const;

private:
    int shiftKey;
};

