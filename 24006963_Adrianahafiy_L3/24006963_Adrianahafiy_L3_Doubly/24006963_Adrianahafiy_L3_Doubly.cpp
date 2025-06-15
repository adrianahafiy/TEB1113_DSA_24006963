/*
Name: Nur Adrianahafiy binti Muhammad Yazid
Student ID: 24006963
Group: G1
Topic: Doubly Linked List
*/

#include <iostream>
using namespace std;

struct DoublyNode {
	string name;
	DoublyNode* prev;
	DoublyNode* next;

	//constructor
	DoublyNode(string name, DoublyNode* prev = nullptr, DoublyNode* next = nullptr) {
		this->name = name;
		this->prev = prev;
		this->next = next;
	}
};

//Doubly Linked List
class DoublyLinkedList {
private:
	DoublyNode* head;
	DoublyNode* tail;

public:
	//constructor
	DoublyLinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	//add to end of list
	void add(string name) {
		DoublyNode* newNode = new DoublyNode(name);
		if (head == nullptr) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
	}

	void remove(string name) {
		DoublyNode* current = head;

		while (current != nullptr && current->name != name) {
			current = current->next;
		}

		if (current == nullptr) {
			return;
		}

		if (current == head) {
			head = current->next;
			if (head != nullptr) {
				head->prev = nullptr;
			}
			else {
				tail = nullptr;
			}
		}
		else if (current == tail) {
			tail = current->prev;
			tail->next = nullptr;
		}
		else {
			current->prev->next = current->next;
			current->next->prev = current->prev;
		}

		delete current;
	}

	//display forward
	void displayForward() {
		DoublyNode* current = head;
		while (current != nullptr) {
			cout << current->name << " <-> ";
			current = current->next;
		}
		cout << "NULL" << endl;
	}

	//display backward
	void displayBackward() {
		DoublyNode* current = tail;
		while (current != nullptr) {
			cout << current->name << " <-> ";
			current = current->prev;
		}
		cout << "NULL" << endl;
	}

	//destructor
	~DoublyLinkedList() {
		DoublyNode* current = head;
		while (current != nullptr) {
			DoublyNode* temp = current;
			current = current->next;
			delete temp;
		}
	}
};

int main() {
	DoublyLinkedList list;
	list.add("Ali");
	list.add("Sarah");
	list.add("Imran");
	list.add("Khairul");

	cout << "Forward: ";
	list.displayForward();

	cout << "Backward: ";
	list.displayBackward();

	cout << "Remove Imran\n";
	list.remove("Imran");

	cout << "Forward after removal: ";
	list.displayForward();

	cout << "Backward after removal: ";
	list.displayBackward();

	return 0;
}