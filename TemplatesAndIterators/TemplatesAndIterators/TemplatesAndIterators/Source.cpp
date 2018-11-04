#include <iostream>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

//Templace Functions
template<typename T>
void square(T val) {
	cout << val << " ^ 2 = " << val * val << "\n";
}

template<typename T>
T add(T val1, T val2) {
	return val1 + val2;
}


template<typename T>
T max(T val1, T val2) {
	return (val1 < val2) ? val2 : val1;
}

//Template Classes
template<typename T, typename U>
class Person {
public:
	T height;
	U weight;
	static int numOfPeople;

	Person(T h, U w) {
		height = h;
		weight = w;
		numOfPeople++;
	}

	void getData() {
		cout << "Height : " << height << endl;
		cout << "Weight : " << weight << endl;
	}
};

template<typename T, typename U> int Person<T, U>::numOfPeople;


int main(){
	square(10);
	square(10.10);

	cout << "5 + 4 = " << add(5, 4) << endl;
	cout << "5.5 + 4.6 = " << add(5.5, 4.6) << endl;

	cout << "MAX(4,8) = " << max(4, 8) << endl;
	cout << "MAX(4.5,8.9) = " << max(4.5, 8.9) << endl;
	cout << "MAX(A,B) = " << max('A', 'B') << endl;
	cout << "MAX(Dog,Cat) = " << max("Dog", "Cat") << endl;
	
	Person<double, int> mikeTyson(5.83, 216);
	mikeTyson.getData();

	cout << "Number of people : " << mikeTyson.numOfPeople << "\n";
	cout << "\n";

	//Iterator
	vector<int> nums = { 1,2,3,4 };
	vector<int>::iterator itr;
	for (itr = nums.begin(); itr < nums.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;

	vector<int>::iterator itr2 = nums.begin();
	advance(itr2, 1);
	cout << *itr2 << endl;

	auto itr3 = next(itr2, 1);
	cout << *itr3 << endl;

	auto itr4 = prev(itr2, 1);
	cout << *itr4 << endl;

	vector<int> nums2 = { 1,4,5,6 };
	vector<int> nums3 = { 2,3 };
	auto itr5 = nums2.begin();
	advance(itr5, 1);
	copy(nums3.begin(), nums3.end(), inserter(nums3, itr5));
	for (int &i : nums3) {
		cout << i << "\n";
	}

	return 0;
}