/*
Name: Nur Adrianahafiy binti Muhammad Yazid
Student ID: 24006963
Group: G1
Topic: Stack
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

class Stack {
private:
	Node* top;

public:
	Stack() {
		top = nullptr;
	}

	void push(string name) {
		Node* newNode = new Node(name, top);
		top = newNode;
	}

	void pop() {
		if (top == nullptr) {
			cout << "Stack empty, nothing to pop.\n";
			return;
		}
		else {
			Node* temp = top;
			cout << "Popping the top: " << temp->name << "\n\n";
			top = top->nextPtr;
			delete temp;
		}
	}

	string peek() {
		if (top == nullptr) {
			throw runtime_error("Stack empty, cannot peek");
		}
		return top->name;
	}

	void display() {
		Node* current = top;
		while (current != nullptr) {
			cout << current->name << "->";
			current = current->nextPtr;
		}
		cout << "NULL" << endl;
	}

	~Stack() {
		Node* current = top;
		while (current != nullptr) {
			Node* temp = current;
			current = current->nextPtr;
			delete temp;
		}
	}

};

int main() {
	Stack stack;

	stack.push("Ali");
	cout << "Stack insert 1: ";
	stack.display();

	stack.push("Imran");
	cout << "Stack insert 2: ";
	stack.display();

	stack.push("Khairul");
	cout << "Stack insert 3: ";
	stack.display();

	cout << "Stack tail: " << stack.peek();

	cout << "\n\nPop stack...\n\n";
	stack.pop();

	cout << "Stack after pop: ";
	stack.display();

	cout << "Stack tail after pop: " << stack.peek() <<endl;

	return 0;
}