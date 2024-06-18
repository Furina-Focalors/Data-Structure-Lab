//BST.cpp
#include "BST.h"

TreeNode* BST::Search(int& v) {
	if (!root)return nullptr;
	TreeNode* cur = root;
	while (cur) {
		if (cur->val > v)cur = cur->left;
		else if (cur->val < v)cur = cur->right;
		else return cur;
	}
	return nullptr;
}

bool BST::Insert(int v) {
	if (!root) {
		root = new TreeNode(v);
		return true;
	}
	TreeNode* cur = root;
	while (cur) {
		if (!cur->left && cur->val > v) {
			cur->left = new TreeNode(v);
			return true;
		}
		else if (!cur->right && cur->val < v) {
			cur->right = new TreeNode(v);
			return true;
		}
		if (cur->val > v)cur = cur->left;
		else if (cur->val < v)cur = cur->right;
	}
	return false;
}

std::vector<int> BST::InorderTraversal()const {
	std::vector<int> result;
	std::stack<TreeNode*> temp;
	TreeNode* cur = root;
	while (cur != nullptr || !temp.empty()) {
		while (cur != nullptr) {
			temp.push(cur);
			cur = cur->left;
		}
		if (!temp.empty()) {
			cur = temp.top();
			temp.pop();
			result.emplace_back(cur->val);
			cur = cur->right;
		}
	}
	return result;
}

int BST::KthLargest(int& k)const {
	std::vector<int> seq = InorderTraversal();
	if (k > seq.size())return NULL;
	else return seq[seq.size() - k];
}