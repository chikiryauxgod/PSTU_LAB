#include "Fraction.h"

Fraction::Fraction(void) :Pair() {
	integer = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fraction::~Fraction(void) {
	std::cout << "Destructor called" << std::endl;
}

Fraction::Fraction(int whole, int numerator, int denominator) : Pair(numerator, denominator), integer(whole) {
	integer = whole;
	std::cout << "Parametrized constructor called" << std::endl;
}

Fraction::Fraction(const Fraction& F) {
	first = F.first;
	second = F.second;
	integer = F.integer;
	std::cout << "Copy constructor called" << std::endl;
}

void Fraction::setInteger(int I) {
	integer = I;
}

Fraction& Fraction::operator=(const Fraction& f) {
	std::cout << "Assignment operator called" << std::endl;
	if (this != &f) {
		first = f.first;
		second = f.second;
		integer = f.integer;
	}
	return *this;
}

bool Fraction::operator==(const Fraction& other) const {
	return (integer == other.integer) && (Pair::operator==(other));
}

bool Fraction::operator<(const Fraction& other) const {
	if (integer < other.integer) {
		return true;
	}
	else if (integer == other.integer) {
		return Pair::operator<(other);
	}
	return false;
}

bool Fraction::operator<=(const Fraction& other) const {
	return (*this < other) || (*this == other);
}

bool Fraction::operator>(const Fraction& other) const {
	return !(*this <= other);
}

bool Fraction::operator>=(const Fraction& other) const {
	return !(*this < other);
}

bool Fraction::operator!=(const Fraction& other) const {
	return !(*this == other);
}

std::istream& operator >> (std::istream& is, Fraction& obj) {
	std::cout << "Integer part: ";
	is >> obj.integer;
	std::cout << "Numerator: ";
	is >> obj.first;
	std::cout << "Denominator: ";
	is >> obj.second;
	return is;
}


std::ostream& operator << (std::ostream& os, const Fraction& f) {
	os << "\n Integer part: " << f.integer;
	os << "\n Numerator: " << f.first;
	os << "\n Denominator: " << f.second;
	os << "\n";
	return os;
}

