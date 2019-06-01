#pragma once
#include "Includes.h"

using namespace std;

template <typename T>
class List {
public:
	List();
	~List();

	void push(T data);
	void del(int index);
	void del(string name);
	void write();
	void writeUp();
	T& findBook(string authorName);

	int len() {
		return this->size;
	}

	T& operator[](const int index);
	T& operator[](string name);

private:
	template <typename T>
	class Node {
	public:
		T data;

		Node *pNext;

		Node(T data = T(), Node *pNext = NULL) {
			this->data = data;
			this->pNext = pNext;
		}
	};

	Node<T> *head = NULL;
	int size;
};