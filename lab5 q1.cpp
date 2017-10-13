#include<iostream>
using namespace std;

float sumArray(float array[], int len) {
	float sum=0;
	for (int i=0; i < len; ++i) {
		sum += array[i];
	}

	return sum;
}

int main() {
	int n;
	cout << "How many numbers do you want to add? ";
	cin >> n;

	const int length = n;
	float array[length];
	
	for (int i=0; i < length; ++i) {
		cout << "Enter number " << i+1 << ": ";
		cin >> array[i];
	}

	cout << "Sum of numbers: " << sumArray(array,length) << endl;

	return 0;
}
