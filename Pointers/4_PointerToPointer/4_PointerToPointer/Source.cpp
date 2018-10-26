#include <iostream>

using namespace std;

int main() {
	int x = 5;
	int *p = &x;
	*p = 6;
	int **q = &p;
	int ***r = &q;

	cout << "Value of x : " << x << endl;
	cout << "Adress of x (which is p): " << p << endl;
	cout << "Adress of p (which is q): " << q << endl;
	cout << "Value of q (which is r): " << r << endl;

	cout << "Value using p: " << *p << endl;
	cout << "Value using q: " << *(*q) << endl;
	cout << "Value using r: " << *(*(*r)) << endl;

	//Modifying the value
	***r = 100; //chain of dereferencing
	cout << "Value of x: " << x << endl;
	return 0;
}