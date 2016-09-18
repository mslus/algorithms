/*
 * prim.cc
 *
 *  Created on: Sep 18, 2016
 *      Author: maciek
 */
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct Graph{
	vector< vector< pair<int, int> > > adj;

	Graph(int n){
		adj.resize(n);
	}
};

struct edge{
	int x;
	int y;
	int cost;

	edge(int a, int b, int c){
		x = a; y = b; cost = c;
	}
};

bool operator<(const edge &e1, const edge &e2){
	if(e1.cost != e2.cost) return e1.cost > e2.cost;
	else if(e1.x != e2.x) return e1.x > e2.x;
	else if(e1.y != e2.y) return e1.y > e2.y;
	else return false;
}

void prim(Graph G, int start){
	priority_queue<edge> pq;
	set<int> S;
	vector<int> parent(G.adj.size(), -1);
	int cost = 0;

	for(int i = 0; i < G.adj[start].size(); i++)
		pq.push(edge(start, G.adj[start][i].first, G.adj[start][i].second ));
	S.insert(start);

	while(S.size() < G.adj.size()){
		// remove edges that already have second end in the set
		while(S.find(pq.top().y) != S.end()) pq.pop();

		edge e = pq.top();
		pq.pop();
		for(int i = 0; i < G.adj[e.y].size(); i++)
				pq.push(edge(e.y, G.adj[e.y][i].first, G.adj[e.y][i].second ));
		S.insert(e.y);
		parent[e.y] = e.x;
		cost+=e.cost;
	}

	for(int i = 0; i < G.adj.size(); i++)
		cout << i << " " << parent[i] << endl;
	cout << "cost: " << cost << endl;

}

int main(){
	int n, m;
	int x, y, z;

	cin >> n >> m;
	Graph G(n);
	for(int i = 0; i < m; i++){
		cin >> x >> y >> z;
		G.adj[x].push_back( pair<int,int>(y, z) );
		G.adj[y].push_back( pair<int,int>(x, z) );
	}

	prim(G, 0);
	return 0;

}

