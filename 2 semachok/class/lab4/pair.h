#pragma once
#include <iostream>
using namespace std;

class Pair {
public:
	int first;
	int second;
	bool anotherOutput;
	Pair();
	Pair(int f, int s);
	Pair(const Pair& tmp);
	~Pair();
	int get_first();
	int get_second();
	void set_first(int f);
	void set_second(int s);
	friend istream& operator>>(istream& is, Pair& tmp);
	friend ostream& operator<<(ostream& os, const Pair& tmp);
	Pair& operator=(const Pair& tmp);
	Pair operator-(const Pair& tmp);
	Pair operator+(const Pair& tmp);
	Pair operator*(const Pair& tmp);
};
