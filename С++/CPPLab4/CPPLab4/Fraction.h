#pragma once
#include "Pair.h"

class Fraction : public Pair
{
public: 
	Fraction(void);
	~Fraction(void);
	Fraction(int i, int f, int s);
	Fraction(const Fraction&);

	int getInteger() { return integer;}
	void setInteger(int);
	Fraction& operator= (const Fraction&);
	bool operator== (const Fraction& other) const;
	bool operator< (const Fraction& other) const;
	bool operator<= (const Fraction& other) const;
	bool operator> (const Fraction& other) const;
	bool operator>= (const Fraction& other) const;
	bool operator!= (const Fraction& other) const;

	friend std::ostream& operator<< (std::ostream& os, const Fraction& obj);
	friend std::istream& operator>> (std::istream& is, Fraction& obj);

protected:
	int integer;
};

