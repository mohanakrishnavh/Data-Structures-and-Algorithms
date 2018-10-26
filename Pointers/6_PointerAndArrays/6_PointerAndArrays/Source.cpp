#include <iostream>

using namespace std;

int main() {
	int A[] = { 2, 4, 5, 8, 1 };
	cout << "Adress of A: "<< A << endl;
	cout << "Adress of A: " << &A[0] << endl;
	cout << "Value of A[0]: " << A[0] << endl;
	cout << "Value of A[0]: " << *A << endl;
	cout << "\n\n";

	for (int i = 0; i < 5; i++) {
		cout << "Address of A[" << i << "] : " << &A[i] << endl;
		cout << "Address of A[" << i << "] : " << A+i << endl;
		cout << "Value of A[" << i << "] : " << A[i] << endl;
		cout << "Value of A[" << i << "] : " << *(A + i) << endl;
		cout << endl;
	}

	return 0;
}