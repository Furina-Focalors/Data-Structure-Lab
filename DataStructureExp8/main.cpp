//main.cpp
#include<iostream>
#include<vector>
#include"BST.h"

//exp 2
std::vector<int> InorderTraversal(TreeNode* root) {
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
bool isBST(TreeNode* root) {
	std::vector<int> res = InorderTraversal(root);
	int size = res.size();
	for (int i = 1; i < size; ++i)
		if (res[i] <= res[i - 1])return false;
	return true;
}

int main() {
	BST tree;
	//exp 1
	//int ele;
	//std::cout << "输入元素：";//2 5 3 1 4
	//for (int i = 0; i < 5; ++i) {
	//	std::cin >> ele;
	//	tree.Insert(ele);
	//}
	//std::cout << "输入k：";
	tree.Insert(2);
	tree.Insert(5);
	tree.Insert(3);
	tree.Insert(1);
	tree.Insert(4);
	//int k=2;
	//std::cin >> k;
	//std::cout << "第2大的节点为" << tree.KthLargest(k) << '\n';
	//exp 2
	if (isBST(tree.GetRoot())) {
		std::cout << "是BST，中序遍历为：";
		std::vector<int>inorder = InorderTraversal(tree.GetRoot());
		for (int i = 0; i < inorder.size(); ++i)std::cout << inorder[i];
		std::cout << '\n';
	}
	std::cout << "将上述二叉树（中序）[1,2,3,4,5]打乱为[1,2,3,5,4]\n";
	TreeNode* root = new TreeNode(2);
	TreeNode* cur = root;
	cur->left = new TreeNode(1);
	cur->right = new TreeNode(5);
	cur = cur->right;
	cur->left = new TreeNode(3);
	cur->right = new TreeNode(4);
	if (!isBST(root)) {
		std::cout << "不是BST，中序遍历为：";
		std::vector<int>inorder = InorderTraversal(root);
		for (int i = 0; i < inorder.size(); ++i)std::cout << inorder[i];
		std::cout << '\n';
	}
	return 0;
}