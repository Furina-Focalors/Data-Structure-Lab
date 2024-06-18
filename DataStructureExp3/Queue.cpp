//Queue.cpp
#include<stack>
#include<iostream>


template<class T>
class Queue
{
public:
	Queue() {};

	void push(const T& item) {
		data.push(item);
		//size = data.size();
	}
	void pop() {
		if (data.empty()) {
			std::cerr << "Illegal operation:popping from an empty queue.\n";
			exit(EXIT_FAILURE);
		}
		while (!data.empty()) {
			temp.push(data.top());
			data.pop();
		}
		temp.pop();//移除原堆栈最底层的元素，即队列中最靠前的元素
		while (!temp.empty()) {
			data.push(temp.top());
			temp.pop();
		}
		//size = data.size();
	}

	bool empty()const {
		return data.empty();
	}

	T peek() {
		while (!data.empty()) {
			temp.push(data.top());
			data.pop();
		}
		T result = temp.top();
		while (!temp.empty()) {
			data.push(temp.top());
			temp.pop();
		}
		return result;
	}
	//int getSize()const;
private:
	std::stack<T> data;
	std::stack<T> temp;
	//int size;
};