#include <iostream>
#include <queue>

using namespace std;

void show_queue(queue<int> q) {
	queue<int> gq = q;
	while (!gq.empty()) {
		cout << gq.front() << "\t";
		gq.pop();
	}
	cout << "\n";
}

int main() {
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);

	cout << "The queue : ";
	show_queue(q);

	cout << "\nQueue Size : " << q.size();
	cout << "\nQueue Front : " << q.front();
	cout << "\nQueue Back : " << q.back();

	cout << "\nq.pop() : ";
	q.pop();
	show_queue(q);
}