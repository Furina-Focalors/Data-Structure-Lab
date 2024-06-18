//List.h
#pragma once
#include<iostream>
template <class T>
class List;

template<class T>
class ListNode {
	friend class List<T>;
public:
	ListNode() {}
	ListNode(T d)
		:data(d), link(NULL) {}
	void print()const { std::cout << data; }
protected:
	T data;
	ListNode* link;
};

template<class T>
class List
{
public:
	List() {
		ListNode<T>* header = new ListNode<T>();
		first = header;
		length = 0;
	}
	bool Insert(int i, T x) {//insert x at position i, header.i=0
		if (i<1 || i>length + 1) {
			std::cerr << "Invalid position.\n";
			return false;
		}
		ListNode<T>* current = first;
		for (int k = 0; k < i - 1; ++k) {//find position i-1
			current = current->link;
		}
		ListNode<T>* newNode = new ListNode<T>(x);
		newNode->link = current->link;
		current->link = newNode;
		++length;
		return true;
	}
	bool Delete(int i, T& x) {//delete node at position i and pass its value to &x
		if (i<1 || i>length + 1) {
			std::cerr << "Invalid position.\n";
			return false;
		}
		ListNode<T>* current = first;
		for (int k = 1; k < i; ++k) {//find position i-1
			current = current->link;
		}
		ListNode<T>* del = current->link;
		current->link = del->link;
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
		ListNode<T>* current = first;
		current = current->link;
		for (int i = 1; i <= length; ++i) {
			std::cout << current->data << ' ';
			current = current->link;
		}
	}
	//exp 3
	ListNode<T>* intersectionNode(List<T> target)const {
		if (!length || !target.length) return NULL;
		ListNode<T>* p1 = first->link;
		ListNode<T>* p2 = target.first->link;
		if (length >= target.length) {
			for (int i = 0; i < length - target.length; ++i)
				p1 = p1->link;
			int sign = 0;//代表倒数第k个节点为交点
			for (int i = 0; i < target.length; ++i) {
				if (p1 == p2){
					p1 = p1->link;
					p2 = p2->link;
					++sign;
				}
				else {
					p1 = p1->link;
					p2 = p2->link;
					sign = 0;
				}
			}
			if (sign == 0)return NULL;
			else {
				p2 = target.first->link;
				for (int i = 0; i < target.length - sign; ++i) {
					p2 = p2->link;
				}
				return p2;
			}
		}
		else {
			for (int i = 0; i < target.length - length; ++i)
				p2 = p2->link;
			int sign = 0;//代表倒数第k个节点为交点
			for (int i = 0; i < length; ++i) {
				if (p1 == p2) {
					p1 = p1->link;
					p2 = p2->link;
					++sign;
				}
				else {
					p1 = p1->link;
					p2 = p2->link;
					sign = 0;
				}					
			}
			if (sign == 0)return NULL;
			else {
				p1 = first->link;
				for (int i = 0; i < length - sign; ++i) {
					p1 = p1->link;
				}
				return p1;
			}
		}
	}

	void linkTo(List lis, int i) {//link the last node to lis[i] 
		if (i<1 || i>length) {
			std::cerr << "Invalid position.\n";
		}
		ListNode<T>* current = first;
		ListNode<T>* target = lis.first;
		for (int j = 0; j < length; ++j)
			current = current->link;
		for (int k = 0; k < i; ++k)
			target = target->link;
		current->link = target;
		//length change
		current = current->link;
		while (current != nullptr) {
			++length;
			current = current->link;
		}
	}

	//exp 4
	void ringTo(int i) {//make the list a ring (node[length]->link=node[i])
		ListNode<T>* current = first;
		ListNode<T>* target = nullptr;
		for (int j = 0; j < length; ++j) {
			current = current->link;
			if (i == j + 1)
				target = current;
		}	
		current->link = target;
	}
	bool isRing()const {
		ListNode<T>* current = first;
		for (int i = 0; i < length; ++i)
			current = current->link;
		if (current->link != nullptr)return true;
		else return false;
	}
	bool isRing_noLength()const {
		ListNode<T>* fPtr = first;
		ListNode<T>* sPtr = first;
		while (fPtr != nullptr && fPtr->link != nullptr) {
			fPtr = fPtr->link->link;
			sPtr = sPtr->link;
			if (fPtr == sPtr)
				return true;
		}
		return false;
	}
	//extra
	ListNode<T>* ringStart()const {
		ListNode<T>* current = first;
		for (int i = 0; i < length; ++i)
			current = current->link;
		return current->link;
	}
	ListNode<T>* ringStart_noLength()const {
		ListNode<T>* fPtr = first;
		ListNode<T>* sPtr = first;
		while (fPtr != nullptr && fPtr->link != nullptr) {
			fPtr = fPtr->link->link;
			sPtr = sPtr->link;
			if (fPtr == sPtr) {
				fPtr = first;
				while (fPtr != sPtr) {
					fPtr = fPtr->link;
					sPtr = sPtr->link;
				}
				return fPtr;
			}
		}
		return NULL;
	}
private:
	ListNode<T> *first;
	int length;
};

//wrong code:
//ListNode<T>* intersectionNode_backup(List<T> target)const {
//	if (!length || !target.length) return NULL;
//	ListNode<T>* p1 = first->link;
//	ListNode<T>* p2 = target.first->link;
//	if (length >= target.length) {
//		for (int i = 0; i < length - target.length; ++i)
//			p1 = p1->link;
//		int sign = 0;//代表倒数第k个节点为交点
//		for (int i = 0; i < target.length; ++i) {
//			if (p1->data == p2->data) {
//				p1 = p1->link;
//				p2 = p2->link;
//				++sign;
//			}
//			else {
//				p1 = p1->link;
//				p2 = p2->link;
//				sign = 0;
//			}
//		}
//		if (sign == 0)return NULL;
//		else {
//			p2 = target.first->link;
//			for (int i = 0; i <= target.length - sign; ++i) {
//				p2 = p2->link;
//			}
//			return p2;
//		}
//	}
//	else {
//		for (int i = 0; i < target.length - length; ++i)
//			p2 = p2->link;
//		int sign = 0;//代表倒数第k个节点为交点
//		for (int i = 0; i < length; ++i) {
//			if (p1->data == p2->data)
//				++sign;
//			else
//				sign = 0;
//		}
//		if (sign == 0)return NULL;
//		else {
//			p1 = first->link;
//			for (int i = 0; i <= length - sign; ++i) {
//				p1 = p1->link;
//			}
//			return p1;
//		}
//	}
//}
//for (int x = 0; x < 2; ++x) {
	//	List<int> listA;
	//	List<int> listB;
	//	int a = 0, pos = 1;
	//	cout << "enter listA element(114514 to exit):";//test data:1 2 3 4 5 114514    1 2 3 4 5 114514
	//	while (cin >> a && a != 114514) {
	//		listA.Insert(pos, a);
	//		++pos;
	//	}
	//	cout << "listA is:\n";
	//	listA.print();
	//	cout << endl;
	//	a = 0;
	//	pos = 1;
	//	cout << "enter listB element(114514 to exit):";//test data:1 3 4 5 114514      1 2 3 4 6 114514
	//	while (cin >> a && a != 114514) {
	//		listB.Insert(pos, a);
	//		++pos;
	//	}
	//	cout << "listB is:\n";
	//	listB.print();
	//	cout << endl;
	//	if (listA.intersectionNode(listB) != NULL) {
	//		cout << "intersection Node is: ";
	//		listA.intersectionNode(listB)->print();
	//		cout << endl;
	//	}
	//	else
	//		cout << "intersection Node is: NULL\n";
	//}
	//return 0;