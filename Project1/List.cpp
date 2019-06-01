#include "List.h"	

template<typename T>
List<T>::List() {
	size = 0;
	head = NULL;
}
template<typename T>
List<T>::~List() {

}

template<typename T>
void List<T>::del(int index) {
	if (index >= size) return;

	int i = 0;
	Node<T> *counterNode = head;
	if (index != 0) {
		while (i < index - 1) {
			counterNode = counterNode->pNext;
			i++;
		}
		if (counterNode->pNext->pNext != NULL) {
			counterNode->pNext = counterNode->pNext->pNext;
		}
		else {
			counterNode->pNext = NULL;
		}
	}
	else {
		this->head = this->head->pNext;
	}

	size--;
}

template<typename T>
void List<T>::del(string name) {
	int i = 0;

	Node<T> *counterNode = head;
	while (i < size) {
		counterNode = counterNode->pNext;
			
		if (counterNode->data == name) {
			del(i);
		}

		i++;
	}
}

template<typename T>
void List<T>::push(T data) {
	if (this->head == NULL) {
		this->head = new Node<T>(data);
	}
	else {
		Node<T> *counterNode = head;
		while (counterNode->pNext != NULL) {
			counterNode = counterNode->pNext;
		}

		counterNode->pNext = new Node<T>(data);
	}

	size++;
}

template<typename T>
void List<T>::write() {
	Node<T> *curentNode = head;
	for (int i = 0; i < this->size; i++) {
		cout << "[" << i << "] " << curentNode->data << endl;
		curentNode = curentNode->pNext;
	}
	cout << endl;
}

template <typename T>
void List<T>::writeUp() {
	Node<T> *curentNode = head;
	for (int i = 0; i < this->size; i++) {
		cout << "[" << i << "] ";
		curentNode->data.info();
		curentNode = curentNode->pNext;
	}
	cout << endl;
}

template<typename T>
T & List<T>::operator[](const int index)
{
	Node<T> *curentNode = head;
	for (int i = 0; i < this->size; i++) {
		if (i == index) {
			return curentNode->data;
		}
		curentNode = curentNode->pNext;
	}

	T *defaultNode = new T();
	return *defaultNode;
}

template<typename T>
T & List<T>::operator[](string name)
{
	Node<T> *curentNode = head;
	for (int i = 0; i < this->size; i++) {
		if (curentNode->data.name == name) {
			return curentNode->data;
		}
		curentNode = curentNode->pNext;
	}

	T *defaultNode = new T("НЕ определено");
	return *defaultNode;
}

template<typename T>
T & List<T>::findBook(string authorName) {
	Node<T> *curentNode = head;
	for (int i = 0; i < this->size; i++) {
		if (curentNode->data.author == authorName) {
			return curentNode->data;
		}
		curentNode = curentNode->pNext;
	}

	T *defaultNode = new T("НЕ определено");
	return *defaultNode;
}