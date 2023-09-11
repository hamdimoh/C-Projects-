#pragma once
#include <iostream>
#include<cmath>
#include "Punkt.h"


class Rechteck
{
private:
	Punkt P1, P2;
public:
	Rechteck(Punkt A_, Punkt B_) { P1 = A_;	P2 = B_; };
	double Flaeche();
	double Umfang();
	unsigned int Umfang(bool is_Inches, double cmInInches = 0.3937008);
};
