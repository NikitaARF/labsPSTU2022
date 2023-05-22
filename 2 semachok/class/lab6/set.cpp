#include <iostream>
#include "set.h"

Set::Set() {
	size = 0;
	data = nullptr;
}

Set::Set(int s) {
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = 0;
	}
	beg.elem = &data[0];
	end.elem = &data[size];
}

Set::Set(const Set& temp)
{
	size = temp.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = temp.data[i];
	}
	beg = temp.beg;
	end = temp.end;
}

Set::~Set() {
	delete[]data;
	data = 0;
}

Set& Set::operator=(const Set& temp)
{
	if (this == &temp) { return *this; }
	size = temp.size;
	if (data != 0) { delete[] data; }
	data = new int[size];
	for (int i = 0; i < size; i++) { data[i] = temp.data[i]; }
	beg = temp.beg;
	end = temp.end;
	return *this;
}

int& Set::operator[](int index) {
	if (index < size) return data[index];
	else { std::cout << "BG" << std::endl; }
}

void Set::add(int el) {
    for (int i = 0; i < size; i++) {
        if (data[i] == el) {
            return;
        }
    }
    int* newData = new int[size + 1];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    newData[size] = el;
    delete[] data;
    data = newData;
    size++;
}

Set Set::operator*(const Set& tmp) {
    Set result;
    for (int i = 0; i < size; i++) {
        result.add(data[i]);
    }
    for (int i = 0; i < tmp.size; i++) {
        bool in_result = false;
        for (int j = 0; j < result.size; j++) {
            if (tmp.data[i] == result.data[j]) {
                in_result = true;
                break;
            }
        }
        if (!in_result) {
            result.add(tmp.data[i]);
        }
    }
    return result;
}

int Set::operator ()() {
	return size;
}

std::istream& operator>>(std::istream& is, Set& temp) {
	for (int i = 0; i < temp.size; i++) { is >> temp.data[i]; }
	return is;
}

std::ostream& operator<<(std::ostream& os, Set& temp) {
	for (int i = 0; i < temp.size; i++) { os << temp.data[i] << " "; }
	return os;
}
