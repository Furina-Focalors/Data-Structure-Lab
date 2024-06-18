//main.cpp
#include<iostream>
#include<string>
#include<stack>
#include"Queue.cpp"
using namespace std;

//exp1 func
int isValid(string s) {
	stack<char> temp;
	for (int i = 0; i < s.length(); ++i) {
		temp.push(s[i]);
		if (s[i] == ')') {
			temp.pop();
			if (temp.empty())//为空则一定无法匹配左括号
				return 0;
			else if (temp.top() != '(')
				return 0;
			else
				temp.pop();
		}
		if (s[i] == ']') {
			temp.pop();
			if (temp.empty())//为空则一定无法匹配左括号
				return 0;
			else if (temp.top() != '[')
				return 0;
			else
				temp.pop();
		}
		if (s[i] == '}') {
			temp.pop();
			if (temp.empty())//为空则一定无法匹配左括号
				return 0;
			else if (temp.top() != '{')
				return 0;
			else
				temp.pop();
		}
	}
	if (temp.empty())//全部匹配并消去，否则栈内存在左括号
		return 1;
	else
		return 0;
}


int main() {
	//exp 1
	/*string s[3] = { "(){}[][{()()[]}]" ,"){}{}()[[[]]]","([{()}]]" };
	for (int i = 0; i < 3; ++i) {
		if (isValid(s[i]))
			cout << "string is valid.\n";
		else
			cout << "string is invalid.\n";
	}
	return 0;*/
	
	//exp 2
	Queue<int> test;
	if (test.empty())cout << "queue is empty.\n";
	cout << "Pushing 0-9 to the queue...\n";
	for (int i = 0; i < 10; ++i)
		test.push(i);
	if (!test.empty())cout << "queue is not empty.\n";
	cout << "Popping an element from the queue...\n";
	test.pop();
	cout << "The first element of the queue is " << test.peek() << endl;
	cout << "The remaining elements are:\n";
	while (!test.empty()) {
		cout << test.peek() << ' ';
		test.pop();
	}
	return 0;
}