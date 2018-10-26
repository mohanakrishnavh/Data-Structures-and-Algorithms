#include <iostream>
#include <map>
#include <string>
#include <iterator>

using namespace std;

int main() {
	map<char, int> count_map;

	//Inserting Elements in random order
	count_map.insert(pair <char, int>('a', 10));
	count_map.insert(pair <char, int>('c', 10));
	count_map.insert(pair <char, int>('b', 5));
	count_map.insert(pair <char, int>('d', 1));
	count_map.insert(pair <char, int>('f', 3));
	count_map.insert(pair <char, int>('e', 2));
	count_map.insert(pair <char, int>('m', 95));
	count_map.insert(pair <char, int>('n', 99));
	count_map.insert(pair <char, int>('o', 100));
	count_map.insert(pair <char, int>('v', 101));

	//Printing the map
	map<char, int> ::iterator itr;
	cout << "\ncount_map : \n";
	cout << "\tKEY\tELEMENT\n";
	for (itr = count_map.begin(); itr != count_map.end(); ++itr)
	{
		cout << '\t' << itr->first
			<< '\t' << itr->second << '\n';
	}
	cout << endl;

	// assigning the elements from count_map to count_map2 
	map <char, int> count_map2(count_map.begin(), count_map.end());

	// print all elements of the map count_map2 
	cout << "\nThe map count_map2 after assign from gquiz1 is : \n";
	cout << "\tKEY\tELEMENT\n";
	for (itr = count_map2.begin(); itr != count_map2.end(); ++itr)
	{
		cout << '\t' << itr->first
			<< '\t' << itr->second << '\n';
	}
	cout << endl;

	map<string, int> length_map;
	string s1("String 1");
	string s2 = "String 2 + 1";
	string s3 = "String 3 + 2 + 1";
	length_map[s1] = s1.size();
	length_map[s2] = s2.size();
	length_map[s3] = s3.size();
	int size = length_map.size();
	cout << "Size of s1 : " << length_map[s1];


	return 0;
}