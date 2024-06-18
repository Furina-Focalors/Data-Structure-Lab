#pragma once
#include<stack>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>

template<class T>
class TreeNode {
public:
	TreeNode()
		:lChild(nullptr),rChild(nullptr){}
	TreeNode(T d)
		:data(d),lChild(nullptr),rChild(nullptr){}
//private:
	T data;
	TreeNode* lChild;
	TreeNode* rChild;
};

template<class T>
class BinaryTree
{
public:
	BinaryTree()
		:root(nullptr) {}
	BinaryTree(T data, TreeNode<T>* lCh, TreeNode<T>* rCh) {
		root = new TreeNode<T>(data);
		root->lChild = lCh;
		root->rChild = rCh;
	}
	BinaryTree(TreeNode<T>* r) {
		root = r;
	}

	bool BuildRoot(T data) {
		if (root) {
			std::cout << "Root already exists.\n";
			return false;
		}
		else {
			root = new TreeNode<T>(data);
			if (!root) {
				std::cout << "Memory allocation failed.\n";
				return false;
			}
			return true;
		}
	}

	TreeNode<T>* getNode(T d) {
		//inorder traverse to find node
		std::stack<TreeNode<T>*>tempStack;
		TreeNode<T>* current = root;
		do {
			while (current != nullptr) {
				tempStack.push(current);
				current = current->lChild;//LVR, visit leftChild first
			}
			//current = node without leftChild
			if (!tempStack.empty()) {//top=node without leftchild(or leftchild has been visited)
				tempStack.pop(current);
				if (current->data == d)return current;//visit(current)
				current = current->rChild;//get rightChild
			}
		} while (current != nullptr || !tempStack.empty());
		return nullptr;
	}

	bool InsertChild(TreeNode<T>* parent, int lr, T data) {
		if (!parent) {
			std::cout << "Invalid insertion position.\n";
			return false;
		}
		if (!lr) {//lr==0 leftChild
			if (parent->lChild) {
				std::cout << "The parent already has a left child.\n";
				return false;
			}
			parent->lChild = new TreeNode<T>(data);
			return true;
		}
		else {//lr!=0 rightChild
			if (parent->rChild) {
				std::cout << "The parent already has a right child.\n";
				return false;
			}
			parent->rChild = new TreeNode<T>(data);
			return true;
		}
	}

	//exp 1
	int getDepth(TreeNode<T>* root)const {
		return root ? std::max(getDepth(root->lChild) + 1, getDepth(root->rChild) + 1) : 0;
	}
	//exp 2
	void treeToChain() {
		//get preorder sequence
		std::stack<TreeNode<T>*> tempStack;
		std::queue<TreeNode<T>*> resultQueue;
		TreeNode<T>* current = root;
		while (current || !tempStack.empty()) {
			while (current) {
				resultQueue.push(current);//访问根
				if (current->rChild)tempStack.push(current->rChild);//保存右子树
				current = current->lChild;//访问左子树
			}
			if (!tempStack.empty()) {
				current = tempStack.top();//节点无左子树，访问最深层的右子树
				tempStack.pop();
				resultQueue.push(current);
				if (current->rChild)tempStack.push(current->rChild);
				current = current->lChild;
			}
		}
		current = resultQueue.front();
		resultQueue.push(nullptr);//最后一个指针指向nullptr
		while (!resultQueue.empty()&&current) {//调整节点左右指针
			resultQueue.pop();
			current->lChild = nullptr;
			current->rChild = resultQueue.front();
			current = resultQueue.front();
		}
	}

	//exp 3
	TreeNode<T>* Invert(TreeNode<T>* node) {
		if (node == nullptr)return nullptr;
		TreeNode<T>* temp = node->lChild;
		node->lChild = node->rChild;
		node->rChild = temp;
		Invert(node->lChild);
		Invert(node->rChild);
		return node;
	}
	void preorderTraverse()const {
		//get preorder sequence
		std::stack<TreeNode<T>*> tempStack;
		TreeNode<T>* current = root;
		while (current || !tempStack.empty()) {
			while (current) {
				std::cout<<current->data<<' ';//访问根
				if (current->rChild)tempStack.push(current->rChild);//保存右子树
				current = current->lChild;//跳转左子树
			}
			if (!tempStack.empty()) {
				current = tempStack.top();//节点无左子树，访问最深层的右子树
				tempStack.pop();
				std::cout << current->data << ' ';
				if (current->rChild)tempStack.push(current->rChild);
				current = current->lChild;
			}
		}
	}

//private:
	TreeNode<T>* root;
};

