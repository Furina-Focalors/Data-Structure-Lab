#include<iostream>
#include"BinaryTree.h"
using namespace std;

//exp 4 support
template<class T>
vector<T> getPart(vector<T>arr, int start, int end) {//return arr[start:end+1]
	if (start < 0 || end >= arr.size()) {
		cerr << "Invalid array index range.\n";
		exit(0);
	}
	vector<T> result;
	for (int i = start; i <= end; ++i)
		result.push_back(arr[i]);
	return result;
}

template<class T>
TreeNode<T>* constructTree(std::vector<TreeNode<T>*>pre, std::vector<TreeNode<T>*>in) {
	int i = 0, size = pre.size();
	if (size == 1)return pre[0];
	for (; i < size && in[i] != pre[0]; ++i);//get root index in inorder sequence
	if (i != 0)
		pre[0]->lChild = constructTree(getPart(pre, 1, i), getPart(in, 0, i - 1));//construct left subtree
	if (i != size - 1)
		pre[0]->rChild = constructTree(getPart(pre, i + 1, size - 1), getPart(in, i + 1, size - 1));//construct right subtree
	return pre[0];
}

TreeNode<int>* constructTree(vector<int> preorder, vector<int> inorder) {
	int i = 0, size = preorder.size();
	TreeNode<int>* node = new TreeNode<int>(preorder[0]);
	if (size == 1)return node;
	for (; i < size && inorder[i] != preorder[0]; ++i);//get root index in inorder sequence
	if (i != 0)
		node->lChild = constructTree(getPart(preorder, 1, i), getPart(inorder, 0, i - 1));//construct left subtree
	if (i != size - 1)
		node->rChild = constructTree(getPart(preorder, i + 1, size - 1), getPart(inorder, i + 1, size - 1));//construct right subtree
	return node;
}

int main() {
	/*BinaryTree<int> testTree;
	testTree.BuildRoot(1);
	TreeNode<int>* current = testTree.root;
	testTree.InsertChild(current, 0, 2);
	testTree.InsertChild(current, 1, 3);
	current = current->lChild;
	testTree.InsertChild(current, 0, 4);
	testTree.InsertChild(current, 1, 5);
	current = current->rChild;
	testTree.InsertChild(current, 1, 6);
	current = testTree.root->rChild;
	testTree.InsertChild(current, 1, 7);
	current = current->rChild;
	testTree.InsertChild(current, 0, 8);
	testTree.InsertChild(current, 1, 9);*/

	//exp 1
	/*cout << testTree.getDepth(testTree.root) << endl;
	return 0;*/

	//exp 2
	/*testTree.treeToChain();
	current = testTree.root;
	while (current) {
		cout << current->data << ' ';
		if (!current->lChild)current = current->rChild;
	}
	cout << endl;
	return 0;*/

	//exp 3
	/*testTree.Invert(testTree.root);
	testTree.preorderTraverse();
	return 0;*/

	//exp 4
	TreeNode<int>* node[10];
	for (int i = 1; i <= 9; ++i) {
		node[i] = new TreeNode<int>(i);
	}
	vector<TreeNode<int>*>pre = { node[1],node[2],node[4],node[5],node[6],node[3],node[7],node[8],node[9] };
	vector<TreeNode<int>*>in = { node[4],node[2],node[5],node[6],node[1],node[3],node[8],node[7],node[9] };
	BinaryTree<int> tree;
	tree.root = constructTree(pre, in);
	tree.preorderTraverse();
	cout << endl;
	vector<int>preorder = { 1,2,4,5,6,3,7,8,9 };
	vector<int>inorder = { 4,2,5,6,1,3,8,7,9 };
	BinaryTree<int>tree2;
	tree2.root = constructTree(preorder, inorder);
	tree2.preorderTraverse();
	cout << endl;
	return 0;
}