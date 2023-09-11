#include <iostream>
#include <cmath>
#include <optional>

using namespace std;

//Aufgabe 1

void swapMitReferenzen(int& value1, int& value2) {
    value1 ^= value2;
    value2 ^= value1;
    value1 ^= value2;
}

void swapMitPointer(int* value1, int* value2) {
    *value1 ^= *value2;
    *value2 ^= *value1;
    *value1 ^= *value2;
}

//Aufgabe 2

void arrAusgabe(int* int_arr, int* letztes_element) {
    for (int* i = int_arr; i <= letztes_element; i++) {
        cout << *i << " ";
    }
    cout << endl;
}

void arrAusgabe(int* int_arr, int laengearr) {
    for (int i = 0; i < laengearr; i++) {
        cout << int_arr[i] << " ";
    }
    cout << endl;
}

//Aufgabe 3
bool rootSquad(float a_IN, float b_IN, float c_IN, float* d_OUT, float* e_OUT) {
    float discriminant = (b_IN * b_IN) - 4 * a_IN * c_IN;

    if (discriminant < 0) {
      
        return false;
    }

    *d_OUT = (-b_IN - sqrt(discriminant)) / (2 * a_IN);
    *e_OUT = (-b_IN + sqrt(discriminant)) / (2 * a_IN);

    return true;
}


int main()
{
    // Aufgabe 1
    int value1 = 13;
    int value2 = 23;
    cout << "Wert 1 = " << value1 << ", Wert 2 = " << value2 << endl;

    swapMitReferenzen(value1, value2);

    cout << "Swap mit Referenzen =>Nach Swap : Wert 1 = " << value1 << ", Wert 2 = " << value2 << endl << endl;

  
    value1 = 13;
    value2 = 23;
    cout << "Wert 1 = " << value1 << ", Wert 2 = " << value2 << endl;
    swapMitPointer(&value1, &value2);
    cout << "Swap mit Pointer =>Nach Swap: Wert 1 = " << value1 << ", Wert 2 = " << value2 << endl;

    //Aufgabe 2
    cout << "Aufgabe 2 " << endl;
    int array[8] = { 1, 2, 3, 4, 5,6,7,8 };
    arrAusgabe(array, (array + 7));
    arrAusgabe(array, 7);

    //Aufgabe 3
    cout << "Aufgabe 3 " << endl;
    float a, b, c, root1, root2;

    std::cout << "Geben Sie die Koeffizienten a, b und c ein: ";
    std::cin >> a >> b >> c;

    if (rootSquad(a, b, c, &root1, &root2)) {
        std::cout << "Reelle Loesungen gefunden:" << std::endl;
        std::cout << "Erste Loesung: " << root1 << std::endl;
        std::cout << "Zweite Loesung: " << root2 << std::endl;
    }
    else {
        std::cout << "Komplexe Loesungen gefunden." << std::endl;
    }





    return 0;
}
