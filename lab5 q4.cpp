#include<iostream>
using namespace std;

const int N = 50;

int length(float arr[]) {
	int i=0;
	while (arr[i] != '\0') {
		++i;
	}
	return i;
}

void print(float arr[]) {
	for (int i=0; i<length(arr); ++i) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void combine(float array1[], float array2[], float (&combined)[N]) {
	for (int i=0; i<N; ++i) {
		combined[i] = '\0';
	}

	for (int i=0; i < length(array1)+length(array2); ++i) {
		if (i < length(array1)) {
			combined[i] = array1[i];
		} else {
			combined[i] = array2[i-length(array1)];
		}
	}
}

float maxElement(float arr1[], float arr2[]) {
	float combinedArray[N];
	combine(arr1, arr2, combinedArray);

	float max=combinedArray[0];
	for (int i=0; i<length(combinedArray); ++i) {
		if (combinedArray[i] > max) {
			max = combinedArray[i];
		}
	}

	return max;
}

float minElement(float arr1[], float arr2[]) {
	float combinedArray[N];
	combine(arr1, arr2, combinedArray);

	float min=combinedArray[0];
	for (int i=0; i<length(combinedArray); ++i) {
		if (combinedArray[i] < min) {
			min = combinedArray[i];
		}
	}

	return min;
}

int main() {
	float arr1[N] = {3, 5, 6, 7, 1};
	float arr2[N] = {10, 40, 20, 30};

	float combinedArray[N];
	combine(arr1, arr2, combinedArray);

	cout << "Combined Array: ";
	print(combinedArray);

	cout << "Minimum element: " << minElement(arr1, arr2) << endl;
	cout << "Maximum element: " << maxElement(arr1, arr2) << endl;

	return 0;
}
