#pragma once
#include <iostream>
#include "abstract.h"

class Pair : public Abstract {
protected:
	int first;
	int second;
	bool anotherOutput;
public:
	Pair(void);
	Pair(int, int);
	Pair(const Pair&);
	~Pair(void);
	int getFirst(void);
	void setFirst(int f);
	int getSecond(void);
	void setSecond(int s);
	friend std::istream& operator>>(std::istream& is, Pair& tmp);
	friend std::ostream& operator<<(std::ostream& os, const Pair& tmp);
	Pair& operator=(const Pair& tmp);
	Pair operator-(const Pair& tmp);
	Pair operator+(const Pair& tmp);
	Pair operator*(const Pair& tmp);
	void Show();
};