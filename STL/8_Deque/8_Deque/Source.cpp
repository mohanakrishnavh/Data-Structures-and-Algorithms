#include <iostream>
#include <deque>
#include <iterator>

using namespace std;

void show_deque(deque<int> dq) {
	deque<int> ::iterator it;
	for (it = dq.begin(); it != dq.end(); ++it)
	{
		cout << *it << '\t';
	}
	cout << endl;
}

int main() {
	deque<int> dqueue;
	dqueue.push_back(10);
	dqueue.push_front(20);
	dqueue.push_back(30);
	dqueue.push_front(15);
	show_deque(dqueue);

	cout << "\ndqueue.size() : " << dqueue.size();
	cout << "\ndqueue.max_size() : " << dqueue.max_size();

	cout << "\ndqueue.at(2) : " << dqueue.at(2);
	cout << "\ndqueue.front() : " << dqueue.front();
	cout << "\ndqueue.back() : " << dqueue.back();

	cout << "\ndqueue.pop_front() : ";
	dqueue.pop_front();
	show_deque(dqueue);

	cout << "\ndqueue.pop_back() : ";
	dqueue.pop_back();
	show_deque(dqueue);

	return 0;
}