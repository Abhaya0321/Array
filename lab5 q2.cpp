#include<iostream>
using namespace std;

float maxElement(float array[], int length) {
	float max=array[0];
	for (int i=0; i<length; ++i) {
		if (array[i] > max) {
			max = array[i];
		}
	}

	return max;
}

float minElement(float array[], int length) {
	float min=array[0];
	for (int i=0; i<length; ++i) {
		if (array[i] < min) {
			min = array[i];
		}
	}

	return min;
}

float mean(float array[], int length) {
	float total=0;
	for (int i=0; i < length; ++i) {
		total += array[i];
	}

	return total/length;
}

float median(float array[], int length) {
	bool flag=true;
	float temp;
	while(flag) {
		flag = false;
		for (int i=0; i < length; ++i) {
			if (array[i+1] > array[i]) {
				temp = array[i+1];
				array[i+1] = array[i];
				array[i] = temp;
				flag = true;
			}
		}
	}

	if (length%2 != 0) {
		return array[(length-1)/2];
	} else {
		float med = 0;
		med = (array[length/2] + array[length/2 - 1])/2;
		return med;
	}
}

int freqElement(float array[], int length, float element) {
	int counter=0;
	for (int i=0; i<length; ++i) {
		if (array[i] == element) {
			++counter;
		}
	}

	return counter;
}

float mode(float array[], int length) {
	/* Does not work if multiple numbers
	 * have the highest frequency */

	float mod=array[0];
	int modFreq=0;
	for (int i=0; i < length; ++i) {
		if (freqElement(array, length, array[i]) > modFreq) {
			modFreq = freqElement(array, length, array[i]);
			mod = array[i];
		}
	}

	return mod;
}

int main() {
	int n;
	cout << "How many numbers do you want to enter? ";
	cin >> n;

	const int length = n;

	float array[length];
	for (int i=0; i < length; ++i) {
		cout << "Enter number " << i+1 << ": ";
		cin >> array[i];
	}

	cout << "Largest Element: " << maxElement(array, length) << endl;
	cout << "Smallest Element: " << minElement(array, length) << endl;
	cout << "Mean: " << mean(array, length) << endl;
	cout << "Median: " << median(array, length) << endl;
	cout << "Mode: " << mode(array, length) << endl;

	return 0;
}
