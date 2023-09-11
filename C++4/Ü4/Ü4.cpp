#include<iostream>
#include<vector>
#include<string>
#include "Punkt.h"
#include "Rechteck.h"
#include "Verschlüsselungs.h"
#include "SIMcard.h"

using namespace std;


int main()
{
    std::cout << "Aufgabe 1\n ";
    Verschlüsselungs verschlusserl(20);
    string encryptedText;
    encryptedText = verschlusserl.encrypt("Vertiefung Programmierung");
    cout << encryptedText << endl;

    string decryptedText;
    decryptedText = verschlusserl.decrypt(encryptedText);
    cout << decryptedText << endl;

    cout << verschlusserl.compare(encryptedText, decryptedText) << endl;
    cout << verschlusserl.findKey(encryptedText, decryptedText) << endl;
    //____________________________________________________________________________________
    std::cout << "Aufgabe 2\n ";
    Punkt A, B;
    double x, y;
    cout << "Koordinaten x und y vom Punkt A(x,y): ";
    cin >> x >> y;
    A.set(x, y);
    cout << "Koordinaten x und y vom Punkt B(x,y): ";
    cin >> x >> y;
    B.set(x, y);

    Rechteck RE(A, B);
    cout << "Die Rechteckflaeche betraegt " << RE.Flaeche() << endl;
    double dUmfang;
    dUmfang = RE.Umfang();
    cout << "Der Umfang des Rechteckes betraegt " << dUmfang << endl;
    unsigned int uiUmfang;
    uiUmfang = RE.Umfang(true);
    cout << "Der gerundete Umfang des Rechteckes in Inches betraegt " << uiUmfang << endl;
    //________________________________________________________________________________________
    std::cout << "Aufgabe 3\n ";
    int pin;
    std::cout << "Bitte geben Sie die PIN der SIM-Karte ein: ";
    std::cin >> pin;

    SIMcard simcard(pin);

    while (true) {
        std::cout << "Optionen:\n1. Neuen Eintrag hinzufuegen\n2. Nummer suchen\n3. Beenden\n";
        int option;
        std::cin >> option;

        if (option == 1) {
            std::string name, telefonnummer;
            std::cout << "Name: ";
            std::cin >> name;
            std::cout << "Telefonnummer: ";
            std::cin >> telefonnummer;

            if (simcard.trageEin(name, telefonnummer, pin)) {
                std::cout << "Eintrag erfolgreich hinzugefuegt." << std::endl;
            }
            else {
                std::cout << "Falsche PIN. Eintrag konnte nicht hinzugefuegt werden." << std::endl;
            }
        }
        else if (option == 2) {
            std::string name;
            std::cout << "Name: ";
            std::cin >> name;

            int nummer = simcard.sucheNummer(name, pin);
            if (nummer == 0) {
                std::cout << "Eintrag nicht gefunden." << std::endl;
            }
            else if (nummer == -1) {
                std::cout << "Falsche PIN. Zugriff verweigert." << std::endl;
            }
            else {
                std::cout << "Telefonnummer: " << nummer << std::endl;
            }
        }
        else if (option == 3) {
            break;
        }
        else {
            std::cout << "Ungueltige Option. Bitte erneut versuchen." << std::endl;
        }
    }

    return 0;
}