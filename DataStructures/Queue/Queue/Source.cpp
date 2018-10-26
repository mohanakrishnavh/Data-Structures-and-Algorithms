#include <iostream>

using namespace std;

#define MAX_SIZE 100

class Queue {
private:
	int Q[MAX_SIZE];
	int front, rear;

public:
	Queue() {
		front = -1;
		rear = -1;
	}

	~Queue(){
		front = NULL;
		rear = NULL;
	}

	//To check if the queue is empty
	bool isEmpty() {
		if (front == -1 && rear == -1) {
			return true;
		}
		else {
			return false;
		}
	}

	//To check if the queue is full
	bool isFull() {
		if ((rear + 1) % MAX_SIZE == front) {
			return true;
		}
		return false;
	}

	//Insert an element at the rear end of Queue
	void enqueue(int x) {
		if (isFull()) {
			cout << "Queue is full!\n";
			return;
		}
		if (isEmpty()) {
			front = rear = 0;
		}
		else {
			rear = (rear + 1) % MAX_SIZE;
		}
		Q[rear] = x;
	}

	//Removes an element from the front end of Queue
	int dequeue() {
		int element;
		if (isEmpty()) {
			element = NULL;
		}
		else if (front == rear) {
			element = Q[front];
			front = rear = -1;
		}
		else {
			element = Q[front];
			front = (front + 1) % MAX_SIZE;
		}
		return element;
	}

	//Returns the first element in the Queue
	int qFront() {
		if (front != -1) {
			return Q[front];
		}
		else {
			cout << "Queue is empty!\n";
			return NULL;
		}
	}


	void print() {
		int size = ((rear + (MAX_SIZE - front)) % MAX_SIZE) + 1;
		int index;
		cout << " Queue :";
		for (int i = 0; i < size; i++) {
			index = (front + i) % MAX_SIZE;
			cout << Q[index] << " ";
		}
		cout << endl;
	}

};



int main() {
	Queue Q;
	Q.enqueue(2);
	Q.enqueue(4);
	Q.enqueue(6);
	Q.print();
	cout << boolalpha;
	cout << "Queue is empty ? : " << Q.isEmpty() << endl;
	
	int x = Q.dequeue();
	x = Q.dequeue();
	x = Q.dequeue();
	cout << "x :" << x << endl;

	cout << "Queue is empty ? : " << Q.isEmpty() << endl;

	return 0;
}