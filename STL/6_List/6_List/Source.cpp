#include <iostream>
#include <list>
#include <iterator>

using namespace std;

void show_list(list<int> l) {
	list<int> ::iterator itr;
	for (itr = l.begin(); itr != l.end(); ++itr) {
		cout << *itr << '\t';
	}
	cout << '\n';
}

int main() {
	list<int> l1, l2;

	for (int i = 0; i < 10; i++) {
		l1.push_back(i * 2);
		l2.push_front(i * 3);
	}

	//Displaying the lists
	cout << "\nList 1 : \n";
	show_list(l1);
	cout << "\nList 2 : \n";
	show_list(l2);

	cout << "\nl1.front() : " << l1.front() << endl;
	cout << "\nl1.back() : " << l1.back() << endl;

	cout << "\nl1.pop_front() : ";
	l1.pop_front();
	show_list(l1);

	cout << "\nl2.pop_back() : ";
	l2.pop_back();
	show_list(l2);

	cout << "\nl1.reverse() : ";
	l1.reverse();
	show_list(l1);

	cout << "\nl2.sort(): ";
	l2.sort();
	show_list(l2);

	// Initializing list1 
	list<int> gqlist1 = { 1, 2, 3 };

	// Initializing list2 
	list<int> gqlist2 = { 2, 4, 6 };

	// using merge() to merge list1 with list2 
	gqlist1.merge(gqlist2);

	// Displaying list elements  
	cout << "list1 after merge operation is : ";
	for (int &x : gqlist1) cout << x << " ";
	cout << endl;

	// using remove_if() to remove odd elements 
	// removes 1 and 3 
	gqlist1.remove_if([](int x) {return x % 2 != 0; });

	// Displaying list elements  
	cout << "list1 after remove_if operation is : ";
	for (int &x : gqlist1) cout << x << " ";
	cout << endl;

	return 0;
}