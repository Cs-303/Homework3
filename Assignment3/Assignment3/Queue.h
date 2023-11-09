#pragma once
#include <iostream>
using namespace std;


//queue data structure
template <typename Item_Type>
class Queue {
private:
	Node<Item_Type>* head;
	Node<Item_Type>* tail;
	int total;

public:
	Queue() { head = nullptr; tail = nullptr; total = 0; };

	//add item to back
	void enQueue(Item_Type data) {
		Node<Item_Type>* newNode = new Node<Item_Type>(data);
		if (tail == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->nextPtr = newNode;
			tail = newNode;
		}
		total++;
	}

	//delete item from front, else throw runtime error
	void deQueue() {
		if (head == nullptr) throw runtime_error("Error: Can't dequeue from empty list\n");
		else if (head == tail) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			Node<Item_Type>* delNode = head;
			head = head->nextPtr;
			delete delNode;
		}
		total--;
	}

	//return item from front, else throw runtime error
	Item_Type front() {
		if (empty()) throw runtime_error("Error: Queue is empty\n\n");
		return head->data;
	};

	//return bool expression if list is empty or not
	bool empty() { return (head == nullptr); };

	//return size of queue
	int size() { return total; };

	//Show all item currently in queue
	void show_list() {
		Node<Item_Type>* currentNode = head;
		if (empty()) cout << "Queue is Empty";
		while (currentNode != nullptr) {
			cout << "->" << currentNode->data;
			currentNode = currentNode->nextPtr;
		}
		cout << "\n";
	}
};
