#include<iostream>
using namespace std;

float klarge(float array[], int length, int k) {
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

	for (int i=0; i<length; ++i) {
		cout << array[i] << endl;
	}

	return array[k-1];
}

float ksmall(float array[], int length, int k) {
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

	return array[length-k];
}

int main() {
	float foo[10] = {1, 5, 6, 3, 2, 1, 5, 1, 4, 6};		// array to test the code

	cout << klarge(foo, 10, 5) << endl;
	cout << ksmall (foo, 10, 5) << endl;

	return 0;
}
