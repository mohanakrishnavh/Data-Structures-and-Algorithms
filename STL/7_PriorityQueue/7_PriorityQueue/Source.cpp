#include <iostream>
#include <queue>

using namespace std;

void print_pq(priority_queue <int> pq)
{
	priority_queue <int> temp = pq;
	while (!temp.empty())
	{
		cout << temp.top() << " ";
		temp.pop();
	}
	cout << '\n';
}

void print_pq_min(priority_queue<int,vector<int>,greater<int>> pq)
{
	priority_queue<int, vector<int>, greater<int>> temp = pq;
	while (!temp.empty())
	{
		cout << temp.top() << " ";
		temp.pop();
	}
	cout << '\n';
}

int main() {
	//Max-Heap
	priority_queue<int> pq;
	pq.push(10);
	pq.push(30);
	pq.push(20);
	pq.push(5);
	pq.push(1);
	
	cout << "Priority Queue : ";
	print_pq(pq);
	cout << "pq.size() : " << pq.size();
	cout << "\npq.top() : " << pq.top();
	cout << "\npq.pop() : ";
	pq.pop();
	print_pq(pq);

	//Min-Heap
	priority_queue<int, vector<int>, greater<int>> pq_min;
	pq_min.push(10);
	pq_min.push(30);
	pq_min.push(20);
	pq_min.push(5);
	pq_min.push(1);
	print_pq_min(pq_min);

	return 0;
}