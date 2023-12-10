#include "Pair.h"

Pair::Pair()  {
    first = 0;
    second = 0;
    std::cout << "Default constructor called" << std::endl;
}

Pair::Pair(int f, int s) {
    first = f;
    second = s;
    std::cout << "Parametrized constructor called" << std::endl;
}

Pair::Pair(const Pair& other)  {
    first = other.first;
    second = other.second;
    std::cout << "Copy constructor called" << std::endl;
}

Pair::~Pair() {
    std::cout << "Destructor called" << std::endl;
}

int Pair::getFirst() const {
    return first;
}

int Pair::getSecond() const {
    return second;
}

void Pair::setFirst(int f) {
    first = f;
}

void Pair::setSecond(int s) {
    second = s;
}

bool Pair::compareFields(const Pair& other) const {
    return (first == other.first) && (second == other.second);
}

bool Pair::comparePairs(const Pair& other) const {
    return (first > other.first) || ((first == other.first) && (second > other.second));
}

bool Pair::operator==(const Pair& other) const {
    return compareFields(other);
}

bool Pair::operator<(const Pair& other) const {
    return comparePairs(other);
}

Pair& Pair::operator=(const Pair& other) {
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other) {
        first = other.first;
        second = other.second;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Pair& obj) {
    os << "Pair: (" << obj.first << ", " << obj.second << ")" << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, Pair& obj) {
    std::cout << "Enter first number: ";
    is >> obj.first;
    std::cout << "Enter second number: ";
    is >> obj.second;
    return is;
}
