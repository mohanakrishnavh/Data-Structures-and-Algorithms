#include <iostream>

using namespace std;

int main() {
	int a = 1025;
	int *p = &a;
	cout << "Size of integer: " << sizeof(int) << endl;
	cout << "Address = " << p << " Value = " << *p << endl;
	cout << "Address = " << p+1 << " Value = " << *(p+1) << endl;

	char *p0;
	p0 = (char*)p; //typecasting
	cout << "Size of char: " << sizeof(char) << endl;
	cout << "Address = " << p0 << " Value = " << *p0 << endl; //*p0 = 1 (retains the value)
	cout << "Address = " << p0+1 << " Value = " << *(p0+1) << endl;
	// 1025 = 00000000 00000000 00000100 00000001

	void *p1; // Generic Pointer 
	p1 = p;
	//cout << "Address = " << p1 << " Value = " << *p1 << endl; // we can't dereference the value - since we don't know the type
	cout << "Address = " << p1 << endl;
	// Pointer Arthimetic will also throw error

	return 0;
}