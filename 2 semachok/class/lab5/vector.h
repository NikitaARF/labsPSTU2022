#pragma once
#include <iostream>
#include "abstract.h"


class Vector {
	Abstract** beg;
	int size;
	int current;
public:
	Vector(void);
	Vector(int);
	~Vector(void);
	void Add(Abstract *tmp);
	friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
};