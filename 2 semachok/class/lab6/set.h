#pragma once
#include <iostream>

class Iterator
{
	friend class Set;
public:
	Iterator() { elem = 0; }
	Iterator(const Iterator& it) { elem = it.elem; }
	bool operator==(const Iterator& it) { return elem == it.elem; }
	bool operator!=(const Iterator& it) { return elem != it.elem; }
	void operator++() { ++elem; }
	void operator--() { --elem; }
	int& operator*() const { return *elem; }
private:
	int* elem;
};

class  Set{
public:
	Set();
	Set(int);
	Set(const Set&);
	~Set();
	Set& operator=(const Set&);
	int& operator[](int index);
	Set operator*(const Set&);
	void add(int);
	void remove(int);
	int operator()();
	friend std::istream& operator>>(std::istream& is, Set&);
	friend std::ostream& operator<<(std::ostream& os, Set&);
	Iterator first() { return beg; }
	Iterator last() { return end; }
private:
	int size;
	int* data;
	Iterator beg;
	Iterator end;
};