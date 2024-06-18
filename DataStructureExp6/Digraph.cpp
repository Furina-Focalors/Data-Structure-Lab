//Digraph.cpp
#include "Digraph.h"
using namespace std;

//exp 1
int Digraph::shortestLength() {//BFS
	if (vertex == 1)return 0;
	std::queue<int>queue;//下标
	std::vector<int>marked(vertex);//标记
	int result = 0;
	queue.push(0);
	queue.push(-1);//标记层的结束
	marked[0] = 1;
	while (!queue.empty()) {
		int v = queue.front();
		queue.pop();
		if (v == -1) {
			++result;
			continue;
		}
		if (v == vertex - 1)return result;
		edgeNode* cur = adj[v].firstEdge;
		while (cur) {
			if (!marked[cur->index]) {
				queue.push(cur->index);
				if (!cur->next)queue.push(-1);//表示层末尾
				marked[cur->index] = 1;
			}
			cur = cur->next;
		}
	}
	return -1;
}

//exp 3
vector<int> Digraph::courSequence() {
	vector<int>res;
	vector<int>inDegree(vertex);
	for (int i = 0; i < vertex; ++i) {//get in-degree
		edgeNode* cur = adj[i].firstEdge;
		while (cur) {
			++inDegree[cur->index];
			cur = cur->next;
		}
	}
	while (res.size() < vertex) {
		for (int i = 0; i < vertex; ++i) {
			if (!inDegree[i]) {
				res.emplace_back(i);
				--inDegree[i];//去除点
				edgeNode* cur = adj[i].firstEdge;
				while (cur) {
					--inDegree[cur->index];
					cur = cur->next;
				}
			}
		}
	}
	return res;
}