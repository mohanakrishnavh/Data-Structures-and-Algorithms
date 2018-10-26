#include <iostream>

using namespace std;

int SumOfElements(int *A) // or (int A[]) 
{
	int sum = 0;
	int size = sizeof(A) / sizeof(A[0]);
	cout << "SOE - Size of A : " << sizeof(A) << ", Size of A[0] : " << sizeof(A[0]) << endl;

	for (int i = 0; i < size; i++) {
		sum += A[i];
	}
	return sum;
}

//Correct Implementation
int SumOfElements2(int A[], int size) {
	int sum = 0;

	for (int i = 0; i < size; i++) {
		sum += A[i];
	}
	return sum;
}

void Double(int *A, int size) // or (int A[]) 
{	
	cout << "\nDoubling the Values of Array A:\n";
	for (int i = 0; i < size; i++) {
		A[i] = 2 * A[i];
		cout << A[i] << endl;
	}
}


int main() {
	int A[] = { 1, 2, 3, 4, 5 };
	
	int total = SumOfElements(A);
	cout << "Sum of elements: " << total << endl;
	cout << "MAIN - Size of A : " << sizeof(A) << ", Size of A[0] : " << sizeof(A[0]) << endl;

	int size = sizeof(A) / sizeof(A[0]);
	total = SumOfElements2(A, size); // A can be used for &A[0]
	cout << "Sum of elements(passing size): " << total << endl;
	
	Double(A, size);
	return 0;
}