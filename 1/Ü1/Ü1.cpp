#include <iostream>
#include <limits>
#include<climits>

using namespace std;
int main()
{

    //Aufgabe 1
    cout << "Hallo Welt\n\n!!!\n" << endl;

    //Aufgabe 2
    double ergebnis;
    double größe;
    double körpergewicht;

    cout << "Geben sie ihre Groesse ein:\n";
    cin >> größe;
    cout << "Geben sie ihre Keorpergewicht ein:\n";
    cin >> körpergewicht;

    ergebnis = größe / körpergewicht;

    cout << "Ihr BMI ist:" << ergebnis << endl << endl;

    // Aufgabe 3
    cout << "Anzahl Bits Info" << endl;
    cout << "==================================" << endl;

    cout << "char:" << sizeof(char) << "Bits" << endl;
    cout << "int:" << sizeof(int) << "Bits" << endl;
    cout << "double:" << sizeof(double) << "Bits" << endl;
    cout << "long:" << sizeof(long) << "Bits" << endl;
    cout << "short:" << sizeof(short) << "Bits" << endl;
    cout << "unsigned int:" << sizeof(unsigned int) << "Bits" << endl;
    cout << "unsigned short:" << sizeof(unsigned short) << "Bits" << endl;
    cout << "unsigned long:" << sizeof(unsigned long) << "Bits" << endl;
    cout << "float:" << sizeof(float) << "Bits" << endl;
    cout << "bool:" << sizeof(bool) << "Bits" << endl;

    cout << "Minimal und Maximal-Wert" << endl;
    cout << "==================================" << endl;
    cout << "Der Maximale Wert fuer int: " << numeric_limits<int>::max() << '\n';
    cout << "Der Minimale Wert fuer int: " << numeric_limits<int>::min() << '\n' << endl;

    cout << "Der Maximale Wert fuer double: " << numeric_limits<double>::max() << '\n';
    cout << "Der Minimale Wert fuer double: " << numeric_limits<double>::min() << '\n' << endl;

    cout << "Der Maximale Wert fuer long: " << numeric_limits<long>::max() << '\n';
    cout << "Der Minimale Wert fuer long: " << numeric_limits<long>::min() << '\n' << endl;

    cout << "Der Maximale Wert fuer short: " << numeric_limits<short>::max() << '\n';
    cout << "Der Minimale Wert fuer short: " << numeric_limits<short>::min() << '\n' << endl;

    cout << "Der Maximale Wert fuer unsigned int: " << numeric_limits<unsigned int>::max() << '\n';
    cout << "Der Minimale Wert fuer unsigned int: " << numeric_limits<unsigned int>::min() << '\n' << endl;

    cout << "Der Maximale Wert fuer unsigned short: " << numeric_limits<unsigned short>::max() << '\n';
    cout << "Der Minimale Wert fuer unsigned short: " << numeric_limits<unsigned short>::min() << '\n' << endl;

    cout << "Der Maximale Wert fuer unsigned long: " << numeric_limits<unsigned long>::max() << '\n';
    cout << "Der Minimale Wert fuer unsigned long: " << numeric_limits<unsigned long>::min() << '\n' << endl;

    cout << "Der Maximale Wert fuer float: " << numeric_limits<float>::max() << '\n';
    cout << "Der Minimale Wert fuer float: " << numeric_limits<float>::min() << '\n' << endl;

    cout << "Der Maximale Wert fuer long double: " << numeric_limits<long double>::max() << '\n';
    cout << "Der Minimale Wert fuer long double: " << numeric_limits<long double>::min() << '\n' << endl;

    cout << "Der Maximale Wert fuer bool: " << numeric_limits<bool>::max() << '\n';
    cout << "Der Minimale Wert fuer bool: " << numeric_limits<bool>::min() << '\n' << endl;







    return 0;
}