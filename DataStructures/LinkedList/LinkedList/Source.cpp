#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

class LinkedList {
private:
	Node *head;
	Node *tail;
	int length;

public:
	LinkedList() {
		head = NULL;
		tail = NULL;
		length = 0;
	}

	~LinkedList() {
		Node *nextNode = head;
		while (nextNode) {
			Node *deleteNode = nextNode;
			nextNode = nextNode->next;
			delete deleteNode;
		}
	}

	int get(int index) {
		if (index == 0) {
			return head->data;
		}
		else if (index == (length - 1)) {
			return tail->data;
		}
		else if (index < length) {
			Node *current = head;
			int count = 0;
			while (count < index) {
				current = current->next;
				count++;
			}
			return current->data;
		}
		return -1;
	}

	void addAtHead(int val) {
		Node *newNode = new Node();
		newNode->data = val;

		if (head == NULL && tail== NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
		length++;
	}

	void addAtTail(int val) {
		Node *newNode = new Node();
		newNode->data = val;

		if (head == NULL && tail == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		length++;
	}

	void addAtIndex(int index, int val) {
		if (index < length) {
			if (index == 0) {
				addAtHead(val);
				goto finished;
			}

			int count = 0;
			Node *previousNode = NULL;
			Node *newNode = new Node();
			Node *current = head;
			while (count < index) {
				previousNode = current;
				current = current->next;
				count++;
			}
			newNode->data = val;
			newNode->next = previousNode->next;
			previousNode->next = newNode;
			length++;
		}
		else {
			cout << "\nIndex mentioned is greated than the size of the list. Adding value to the tail of the list.\n";
			addAtTail(val);
		}
	finished:;
	}

	void removeAtHead() {
		if (length > 0) {
			if (head == tail) {
				head = tail = NULL;
			}
			else {
				Node *current = head;
				head = head->next;
				delete current;
			}
			length--;
		}
		else {
			cout << "Empty list!\n";
		}
	}

	void removeAtTail() {
		if (length > 0) {
			if (head == tail) {
				head = tail = NULL;
			}
			else {
				Node *current = head;
				Node *previous = NULL;
				while (current->next != NULL) {
					previous = current;
					current = current->next;
				}
				previous->next = NULL;
				delete current;
				tail = previous;
			}
			length--;
		}
		else {
			cout << "Empty list!\n";
		}
	}

	void reverse() {
		Node *prev = NULL, *next;
		Node *current = head;
		tail = current;
		while (current != NULL) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}

	void reverseRecursive() {
		printReverseRecursiveUtil(head);
	}

	void reverseRecursiveUtil(Node* p) {
		if (p->next == NULL) {
			head = p;
			return;
		}
		reverseRecursiveUtil(p->next);
		Node* q = p->next;
		q->next = p;
		p->next = NULL;
		tail = p;
	}

	void print() {
		if (head) {
			Node *cursor = head;
			while (cursor) {
				if (cursor->next == NULL) {
					cout << cursor->data;
				}
				else {
					cout << cursor->data << " --> ";
				}
				cursor = cursor->next;
			}
		}
		else {
			cout << "Empty list!\n";
		}
		cout << "\n";
	}

	void printRecursive() {
		printRecursiveUtil(head);
	}

	void printReverseRecursive() {
		printReverseRecursiveUtil(head);
	}

	void printRecursiveUtil(Node* p) {
		if (p == NULL) { //exit condition
			return;
		}
		cout << p->data << " "; //print the value in the node
		printRecursiveUtil(p->next); //recursive call
	}

	void printReverseRecursiveUtil(Node* p) {
		if (p == NULL) {
			return;
		}
		printReverseRecursiveUtil(p->next);
		cout << p->data << " ";
	}
};


int main() {
	LinkedList list;
	list.print();
	list.addAtTail(10);
	list.addAtTail(20);
	list.addAtHead(5);
	list.addAtHead(8);
	list.print();

	list.removeAtTail();
	list.print();

	list.removeAtHead();
	list.print();

	list.addAtIndex(1, 9);
	list.print();
	list.addAtIndex(10, 100);
	list.print();
	list.addAtIndex(0, 100);
	list.print();

	cout << "\nElement at index 0: " << list.get(0) << endl;
	cout << "Element at index 2: " << list.get(2) << endl;
	cout << "Element at index 4: " << list.get(4) << endl;
	cout << "Element at index 5: " << list.get(5) << endl;
	
	cout << "\nReversed List : ";
	list.reverse();
	list.print();

	cout << "Original List : ";
	list.reverse();
	list.print();
	cout << "\n";

	cout << "Printing the list recusrively : ";
	list.printRecursive();
	cout << "\n";
	cout << "Printing reverse of the list recusrively : ";
	list.printReverseRecursive();
	cout << "\n\n";

	list.print();

	cout << "Reversing the list recusrively : ";
	list.reverseRecursive();
	cout << "\n";
	list.print();
	cout << "\n";

	return 0;
}