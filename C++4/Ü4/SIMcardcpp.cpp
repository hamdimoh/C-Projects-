#include "SIMcard.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

SIMcard::SIMcard(int& pin) : pin_(pin) {}

bool SIMcard::trageEin(const std::string& name, const std::string& telefonnummer, unsigned int pin) {
    if (pin != pin_) {
        return false;
    }

    Eintrag neuerEintrag = { name, telefonnummer };
    telefonbuch.push_back(neuerEintrag);
    return true;
}

int SIMcard::sucheNummer(const std::string& name, unsigned int pin) const {
    if (pin != pin_) {
        return -1;
    }



    return 0;
}