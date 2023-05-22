#include <iostream>
#include <string>
#include "PC.h"
using namespace std;

PC::PC() {
	CPU = "";
	RAM_volume = 0;
	HD_volume = 0;
}

PC::PC(string cpu, int ram_volume, int hd_volume) {
	CPU = cpu;
	RAM_volume = ram_volume;
	HD_volume = hd_volume;
}

PC::PC(PC& temp) {
	CPU = temp.CPU;
	RAM_volume = temp.RAM_volume;
	HD_volume = temp.HD_volume;
}

PC::~PC() {
	cout << "Decoding" << endl;
}

void PC::show() {
	cout << "the name of CPU: " << CPU << "\n" << "RAM_volume: " << RAM_volume << "\n" << "HD_volume(in GBs): " << HD_volume << "\n";

}

string PC::get_CPU() {
	return CPU;
}

int PC::get_RAM_volume() {
	return RAM_volume;
}

int PC::get_HD_volume() {
	return HD_volume;
}

void PC::set_CPU(string cpu) {
	CPU = cpu;
}

void PC::set_RAM_volume(int ram_volume) {
	RAM_volume = ram_volume;
}

void PC::set_HD_volume(int hd_volume) {
	HD_volume = hd_volume;
}