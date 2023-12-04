#include <iostream>
using namespace std;

class Time {
private:
	int min, sec;
public:
	Time() { min = 0; sec = 0; }
	Time(int m, int s) { min = m; sec = s; }
	Time(const Time& t) { min = t.min; sec = t.sec; }
	~Time() {};
	int get_min() { return min; }
	int get_sec() { return sec; }
	void set_min(int m) { min = m; }
	void set_sec(int s) { sec = s; }

	Time& operator=(const Time&);
	Time& operator++();
	Time operator++(int);
	Time operator+(const Time&);
	friend istream& operator>> (istream& in, Time& t);
	friend ostream& operator<< (ostream& out, const Time& t);

};