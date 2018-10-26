#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortcol(const vector<int>& v1, const vector<int>& v2) {
	return v1[1] < v2[1];
}

bool sortcoldesc(const vector<int>& v1, const vector<int>& v2) {
	return v1[1] > v2[1];
}

bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
	return (a.first > b.first);
}

int main() {
	vector<vector<int>> vect{ {3,5,1}, {4, 8,6}, {7,2,9} };
	int m = vect.size(); //number of rows
	int n = vect[0].size(); //number of cols

	//Case 1 : To sort a particular row of 2D vector
	//Diaplaying 2-D Matrix before sorting
	cout << "Matrix before sorting 1st row :\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << vect[i][j] << " ";
		}
		cout << endl;
	}

	//sort() for sorting first row
	sort(vect[0].begin(), vect[0].end());

	//Displaying the 2-D Matrix after sorting
	cout << "Matrix after sorting 1st row :\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << vect[i][j] << " ";
		}
		cout << endl;
	}

	//Case 2: To sort a particular column of a 2D vector
	vector<vector<int>> vect2{ {3,5,1}, {4, 8,6}, {7,2,9} };
	int m2 = vect2.size(); //number of rows
	int n2 = vect2[0].size(); //number of cols
	cout << "Matrix before sorting 2nd column :\n";
	for (int i = 0; i < m2; i++) {
		for (int j = 0; j < n2; j++) {
			cout << vect2[i][j] << " ";
		}
		cout << endl;
	}
	//sorting based on 2nd column
	sort(vect2.begin(), vect2.end(), sortcol);
	cout << "Matrix after sorting 2nd column :\n";
	for (int i = 0; i < m2; i++) {
		for (int j = 0; j < n2; j++) {
			cout << vect2[i][j] << " ";
		}
		cout << endl;
	}

	//Case 3 : To sort a particular row of 2D vector in descending order
	//Diaplaying 2-D Matrix before sorting
	vector<vector<int>> vect3{ {3,5,1}, {4, 8,6}, {7,2,9} };
	cout << "Matrix before sorting 1st row :\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << vect3[i][j] << " ";
		}
		cout << endl;
	}

	//sort() for sorting in descending order first row
	sort(vect3[0].rbegin(), vect3[0].rend());

	//Displaying the 2-D Matrix after sorting
	cout << "Matrix after sorting 1st row(descending order) :\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << vect3[i][j] << " ";
		}
		cout << endl;
	}

	//Case 4: To sort a particular column of a 2D vector in descending order
	vector<vector<int>> vect4{ {3,5,1}, {4, 8,6}, {7,2,9} };
	int m4 = vect4.size(); //number of rows
	int n4 = vect4[0].size(); //number of cols
	cout << "Matrix before sorting 2nd column :\n";
	for (int i = 0; i < m4; i++) {
		for (int j = 0; j < n4; j++) {
			cout << vect4[i][j] << " ";
		}
		cout << endl;
	}
	//sorting based on 2nd column
	sort(vect4.rbegin(), vect4.rend(), sortcoldesc);
	cout << "Matrix after sorting 2nd column :\n";
	for (int i = 0; i < m2; i++) {
		for (int j = 0; j < n2; j++) {
			cout << vect2[i][j] << " ";
		}
		cout << endl;
	}

	vector<pair<int, int>> vectpair;
	int arr[] = { 5,20,10,40 };
	int arr1[] = { 30,60,20,50 };
	int vect_pair_size = sizeof(arr) / sizeof(arr[0]);
	// Entering values in vector of pairs 
	for (int i = 0; i < n; i++)
		vectpair.push_back(make_pair(arr[i], arr1[i]));

	// Printing the original vector(before sort()) 
	cout << "The vector before applying sort is:\n";
	for (int i = 0; i < n; i++)
	{
		// "first" and "second" are used to access 
		// 1st and 2nd element of pair respectively 
		cout << vectpair[i].first << " "
			<< vectpair[i].second << endl;

	}
	// using modified sort() function to sort 
	sort(vectpair.begin(), vectpair.end(), sortinrev);

	// Printing the sorted vector(after using sort()) 
	cout << "The vector after applying sort is:\n";
	for (int i = 0; i < n; i++)
	{
		// "first" and "second" are used to access 
		// 1st and 2nd element of pair respectively 
		cout << vectpair[i].first << " "
			<< vectpair[i].second << endl;
	}

	return 0;
}