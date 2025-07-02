/*
Name: Nur Adrianahafiy binti Muhammad Yazid
Student ID: 24006963
Group: G1
Topic: Queue
*/

#include <iostream>
using namespace std;

struct Node {
	string name;
	Node* nextPtr;

	Node(string name, Node* nextPtr = nullptr) {
		this->name = name;
		this->nextPtr = nextPtr;
	}
};

class Queue {
private:
	Node* front;
	Node* rear;

public:
	Queue() {
		front = nullptr;
		rear = nullptr;
	}

	void enqueue(string name) {
		Node* newNode = new Node(name);
		if (front == nullptr) {
			front = rear = newNode;
		}
		else {
			rear->nextPtr = newNode;
			rear = newNode;
		}
	}

	void dequeue() {
		if (front == nullptr) {
			cout << "Queue empty, nothing to dequeue.\n";
			return;
		}
		else {
			Node* temp = front;
			cout << "Dequeueing the front: " << temp->name << "\n\n";
			front = front->nextPtr;
			delete temp;
		}
	}

	void display() {
		Node* current = front;
		while (current != nullptr) {
			cout << current->name << "->";
			current = current->nextPtr;
		}
		cout << "NULL" << endl;
	}

	~Queue() {
		Node* current = front;
		while (current != nullptr) {
			Node* temp = current;
			current = current->nextPtr;
			delete temp;
		}
	}

};

int main() {
	Queue queue;

	queue.enqueue("Ali");
	queue.enqueue("Imran");
	queue.enqueue("Khairul");

	cout << "Queue: ";
	queue.display();

	cout << "Remove front..." << endl;
	queue.dequeue();

	cout << "Queue after removal: ";
	queue.display();

	return 0;
}