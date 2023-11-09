#pragma once
#include <iostream>
using namespace std;

template <typename Item_Type>
struct Node {
	Item_Type data;
	Node<Item_Type>* nextPtr;
	Node(Item_Type data2) { data = data2; nextPtr = nullptr; };
};

//stack data structure
template <typename Item_Type>
class Stack {
private:
	Node<Item_Type>* head = nullptr;
	int total;

public:
	Stack() { head = nullptr; total = 0; };

	//add item to front
	void push(Item_Type item) {
		Node<Item_Type>* newNode = new Node<Item_Type>(item);
		newNode->nextPtr = head;
		head = newNode;
		total++;
	}

	//delete item from front, else throw runtime error
	void pop() {
		if (head == nullptr) throw runtime_error("Error: Can't pop from empty list\n");
		else {
			Node<Item_Type>* delNode = head;
			head = head->nextPtr;
			delete delNode;
			total--;
		}
	}

	//return item from front, else throw runtime error
	Item_Type top() { 
		if (empty()) throw runtime_error("Error: Stack is empty\n\n");
		return head->data; 
	};

	//return bool expression if list is empty or not
	bool empty() { return (head == nullptr); };

	//return size of stack
	int size() { return total; };

	//Show all item currently in stack
	void show_list() {
		Node<Item_Type>* currentNode = head;
		if (empty()) cout << "Stack is Empty\n";
		while (currentNode != nullptr) {
			cout << "  " << currentNode->data;
			currentNode = currentNode->nextPtr;
		}
		cout << "\n";
	}
};





















