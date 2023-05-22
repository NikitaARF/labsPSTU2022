#pragma once
#include <iostream>
#include <string>
using namespace std;
class PC {
	string CPU;
	int RAM_volume;
	int HD_volume;
public:
	PC();
	PC(string cpu, int ram_volume, int hd_volume);
	PC(PC& temp);
	~PC();
	void show();
	string get_CPU();
	int get_RAM_volume();
	int get_HD_volume();
	void set_CPU(string cpu);
	void set_RAM_volume(int ram_volume);
	void set_HD_volume(int hd_volume);
};