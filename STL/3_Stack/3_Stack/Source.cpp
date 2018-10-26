#include <iostream>
#include <stack>

using namespace std;

void show_stack(stack<int> s) {
	while (!s.empty()) {
		cout << "\t" << s.top();
		s.pop();
	}
	cout << "\n";
}

int main() {
	stack<int> s;
	s.push(10);
	s.push(30);
	s.push(20);
	s.push(5);
	s.push(1);

	cout << "Stack Size: " << s.size() << endl;
	cout << "Stack Elements: ";
	show_stack(s);

	cout << "\ns.pop() : ";
	s.pop();
	show_stack(s);

	return 0;
}