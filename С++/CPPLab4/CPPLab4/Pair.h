#pragma once
#include <iostream>

class Pair {
public:
    Pair();
    Pair(int f, int s);
    Pair(const Pair& other); 
    ~Pair();

    int getFirst() const;
    int getSecond() const;
    void setFirst(int f);
    void setSecond(int s);
    Pair& operator=(const Pair& other);
    bool compareFields(const Pair& other) const;
    bool comparePairs(const Pair& other) const;
    bool operator== (const Pair& other) const;
    bool operator< (const Pair& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Pair& obj);
    friend std::istream& operator>>(std::istream& is, Pair& obj);

protected: 
    int first;
    int second;

};

