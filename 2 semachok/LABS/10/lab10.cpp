#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size, k;
	cout << "Enter size of array: ";
	cin >> size;
	string* arr = new string[size];
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "enter K words need to delete from string: ";
	cin >> k;
	string* arr2 = new string[size - k];

	for (int i = 0; i < size - k; i++) {
		if (i <= k) {
			arr2[i] = arr[i + k];
		}
		cout << arr2[i] << " ";
	}
	delete[] arr;
	delete[] arr2;
}