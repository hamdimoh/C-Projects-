#include <iostream>
#include <map>
#include <string>

using namespace std;


int main() {
    map<::string, string> phoneBook;
    string name, phoneNumber;
    int o;

    while (true) {
        std::cout << "Optionen:\n1.Eingabe eines Namens mit Tel-Nummer\n2. Ausgabe aller Nutzern mit Tel-Nummer \n"
            << "3. Exit\n";
        std::cout << "Option Eingabe: ";
        cin >> o;
        if (o == 1) {
            std::cout << "gib Name ein";
            cin >> name;


            auto t = phoneBook.find(name);
            if (t != phoneBook.end()) {
                std::cout << "Tel-Nr: " << t->second << endl;
            }
            else {
                std::cout << "Gib Tel-Nr ein: ";
                cin >> phoneNumber;
                phoneBook[name] = phoneNumber;
            }
        }
        else if (o == 2) {

            std::cout << "Alle Telefonbuecher:" << endl;
            for (const auto& entry : phoneBook) {
                std::cout << "Name: " << entry.first << ", Tel-Nr: " << entry.second << endl;
            }
        }
        else if (o == 3) {
            break;
        }
        else {
            std::cout << "ungueltige Option- bitte versuchen Sie nochmal" << endl;
        }
        
    }
    
  
   
      


    //________________________________________________________________________________
    std::cout << "Aufgabe 2" << endl;

   multimap<int, string> fleet;
    int option;

    while (true) {
        std::cout << "Optionen:\n1. Eingabe von Nutzer + Fahrzeug\n2. Ausgabe aller Nutzer mit Fahrzeugen\n"
            << "3. Suche nach den Nutzern zugeordneten Fahrzeugen\n4. Entfernen von Nutzern mit den Ihnen zugehoerigen Fahrzeugen.\n5. Exit\n";
        std::cout << "Enter option: ";
        cin >> option;

        if (option == 1) {
            int userId;
            string vehicleType;

            std::cout << "Gib user ID ein: ";
            cin >> userId;
            std::cout << "Gib Fahrzeug type ein: ";
            cin >> vehicleType;
           
          

            fleet.insert({ userId, {vehicleType} });
        }
        else if (option == 2) {
            std::cout << "Users mit Fahtzeug:" << endl;
            for (const auto& entry : fleet) {
                std::cout << "User ID: " << entry.first << ", Fahrzeug type: " << entry.second<< endl;
            }
        }
        else if (option == 3) {
            int userId;
            std::cout << "Gib user ID ein um zu suchen: ";
            cin >> userId;

            auto range = fleet.equal_range(userId);
            if (range.first == range.second) {
                std::cout << "User mit ID nicht gefunden: " << userId << endl;
            }
            else {
                std::cout << "Fahrzeug vom user ID " << userId << ":" << endl;
                for (auto it = range.first; it != range.second; ++it) {
                    std::cout << "Fahrzeug type: " << it->second<< endl;
                }
            }
        }
        else if (option == 4) {
            int userId;
            std::cout << "gib user ID ein um zu loeschen : ";
            cin >> userId;

            fleet.erase(userId);
            std::cout << "User mit ID " << userId << " Das damit verbundene Fahrzeug ist geloescht." << endl;
        }
        else if (option == 5) {
            break;
        }
        else {
            std::cout << "ungueltige Option- bitte versuchen Sie nochmal." << endl;
        }
    }


    return 0;
}