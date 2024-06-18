//DoublyList.h
#pragma once
#include<iostream>

template<class T>
class DoublyList;

template<class T>
class DoublyNode {
	friend class DoublyList<T>;
public:
	DoublyNode() {}
	DoublyNode(T d)
		:data(d), lLink(nullptr), rLink(nullptr) {}
	void print()const { std::cout << data; }
private:
	T data;
	DoublyNode* lLink;
	DoublyNode* rLink;
};

template<class T>
class DoublyList
{
public:
	DoublyList() {
		DoublyNode<T>* header = new DoublyNode<T>();
		header->lLink = header->rLink = header;
		first = header;
		length = 0;
	}
	bool Insert(int i, T x) {//insert x at position i, header.i=0
		if (i > length + 1||i<1) {
			std::cerr << "Invalid position.\n";
			return false;
		}
		DoublyNode<T>* current = first;
		if (i <= length / 2 + 1) {//sequential traversal if i is at the first half
			int k = 1;
			while (k < i) {
				current = current->rLink;
				++k;
			}
		}
		else {//reverse traversal
			int k = length + 1;
			while (k >= i) {
				current = current->lLink;
				--k;
			}
		}
		DoublyNode<T>* newNode = new DoublyNode<T>(x);
		newNode->rLink = current->rLink;
		current->rLink->lLink = newNode;
		newNode->lLink = current;
		current->rLink = newNode;
		++length;
		return true;
	}
	bool Delete(int i, T& x) {//delete node at position i and pass its value to &x
		if (i > length + 1 || i < 1) {
			std::cerr << "Invalid position.\n";
			return false;
		}
		DoublyNode<T>* del = first;//find position i
		if (i <= length / 2 + 1) {//sequential traversal if i is at the first half
			int k = 1;
			while (k <= i) {
				del = del->rLink;
				++k;
			}
		}
		else {//reverse traversal
			int k = length + 1;
			while (k > i) {
				del = del->lLink;
				--k;
			}
		}
		del->lLink->rLink = del->rLink;
		del->rLink->lLink = del->lLink;
		x = del->data;
		delete del;
		--length;
		return true;
	}
	void print()const {
		if (!length) {
			std::cout << "Empty.";
			return;
		}
		DoublyNode<T>* current = first;
		current = current->rLink;
		for (int i = 1; i <= length; ++i) {
			std::cout << current->data << ' ';
			current = current->rLink;
		}
	}
	int Length()const { return length; }
	//exp 1
	DoublyNode<T>* bottomK(int k)const {
		if (k > length || k < 1) {
			std::cerr << "Invalid position.\n";
			return NULL;
		}
		DoublyNode<T>* current = first;
		if (length - k + 1 <= length / 2 + 1) {//sequential traversal if bottomK is at the first half
			int n = 1;
			while (n <= length - k + 1) {
				current = current->rLink;
				++n;
			}
		}
		else {//reverse traversal
			int n = length + 1;
			while (n > length - k + 1) {
				current = current->lLink;
				--n;
			}
		}
		return current;
	}
	//exp 2
	void inverse() {
		if (length < 1)return;
		DoublyNode<T>* current = first;
		DoublyNode<T>* temp = nullptr;
		/*DoublyNode<T>** lHolder = nullptr;
		DoublyNode<T>** rHolder = nullptr;*/
		for (int i = 0; i <= length; ++i) {//switch lLink and rLink for every node
			temp = current->rLink;
			current->rLink = current->lLink;
			current->lLink = temp;
			/*lHolder = &current->lLink;
			rHolder = &current->rLink;
			temp = *rHolder;
			*rHolder = *lHolder;
			*lHolder = temp;*/

			current = current->lLink;//lLink is the next element in the original list
		}
		print();
	}
private:
	DoublyNode<T>* first;
	int length;
};

