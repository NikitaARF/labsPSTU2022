#include <iostream>
#include "pair.h"
using namespace std;

Pair::Pair() {
	int first = 0;
	int second = 0;
	bool anotherOutput = false;
}

Pair::Pair(int f, int s) {
	int first = f;
	int second = s;
}

Pair::Pair(const Pair& tmp) {
	int first = tmp.first;
	int second = tmp.second;
}

Pair::~Pair() {}

int Pair::get_first() {
	return first;
}

int Pair::get_second() {
	return second;
}

void Pair::set_first(int f) {
	first = f;
}

void Pair::set_second(int s) {
	second = s;
}

istream& operator>>(istream& is, Pair& tmp) {
	cout << "first? :"; is >> tmp.first;
	cout << "second? :"; is >> tmp.second;
	return is;
}

ostream& operator<<(ostream& os, const Pair& tmp) {
	if (tmp.anotherOutput == true) {
		os << tmp.first << "; " << tmp.second;
	}
	else {
		os << tmp.first << "," << tmp.second;
	}
	return os;
}

Pair& Pair::operator=(const Pair& tmp) {
	if (&tmp == this) {
		return *this;
	}
	first = tmp.first;
	second = tmp.second;
	return *this;
}

Pair Pair::operator-(const Pair& tmp) {
	Pair result;
	result.first = first - tmp.first;
	result.second = second - tmp.second;
	result.anotherOutput = true;
	return result;
}

Pair Pair::operator+(const Pair& tmp) {
	Pair result;
	result.first = first * tmp.first;
	result.second = second * tmp.second;
	return result;
}

Pair Pair::operator*(const Pair& tmp) {
	Pair result;
	result.first = first * tmp.first;
	result.second = second * tmp.second;
	return result;
}

