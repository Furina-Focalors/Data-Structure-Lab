//BST.h
#pragma once
#include<vector>
#include<stack>
class TreeNode {
	friend class BST;
public:
	TreeNode() {}
	TreeNode(int v)
		:val(v), left(nullptr), right(nullptr) {}
//private:
	int val;
	TreeNode* left;
	TreeNode* right;
};

class BST
{
public:
	BST()
		:root(nullptr) {}
	BST(TreeNode* r)
		:root(r) {}
	TreeNode* Search(int& v);
	bool Insert(int v);
	std::vector<int> InorderTraversal()const;
	TreeNode* GetRoot()const { return root; }
	//exp 1
	int KthLargest(int& k)const;
private:
	TreeNode* root;
};

