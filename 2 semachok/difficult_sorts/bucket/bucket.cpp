#include <iostream>
#include <ctime>

using namespace std;


void bucketSort(int arr[], int n) {
	const int NUM_BUCKETS = 10; // number of buckets
	const int ARRAY_SIZE = 10; // size of the array to be sorted
	// create an array of buckets
	int buckets[NUM_BUCKETS][ARRAY_SIZE];

	// initialize each bucket to be empty
	int bucketSizes[NUM_BUCKETS] = { 0 };

	// distribute the elements into the buckets
	for (int i = 0; i < n; i++) {
		int bucketIndex = arr[i] / NUM_BUCKETS;
		buckets[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
		bucketSizes[bucketIndex]++;
	}

	// sort each bucket using insertion sort
	for (int i = 0; i < NUM_BUCKETS; i++) {
		for (int j = 1; j < bucketSizes[i]; j++) {
			int temp = buckets[i][j];
			int k = j - 1;
			while (k >= 0 && buckets[i][k] > temp) {
				buckets[i][k + 1] = buckets[i][k];
				k--;
			}
			buckets[i][k + 1] = temp;
		}
	}

	// combine the sorted buckets into a single array
	int index = 0;
	for (int i = 0; i < NUM_BUCKETS; i++) {
		for (int j = 0; j < bucketSizes[i]; j++) {
			arr[index++] = buckets[i][j];
		}
	}
}

int main() {
	int size;
	cin >> size;
	int* arr = new int[size];

	// generate random array
	srand(time(0));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 101;
	}
	cout << endl;

	// print unsorted array
	cout << "Unsorted Array: " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	// sort the array
	bucketSort(arr, size);

	// print sorted array
	cout << "Sorted Array: " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}