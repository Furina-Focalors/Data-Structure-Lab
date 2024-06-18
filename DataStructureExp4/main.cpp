//main.cpp
#include<iostream>
#include"List.h"
#include"DoublyList.h"
using namespace std;


int main() {
	//exp 1
	//DoublyList<int> list;
	//int a = 0, pos = 1;
	//cout << "enter list element(114514 to exit):";//test data:1 2 3 4 5 6 7 114514
	//while (cin >> a && a != 114514) {
	//	list.Insert(pos, a);
	//	++pos;
	//}
	//cout << "List is:\n";
	//list.print();
	//cout << endl;
	//for (int i = 0; i < 2; ++i) {
	//	cout << "enter position(from the bottom):";//test data: 5 2(first half + second half)
	//	int k;
	//	cin >> k;
	//	cout << k<< "th from the bottom is:";
	//	list.bottomK(k)->print();
	//	cout << endl;
	//}
	//return 0;
	
	//exp 2
	//DoublyList<int> list;
	//int a = 0, pos = 1;
	//cout << "enter list element(114514 to exit):";//test data:1 2 3 4 5 6 7 8 114514
	//while (cin >> a && a != 114514) {
	//	list.Insert(pos, a);
	//	++pos;
	//}
	//cout << "List is:\n";
	//list.print();
	//cout << endl;
	//cout << "After inverse:\n";
	//list.inverse();
	//cout << endl;
	//return 0;

	//exp 3
	/*List<int> listA;
	List<int> listB;
	for (int i = 1; i <= 10; ++i) {
		listA.Insert(i, i);
		listB.Insert(i, 10 + i);
	}
	cout << "listA is:\n";
	listA.print();
	cout << endl;
	cout << "listB is:\n";
	listB.print();
	cout << endl;
	if (listA.intersectionNode(listB) != nullptr) {
		cout << "listA.intersectionNode(listB) = ";
		listA.intersectionNode(listB)->print();
		cout << endl;
		cout << "listB.intersectionNode(listA) = ";
		listB.intersectionNode(listA)->print();
		cout << endl;
	}
	else
		cout << "No intersection.\n";
	cout << "link listB to listA[i] (input i): ";
	int i;
	cin >> i;
	listB.linkTo(listA, i);
	if (listA.intersectionNode(listB) != nullptr) {
		cout << "listA.intersectionNode(listB) = ";
		listA.intersectionNode(listB)->print();
		cout << endl;
		cout << "listB.intersectionNode(listA) = ";
		listB.intersectionNode(listA)->print();
		cout << endl;
	}
	else
		cout << "No intersection.\n";
	return 0;*/

	//exp 4 & extra
	List<int> list;
	int a = 0, pos = 1;
	cout << "enter list element(114514 to exit):";//test data:1 2 3 4 5 6 7 8 114514
	while (cin >> a && a != 114514) {
		list.Insert(pos, a);
		++pos;
	}
	cout << "List is:\n";
	list.print();
	cout << endl;
	cout << "using isRing():\n";
	if (list.isRing())cout << "ring.\n";
	else cout << "not ring.\n";
	cout << "-----------------\nusing isRing_noLength():\n";
	if (list.isRing_noLength())cout << "ring.\n";
	else cout << "not ring.\n";
	//test start
	cout << "-----------------\nusing ringStart():\nring starts at node: ";
	if (list.ringStart() != NULL) {
		list.ringStart()->print();
	}
	else
		cout << "NULL";
	cout << "\n-----------------\nusing ringStart_noLength():\nring starts at node: ";
	if (list.ringStart_noLength() != NULL) {
		list.ringStart_noLength()->print();
	}
	else
		cout << "NULL";
	cout << "\n=================\nringTo:";
	cin >> a;
	list.ringTo(a);
	cout << "using isRing():\n";
	if (list.isRing())cout << "ring.\n";
	else cout << "not ring.\n";
	cout << "-----------------\nusing isRing_noLength():\n";
	if (list.isRing_noLength())cout << "ring.\n";
	else cout << "not ring.\n";
	cout << "-----------------\nusing ringStart():\nring starts at node: ";
	if (list.ringStart() != NULL) {
		list.ringStart()->print();
	}
	else
		cout << "NULL";
	cout << "\n-----------------\nusing ringStart_noLength():\nring starts at node: ";
	if (list.ringStart_noLength() != NULL) {
		list.ringStart_noLength()->print();
	}
	else
		cout << "NULL";
	return 0;
}