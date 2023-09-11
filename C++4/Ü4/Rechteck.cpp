#include "Rechteck.h"
#include <iostream>
#include<cmath>
#include "Punkt.h"

double Rechteck::Flaeche() {
	double width, length;
	length = sqrt(pow(P2.getX() - P1.getX(), 2));
	width = sqrt(pow(P2.getY() - P1.getY(), 2));
	return length * width;
};
double Rechteck::Umfang() {
	double width, length;
	length = sqrt(pow(P2.getX() - P1.getX(), 2));
	width = sqrt(pow(P2.getY() - P1.getY(), 2));
	return 2 * width + 2 * length;
};
unsigned int Rechteck::Umfang(bool is_Inches, double cmInInches) {
	double width, length;
	length = sqrt(pow(P2.getX() - P1.getX(), 2)) * cmInInches;
	width = sqrt(pow(P2.getY() - P1.getY(), 2)) * cmInInches;
	return (unsigned int)(2 * width + 2 * length);
};
