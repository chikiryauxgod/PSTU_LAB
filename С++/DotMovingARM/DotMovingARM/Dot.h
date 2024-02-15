#pragma once
#include <iostream>
using namespace std;

class Dot
{
private:
		double x;
		double y;
	
public:
	Dot() { x = 0; y = 0; }
	Dot(double x, double y)
	{
		x = x; y = y;
	}
	Dot(const Dot& t) { x = t.x; y = t.y; }
	~Dot() {};
	double get_x() { return x; }
	double get_y() { return y; }
 
};