//main.cpp
#include<iostream>
#include<vector>
#include"Digraph.h"
#include<algorithm>
#include<string>
using namespace std;
//exp 2
class edge {
public:
	edge() {}
	edge(int v1, int v2, int w)
		:a(v1), b(v2), weight(w) {}
	bool operator<(edge& e)const {
		return weight < e.weight;
	}
	int a;
	int b;
	int weight;
};

int Find(vector<int>parents, int p) {
	if (p == parents[p])return p;
	return Find(parents, parents[p]);
}

int Kruskal(int vertex,vector<edge>edges) {
	sort(edges.begin(), edges.end());
	int result = 0, edgeCount = 0;
	int size = edges.size();
	//unionFind
	vector<int>v(vertex);
	for (int i = 0; i < vertex; ++i)v[i] = i;
	for (int i = 0; i < size; ++i) {
		int v1 = edges[i].a, v2 = edges[i].b, w = edges[i].weight;
		v1 = Find(v, v1);
		v2 = Find(v, v2);
		if (v1 != v2) {
			result += w;
			++edgeCount;
			v[v1] = v2;
		}
	}
	if (edgeCount < vertex - 1) {
		cout << "Impossible.\n";
		return NULL;
	}
	else return result;
}

//extra
class UnionFind {
public:
	UnionFind(int total) 
		:parents(vector<int>(total))
	{
		for (int i = 0; i < total; ++i)
			parents[i] = i;
	}
	int Find(int p) {
		if (p == parents[p])return p;
		return Find(parents[p]);
	}
	void Union(int p, int q) {
		int rootP = Find(p), rootQ = Find(q);
		if (rootP != rootQ)parents[rootQ] = rootP;
	}
private:
	vector<int>parents;
};
bool hasSolution(vector<string>equation) {
	int size = equation.size();
	UnionFind set(26);//a=0,b=1,...,z=25
	vector<string>nEquations;//存放不等式
	for (int i = 0; i < size; ++i) {
		if (equation[i][1] == '=') {
			set.Union((int)(equation[i][0] - 'a'), (int)(equation[i][3] - 'a'));
		}
		else
			nEquations.emplace_back(equation[i]);
	}
	int size2 = nEquations.size();
	for (int i = 0; i < size2; ++i) {
		if (set.Find((int)(nEquations[i][0] - 'a')) == set.Find((int)(nEquations[i][3] - 'a')))
			return false;
	}
	return true;
}

int main() {
	//exp 1
	/*Digraph graph(6), graph2(6);
	graph.addEdge(0, 3);
	graph.addEdge(0, 4);
	graph.addEdge(1, 0);
	graph.addEdge(2, 1);
	graph.addEdge(3, 4);
	graph.addEdge(4, 1);
	graph.addEdge(4, 2);
	graph.addEdge(4, 5);
	graph2.addEdge(0, 3);
	graph2.addEdge(0, 4);
	graph2.addEdge(1, 0);
	graph2.addEdge(2, 1);
	graph2.addEdge(3, 4);
	graph2.addEdge(4, 1);
	graph2.addEdge(4, 2);
	cout << graph.shortestLength()<<' '<<graph2.shortestLength();
	return 0;*/

	//exp 2
	/*vector<edge>edges;
	edges.emplace_back(edge(0, 1, 7));
	edges.emplace_back(edge(0, 1, 11));
	edges.emplace_back(edge(0, 3, 2));
	edges.emplace_back(edge(0, 4, 10));
	edges.emplace_back(edge(1, 2, 3));
	edges.emplace_back(edge(1, 4, 5));
	edges.emplace_back(edge(2, 4, 1));
	edges.emplace_back(edge(3, 4, 4));
	edges.emplace_back(edge(4, 5, 6));
	edges.emplace_back(edge(0, 0, 8));
	edges.emplace_back(edge(2, 5, -1));
	cout << Kruskal(6, edges) << endl;
	vector<edge>edges2;
	edges2.emplace_back(edge(0, 1, 7));
	edges2.emplace_back(edge(0, 1, 11));
	edges2.emplace_back(edge(0, 4, 10));
	edges2.emplace_back(edge(1, 2, 3));
	edges2.emplace_back(edge(1, 4, 5));
	edges2.emplace_back(edge(2, 4, 1));
	edges2.emplace_back(edge(4, 5, 6));
	edges2.emplace_back(edge(0, 0, 8));
	edges2.emplace_back(edge(2, 5, -1));
	Kruskal(6, edges2);
	return 0;*/

	//exp 3
	/*Digraph graph(10);
	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(1, 3);
	graph.addEdge(2, 4);
	graph.addEdge(3, 6);
	graph.addEdge(3, 5);
	graph.addEdge(4, 3);
	graph.addEdge(4, 5);
	graph.addEdge(4, 7);
	graph.addEdge(5, 7);
	graph.addEdge(6, 8);
	graph.addEdge(7, 8);
	graph.addEdge(8, 9);
	vector<int>res = graph.courSequence();
	for (int i = 0; i < res.size(); ++i)cout << res[i] << ' ';
	cout << endl;
	return 0;*/

	//extra
	vector<string>equation;
	equation.emplace_back("a==b");
	equation.emplace_back("c==b");
	equation.emplace_back("g==f");
	equation.emplace_back("f!=a");
	equation.emplace_back("h==f");
	if (hasSolution(equation))cout << "Has solution.\n";
	else cout << "No solution.\n";
	vector<string>equation2;
	equation2.emplace_back("a==b");
	equation2.emplace_back("c==b");
	equation2.emplace_back("g==f");
	equation2.emplace_back("c!=a");
	equation2.emplace_back("h==f");
	if (hasSolution(equation2))cout << "Has solution.\n";
	else cout << "No solution.\n";
	return 0;
}