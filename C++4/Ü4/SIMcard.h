#pragma once
#include <vector>
#include <string>
using namespace std;

struct Eintrag {
    std::string name;
    std::string telefonnummer;
};

class SIMcard {
public:
    SIMcard(int& pin);

    bool trageEin(const std::string& name, const std::string& telefonnummer, unsigned int pin);
    int sucheNummer(const std::string& name, unsigned int pin) const;

private:
    std::vector<Eintrag> telefonbuch;
    unsigned int pin_;
};


