#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> g1;
	for (int i = 0; i <= 5; i++) {
		g1.push_back(i);
	}

	//Iterators
	cout << "Output of begin and end: ";
	for (auto i = g1.begin(); i != g1.end(); ++i)
		cout << *i << " ";

	cout << "\nOutput of cbegin and cend: ";
	for (auto i = g1.cbegin(); i != g1.cend(); ++i)
		cout << *i << " ";

	cout << "\nOutput of rbegin and rend: ";
	for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
		cout << *ir << " ";

	cout << "\nOutput of crbegin and crend : ";
	for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir)
		cout << *ir << " ";

	//Member Functions
	cout << "\n\n";
	vector<int> g2;
	for (int i = 1; i <= 5; i++) {
		g1.push_back(i);
	}

	cout << "Size : " << g1.size();
	cout << "\nCapacity : " << g1.capacity();
	cout << "\nMaximum Size : " << g1.max_size();

	//resizes the vector size to 4
	g1.resize(4);
	cout << "\nSize(After Resize) : " << g1.size();

	//check if the vector is empty
	if (g1.empty() == false) {
		cout << "\nVector is not empty.";
	}
	else {
		cout << "\nVector is empty.";
	}

	//shrinks the vector
	g1.shrink_to_fit();
	cout << "\nVector elements are: ";
	for (auto it = g1.begin(); it != g1.end(); it++) {
		cout << *it << " ";
	}

	//Accessing elements
	vector<int> g3;
	for (int i = 1; i <= 10; i++)
		g3.push_back(i * 10);

	cout << "\nReference operator [g] : g3[2] = " << g3[2];
	cout << "\nat : g3.at(4) = " << g3.at(4);
	cout << "\nfront() : g3.front() = " << g3.front();
	cout << "\nback() : g3.back() = " << g3.back();


	//Modifiers
	vector<int> v;

	v.assign(5, 10); //fill the array with 10 five times

	cout << "Vector v elements are: ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	v.push_back(15); //inserts 15 to the last position
	int n = v.size();
	cout << "\nThe last element of v : " << v[n - 1];

	v.pop_back(); //removes last element
	v.insert(v.begin(), 5); //inserts 5 at the begining
	v.erase(v.begin()); // removes the first element

	//insert copies objects into vector
	//emplace constructs them inside of the vector 

	v.emplace(v.begin(), 10); //inserts 10 at the begining
	cout << "\nThe first element of v : " << v[0];
	v.emplace_back(20); //inserts 20 at the end
	n = v.size();
	cout << "\nThe last element of v : " << v[n - 1];

	//erases the vector
	v.clear();
	cout << "\nVector size after erase: " << v.size();

	// two vector to perform swap 
	vector<int> v1, v2;
	v1.push_back(1);
	v1.push_back(2);
	v2.push_back(3);
	v2.push_back(4);

	cout << "\n\nVector 1: ";
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";

	cout << "\nVector 2: ";
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";

	// Swaps v1 and v2 
	v1.swap(v2);

	cout << "\nAfter Swap \nVector 1: ";
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";

	cout << "\nVector 2: ";
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";

	return 0;
}