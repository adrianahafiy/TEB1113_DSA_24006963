/*
Name: Nur Adrianahafiy binti Muhammad Yazid
Student ID: 24006963
Group: G1
Topic: Singly Linked List
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

class LinkedList {
private:
	Node* head;
	Node* tail;

public:
	LinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	void add(string name) {
		Node* newNode = new Node(name);
		if (head == nullptr) {
			head = tail = newNode;
		}
		else {
			tail->nextPtr = newNode;
			tail = newNode;
		}
	}

	void remove(string name) {
		if (head == nullptr) {
			return;
		}
		if (head->name == name) {
			Node* temp = head;
			head = head->nextPtr;
			delete temp;
			if (head == nullptr) {
				tail = nullptr;
				return;
			}
		}

		Node* current = head;
		while (current->nextPtr != nullptr && current->nextPtr->name != name) {
			current = current->nextPtr;
		}

		if (current->nextPtr != nullptr) {
			Node* temp = current->nextPtr;
			current->nextPtr = current->nextPtr->nextPtr;
			if (temp == tail) {
				tail = current;
				delete temp;
			}
		}
	}

	void display() {
		Node* current = head;
		while (current != nullptr) {
			cout << current->name << "->";
			current = current->nextPtr;
		}
		cout << "NULL" << endl;
	}

	~LinkedList() {
		Node* current = head;
		while (current != nullptr) {
			Node* temp = current;
			current = current->nextPtr;
			delete temp;
		}
	}

};

int main() {
	LinkedList list;

	list.add("Ali");
	list.add("Imran");
	list.add("Khairul");

	cout << "Linked List: ";
	list.display();

	cout << "Remove Ali..." << endl;
	list.remove("Ali");

	cout << "Linked List after removal: ";
	list.display();

	return 0;
}