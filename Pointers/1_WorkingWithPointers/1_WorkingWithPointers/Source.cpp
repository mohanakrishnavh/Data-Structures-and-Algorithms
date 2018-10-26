#include <iostream>

using namespace std;

int main() {
	int a = 10;
	int *p;
	p = &a; // &a = address of a
	cout << "Address of a: "<< p <<  endl;
	cout << "Value stored in address " << p <<" : "<< *p << endl;
	cout << "Address of a: " << &a << endl;

	*p = 12; //dereferencing
	cout << "a = " << a << endl;

	int b = 20;
	*p = b; //We are only modifying the value p has
	cout << "a = " << a << endl;

	p = &b;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "Addres of b = " << &b << endl;
	cout << "Adress of b (after pointing p from a to b) = " << p << endl;
	int *q = &a;
	cout << "Adress of a = " << q << endl;

	return 0;
}