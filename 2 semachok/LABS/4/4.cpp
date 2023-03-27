#include <iostream>
#include <ctime>

using namespace std;

int main() {
	// random array
	srand(time(0));
	int size;
	cout << "enter size: ";
	cin >> size;

	int* data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = 1 + rand() % 1001;
		cout << data[i] << " ";
	}
	cout << endl;


	// shift to left
	int shift, s = 0;

	cout << "enter shift: ";
	cin >> shift;
	cout << "shifted version: ";
	for (s; s < size; s++)
	{
		cout << data[shift] << " ";
		++shift;
		if (shift > size - 1)
		{
			shift -= size;
		}
	}
	cout << endl;


	// sort ascending
	for (int i = 0; i < size - 1; i++)
	{
		int min = i;
		for (int j = i; j < 10; j++)
		{
			if (data[j] < data[min])
			{
				min = j;
			}
		}
		swap(data[i], data[min]);
	}
	cout << "sorted array is: ";
	for (int i = 0; i < 10; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;


	// removing elements with even numbers
	cout << "removed version: ";
	int x = 0;
	for (int i = 0; i < size; i++)
	{
		data[x] = data[i];
		if (data[i] % 2 != 0) {
			x++;
			cout << data[i] << " ";
		}
	}
}