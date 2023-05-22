#include <iostream>
#include "rational.h"
using namespace std;

Rational::Rational() {
	int numerator = 0;
	int denominator = 0;
	bool anotherOutput = false;
}

Rational::Rational(int n, int d) {
	int numerator = n;
	int denominator = d;;
}

Rational::Rational(const Rational& tmp) {
	int numerator = tmp.numerator;
	int denominator = tmp.denominator;
}

Rational::~Rational() {}

int Rational::get_numerator() {
	return numerator;
}

int Rational::get_denominator() {
	return denominator;
}

void Rational::set_numerator(int n) {
	numerator = n;
}

void Rational::set_denominator(int d) {
	denominator = d;
}

istream& operator>>(istream& is, Rational& tmp) {
	cout << "numerator? :"; is >> tmp.numerator;
	cout << "denominator? :"; is >> tmp.denominator;
	return is;
}

ostream& operator<<(ostream& os, const Rational& tmp) {
	if (tmp.anotherOutput == true) {
		os << tmp.numerator << ", " << tmp.denominator;
	}
	else {
		os << tmp.numerator << "," << tmp.denominator;
	}
	return os;
}

Rational& Rational::operator=(const Rational& tmp) {
	if (&tmp == this) {
		return *this;
	}
	numerator = tmp.numerator;
	denominator = tmp.denominator;
	return *this;
}

Rational Rational::operator-(const Rational& tmp) {
	Rational result;
	result.numerator = numerator - tmp.numerator;
	result.denominator = denominator - tmp.denominator;
	result.anotherOutput = true;
	return result;
}

Rational Rational::operator+(const Rational& tmp) {
	Rational result;
	result.numerator = numerator * tmp.denominator + tmp.numerator * denominator;
	result.denominator = denominator * tmp.denominator;
	return result;
}



Rational Rational::operator*(const Rational& tmp) {
	Rational result;
	result.numerator = numerator * tmp.numerator;
	result.denominator = denominator * tmp.denominator;
	return result;
}