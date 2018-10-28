#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};

class DoublyLinkedList {
private:
	Node *head;
	Node *tail;
	int length;

public:
	DoublyLinkedList() {
		head = NULL;
		tail = NULL;
		length = 0;
	}

	~DoublyLinkedList() {
		Node *nextNode = head;
		while (nextNode) {
			Node *deleteNode = nextNode;
			nextNode = nextNode->next;
			delete deleteNode;
		}
	}

	Node* getNewNode(int x) {
		Node* newNode = new Node();
		newNode->data = x;
		newNode->next = NULL;
		newNode->prev = NULL;
		return newNode;
	}

	void insertAtHead(int x) {
		Node* newNode = getNewNode(x);
		if (head == NULL && tail == NULL) {
			head = tail = newNode;
			return;
		}
		else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		length++;
	}

	void insertAtTail(int x) {
		Node* newNode = getNewNode(x);
		if (head == NULL && tail == NULL) {
			head = tail = newNode;
			return;
		}
		else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		length++;
	}

	void print() {
		Node* current = head;
		cout << "Doubly Linked List : ";
		while (current != NULL) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << "\n";
	}

	void reversePrint() {
		Node* current = tail;
		cout << "Doubly Linked List (Reverse) : ";
		while (current != NULL) {
			cout << current->data << " ";
			current = current->prev;
		}
		cout << "\n";
	}

};

int main() {
	DoublyLinkedList dlist;
	dlist.insertAtHead(10);
	dlist.insertAtHead(20);
	dlist.insertAtHead(30);
	dlist.print();
	dlist.reversePrint();

	dlist.insertAtTail(100);
	dlist.insertAtTail(1000);
	dlist.print();
	dlist.reversePrint();

	return 0;
}