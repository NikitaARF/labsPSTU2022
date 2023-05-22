#pragma once
#include <iostream>
#include "pair.h"

class Rational : public Pair {
public:
	int numerator;
	int denominator;
	bool anotherOutput;
	Rational();
	Rational(int n, int d);
	Rational(const Rational& tmp);
	~Rational();
	int get_numerator();
	int get_denominator();
	void set_numerator(int n);
	void set_denominator(int d);
	friend istream& operator>>(istream& is, Rational& tmp);
	friend ostream& operator<<(ostream& os, const Rational& tmp);
	Rational& operator=(const Rational& tmp);
	Rational operator-(const Rational& tmp);
	Rational operator+(const Rational& tmp);
	Rational operator*(const Rational& tmp);
};