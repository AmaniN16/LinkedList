#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "leaker.h"

using namespace std;

template <typename T>
class LinkedList
{
public:
	//Da Node
	struct Node {
	public:
		T data;
		Node* next;
		Node* prev;
	};
private:
	Node* head;
	Node* tail;

public:
	//constructors + destructors 
	LinkedList();
	LinkedList(const LinkedList<T>& list);
	~LinkedList();

	//Behaviors
	void PrintForward();
	void PrintReverse();
	void PrintForwardRecursive(const Node* node);
	void PrintReverseRecursive(const Node* node);

	//Accessor
	unsigned int NodeCount() const;
	void FindAll(vector<Node*>& outData, const T& value) const;
	Node* Find(const T& data) const;
	const Node* GetNode(unsigned int index) const;
	Node* GetNode(unsigned int index);
	const Node* Head() const;
	Node* Head();
	const Node* Tail() const;
	Node* Tail();

	//Insertion
	void AddHead(const T& data);
	void AddTail(const T& data);
	void AddNodesHead(const T* data, unsigned int count);
	void AddNodesTail(const T* data, unsigned int count);
	void InsertAfter(Node* node, const T& data);
	void InsertAt(const T& data, unsigned int index);

	//Removal
	bool RemoveHead();
	bool RemoveTail();
	unsigned int Remove(const T& data);
	bool ReomveAt(unsigned int index);
	void Clear();

	//Operators
	const T& operator[](unsigned int index) const;
	T& operator[](unsigned int index);
	bool operator==(const LinkedList<T>& rhs) const;
	LinkedList<T>& operator=(const LinkedList<T>& rhs);
};


//Class Functions

template<typename T>
LinkedList<T>::LinkedList() {
	head = nullptr;
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
	LinkedList<T> temp(rhs);
	std::swap(temp.head, head);
	return *this;
}

//Copy constructor
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) {
	if (list.head == nullptr) {
		head = nullptr;
		tail = nullptr;
	}

	else {
		head = nullptr;
		Node* listHead = list.head;
		Node* curr = head;
		Node* currList = nullptr;
		while (listHead != nullptr) {
			curr = new Node();
			curr->data = listHead->data;
			curr->next = nullptr;
			if (currList != nullptr)
				currList->next = curr;

			else
				head = curr;
			
			listHead = listHead->next;
			currList = curr;
		}
	}
	
}

template<typename T>
LinkedList<T>::~LinkedList() {
	Node* which;
	which = head;
	while (which != nullptr) {
		Node* whoNext = which->next;
		delete which;
		which = whoNext;
		whoNext = nullptr;
	}
	
	if ((head == nullptr) && (tail == nullptr)) {	
		delete head;
		delete tail;
	}
}

template <typename T>
void LinkedList<T>::AddHead(const T& data) {
	Node* tempNode = new Node();
	tempNode->data = data;
	tempNode->next = head;
	tempNode->prev = nullptr;
	if (head != nullptr)
		head->prev = tempNode;
	head = tempNode;

}

template <typename T>
void LinkedList<T>::AddTail(const T& data) {
	Node* tempNode = new Node();
	tempNode->data = data;
	tempNode->next = nullptr;
	tail = head;
	if (head == nullptr) {
		tempNode->prev = nullptr;
		head = tempNode;
		return;
	}


	while (tail->next != nullptr)
		tail = tail->next;

	tail->next = tempNode;
	tempNode->prev = tail;
	return;
}

template <typename T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count) {
	for (int i = (count - 1); i > -1; i--) {
		AddHead(data[i]);
	}
}

template <typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count) {
	for (unsigned int i = 0; i < count; i++) {
		AddTail(data[i]);
	}	
}

template <typename T>
void LinkedList<T>::PrintForward() {
	Node* which = head;
	if (which != nullptr) {
		while (which != nullptr) {
			cout << which->data << endl;
			which = which->next;
		}
	}
}

template <typename T>
void LinkedList<T>::PrintReverse() {
	Node* tail = head;
	while (tail->next != nullptr)
		tail = tail->next;
	

	while (tail != head) {
		cout << tail->data << endl;
		if (tail->prev != nullptr)
			tail = tail->prev;
	}
	cout << tail->data << endl;
}

template <typename T>
unsigned int LinkedList<T>::NodeCount() const{
	unsigned int count = 0;
	Node* which = head;
	while (which != nullptr) {
			count++;
			which = which->next;
	}
	return count;
}



template<typename T>
void LinkedList<T>::FindAll(vector<Node*>& outData, const T& value) const {
	Node* which = head;
	while (which != nullptr) {
		if (which->data == value)
			outData.push_back(which);
		which = which->next;
	}

}

template<typename T>
typename LinkedList<T>::Node* GetNode(unsigned int index) {
	int count = 0;
	while (head != nullptr) {
		if (count == index)
			return head->data;

		count++;
		head = head->next;
	}

	if (index > NodeCount())
		throw runtime_error("count too big");

}

template<typename T>
const typename LinkedList<T>::Node* GetNode(unsigned int index) {

}

template<typename T>
const typename LinkedList<T>::Node* Head(){
	
}

template <typename T>
typename LinkedList<T>::Node* Head() {
	
}

template <typename T>
const typename LinkedList<T>::Node* Tail() {
	
}

template <typename T>
typename LinkedList<T>::Node* Tail() {
	
}

template <typename T>
void LinkedList<T>::Clear() {
	Node* which = head;
	while (which != nullptr) {
		Node* del = which;
		which = which->next;
		delete del;
	}

	head = nullptr;
	tail = nullptr;
}


