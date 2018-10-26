#include <iostream>
#include <utility>
#include <string>

using namespace std;

int main() {
	pair <int, char> PAIR1;
	PAIR1.first = 100;
	PAIR1.second = 'G';
	cout << "PAIR1 : " << PAIR1.first << " ";
	cout << PAIR1.second << endl;

	//Initlialization
	pair <string, double> PAIR2 ("Microsoft", 30.0);
	cout << "PAIR2 : " << PAIR2.first << " ";
	cout << PAIR2.second << endl;

	//Default Values
	pair <int, double> PAIR3;
	cout << "PAIR3 : " << PAIR3.first << " ";
	cout << PAIR3.second << endl;

	pair <string, char> PAIR4;
	cout << "PAIR4 : " << PAIR4.first << " ";
	cout << PAIR4.second << endl;
	cout << "Concatenating the PAIR4 : " << PAIR4.first + PAIR4.second <<"."<<endl;

	//Member Function
	pair <int, char> PAIR5;
	pair <string, double> PAIR6 ("Emkae", 1.23);
	pair <string, double> PAIR7;

	PAIR5.first = 100;
	PAIR5.second = 'F';
	PAIR7 = make_pair("Espee", 4.56);

	cout << "PAIR5 : " << PAIR5.first << " ";
	cout << PAIR5.second << endl;
	cout << "PAIR6 : " << PAIR6.first << " ";
	cout << PAIR6.second << endl;
	cout << "PAIR7 : " << PAIR7.first << " ";
	cout << PAIR7.second << endl;
	
	//Operators
	pair <int, int> PAIR8 = make_pair(1, 12);
	pair <int, int> PAIR9 = make_pair(9, 12);
	cout << (PAIR8 == PAIR9) << endl;
	cout << (PAIR8 != PAIR9) << endl;
	cout << (PAIR8 >= PAIR9) << endl;
	cout << (PAIR8 <= PAIR9) << endl;
	cout << (PAIR8 > PAIR9) << endl;
	cout << (PAIR8 < PAIR9) << endl;

	//Swapping
	cout << "Before Swapping:\n";
	cout << "PAIR8 : " << PAIR8.first << " ";
	cout << PAIR8.second << endl;
	cout << "PAIR9 : " << PAIR9.first << " ";
	cout << PAIR9.second << endl;

	PAIR8.swap(PAIR9);
	
	cout << "After Swapping:\n";
	cout << "PAIR8 : " << PAIR8.first << " ";
	cout << PAIR8.second << endl;
	cout << "PAIR9 : " << PAIR9.first << " ";
	cout << PAIR9.second << endl;

	pair <int, int> PAIR10(PAIR9);
	cout << "PAIR10 : " << PAIR10.first << " ";
	cout << PAIR10.second << endl;
	cout << "Sum of PAIR 10:" << PAIR10.first + PAIR10.second;
	return 0;
}