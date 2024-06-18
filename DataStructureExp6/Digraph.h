//Digraph.h
#pragma once
#include<vector>
#include<queue>
class edgeNode {
public:
	edgeNode(int i=0)
		:index(i),next(nullptr){}
//private:
	int index;
	edgeNode* next;
};
class vertexNode {
public:
	vertexNode(int d=0)
		:data(d),firstEdge(nullptr){}
//private:
	int data;
	edgeNode* firstEdge;
};
class Digraph
{
public:
	Digraph(int v = 0)
		:vertex(v),adj(std::vector<vertexNode>(v)),edge(0) {
		for (int i = 1; i <= v; ++i) {
			adj[i - 1].data = i;
		}
	}
	void addEdge(int fromIndex,int toIndex) {
		if (!adj[fromIndex].firstEdge) {//无出边
			adj[fromIndex].firstEdge = new edgeNode(toIndex);
			++edge;
			return;
		}
		edgeNode* cur = adj[fromIndex].firstEdge;
		while (cur->next)cur = cur->next;
		cur->next = new edgeNode(toIndex);
		++edge;
	}
	//exp 1
	int shortestLength();
	//exp 3
	std::vector<int> courSequence();
//private:
	std::vector<vertexNode>adj;//邻接表
	int vertex;//顶点数
	int edge;//边数
};

