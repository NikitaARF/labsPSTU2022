#include <iostream>
#include <string>
#include "PC.h"
using namespace std;

int main() {
	string cpu;
	int ram_volume;
	int hd_volume;
	cout << "enter name of CPU: "; cin >> cpu;
	cout << "enter the volume of RAM: "; cin >> ram_volume;
	cout << "enter the volume of HD: "; cin >> hd_volume;
	cout << endl;
	PC pc1;
	pc1.show();
	cout << endl;
	PC pc2(cpu, ram_volume, hd_volume);
	pc2.show();
	cout << endl;
	PC pc3(cpu, ram_volume, hd_volume);
	pc3.show();
	cout << endl;
	pc1.set_CPU("intel");
	pc1.set_RAM_volume(32);
	pc1.set_HD_volume(1000);
	pc1.show();
	cout << endl;
	return 0;
}