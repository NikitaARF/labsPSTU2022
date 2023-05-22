#include <iostream>
#include "pair.h"

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

int Pair::getFirst() {
	return first;
}

int Pair::getSecond() {
	return second;
}

void Pair::setFirst(int f) {
	first = f;
}

void Pair::setSecond(int s) {
	second = s;
}

std::istream& operator>>(std::istream& is, Pair& tmp) {
	std::cout << "first? :"; is >> tmp.first;
	std::cout << "second? :"; is >> tmp.second;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Pair& tmp) {
	os << tmp.first << "," << tmp.second;
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
	return result;
}

void Pair::Show()
{
	std::cout << "first: " << first << "\n" << "second: " << second;
}