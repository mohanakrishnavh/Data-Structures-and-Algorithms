#include <iostream>

using namespace std;

int main() {
	int a = 10;
	int *p = &a;
	
	// Pointer Arithmetic
	cout << p << endl; // p is 2002
	cout << p + 1 << endl; // p+1 will be 2006 (because p is pointer to integer)
	cout << "Size of integer: " << sizeof(int) << endl;
	cout << "Value at address p : " << *p << endl;
	cout << "Value at adress (p+1) : " << *(p + 1) << endl;

	return 0;
}