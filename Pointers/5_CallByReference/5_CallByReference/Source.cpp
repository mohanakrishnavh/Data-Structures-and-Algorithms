#include <iostream>

using namespace std;


// Call By Value
// Called Function
void increment(int a) //a - formal argument
{
	a = a + 1; // 
	cout << "Adress of variable a in increment() = " << &a << endl;
}


//Call By Reference
void increment2(int *p) {
	*p = (*p) + 1;
}

// Calling Function
int main() 
{
	int a;
	a = 10;
	increment(a); // a - actual argument
	cout << "Adress of variable a in main() = " << &a << endl;
	cout << "Value of a : " << a;
	increment2(&a);
	cout << "Value of a(after increment2): " << a;

	return 0;
}