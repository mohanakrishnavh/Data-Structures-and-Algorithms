#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

vector<int> generateRandVec(int n, int min, int max) {
	vector<int> values;
	srand(time(NULL));
	int i = 0, randValue = 0;
	while (i < n) {
		randValue = min + rand() % ((max + 1) - min);
		values.push_back(randValue);
		i++;
	}
	return values;
}


int main() {
	vector<int> values = generateRandVec(10, 1, 50);
	cout << "Random Vector (Unsorted) :" << endl;
	for (auto val : values) {
		cout << val << endl;
	}
	cout << "\n";

	//sort
	//Sort in reverse order using Lambda Expression
	sort(values.begin(), values.end(), [](int x, int y) {return x > y; });

	cout << "Random Vector (Sorted in reverse by Lamdba) : " << endl;
	for (auto val : values) {
		cout << val << endl;
	}
	cout << "\n";
	
	//sort
	//Sort using Lambda Expression
	sort(values.begin(), values.end(), [](int x, int y) {return x < y; });
	
	cout << "Random Vector (Sorted by Lamdba) : " << endl;
	for (auto val : values) {
		cout << val << endl;
	}
	cout << "\n";

	//copy_if
	//Copies values only if the conditon is satisfied
	vector<int> evenValues;
	copy_if(values.begin(), values.end(), back_inserter(evenValues),
		[](int x) {return (x % 2) == 0; });
	cout << "Random Vector (filter even values by Lamdba) : " << endl;
	for (auto val : evenValues) {
		cout << val << endl;
	}
	cout << "\n";
	
	//for_each
	int sum = 0;
	for_each(values.begin(), values.end(),
		[&](int x) {sum += x; });
	cout << "Sum : " << sum << "\n\n";

	//copy_if - input divisior
	int divisor;
	vector<int> values2;
	cout << "List of values divisible by : ";
	cin >> divisor;
	copy_if(values.begin(), values.end(), back_inserter(values2),
		[divisor](int x) {return (x % divisor) == 0; });
	cout << "Random Vector (divisble by input divisior) : " << endl;
	for (auto val : values2) {
		cout << val << endl;
	}
	cout << "\n";
	
	//for_each - double the value
	vector<int> doubleValues;
	for_each(values.begin(), values.end(),
		[&](int x) {doubleValues.push_back(x * 2); });
	cout << "Random Vector (double the values) : " << endl;
	for (auto val : doubleValues) {
		cout << val << endl;
	}
	cout << "\n";

	//transform
	//add values in seperate vectors and save them to another
	vector<int> vec1 = { 1,2,3,4,5 };
	vector<int> vec2 = { 1,2,3,4,5 };
	vector<int> result(5);
	transform(vec1.begin(), vec1.end(),
		vec2.begin(), result.begin(),
		[](int x, int y) {return x + y; });
	cout << "Result Vector: " << endl;
	for (auto val : result) {
		cout << val << endl;
	}
	cout << "\n";
	cout << "Saving Vector: " << endl;
	for (auto val : vec2) {
		cout << val << endl;
	}
	cout << "\n";

	//ternary operator
	int age = 26;
	bool canIVote = (age >= 18) ? true : false;
	cout << boolalpha;
	cout << "Can i vote ? : " << canIVote << "\n";

	//Recursive Lambda
	function<int(int)> Fib = 
		[&Fib](int n) {return n < 2 ? n : 
		Fib(n - 1) + Fib(n - 2); };
	cout << "Fibonacci(4) : " << Fib(4) << endl;

	//generate n fibonacci numbers;
	int no_of_fibs;
	cout << "Enter the number of fibonacci numbers to generate : ";
	cin >> no_of_fibs;
	vector<int> indices(no_of_fibs);
	vector<int> fibNumbers;

	iota(indices.begin(), indices.end(), 0);
	for_each(indices.begin(), indices.end(),
		[&](int x) {fibNumbers.push_back(Fib(x)); });
	cout << "Fibonacci of "<< no_of_fibs <<" numbers: " << endl;
	for (auto val : fibNumbers) {
		cout << val << endl;
	}
	cout << "\n";

	return 0;
}