#pragma once
#include <iostream>
#include<cmath>
using namespace std;
class Punkt
{
private:
	double x, y;
public:
	Punkt(double X = 0, double Y = 0) { x = X;	y = Y; };
	void set(double X, double Y);
	double getX();
	double getY();
};

