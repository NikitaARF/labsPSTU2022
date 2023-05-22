#include <iostream>
#include "vector.h"

Vector::Vector(void)
{
	beg = 0;
	size = 0;
	current = 0;
}

Vector::Vector(int n)
{
	beg = new Abstract * [n];
	current = 0;
	size = n;
}

Vector::~Vector(void)
{
	if (beg != 0)
	{
		delete[] beg;
	}
	beg = 0;
}

void Vector::Add(Abstract *tmp)
{
	if (current < size)
	{
		beg[current] = tmp;
		current++;
	}
}

std::ostream& operator<<(std::ostream& os, const Vector& vec)
{
	if (vec.size == 0)
	{
		os << "Empty" << std::endl;
	}
	Abstract **tmp = vec.beg;
	for (int i = 0; i < vec.current; i++)
	{
		(*tmp)->Show();
		tmp++;
	}
	return os;
}

