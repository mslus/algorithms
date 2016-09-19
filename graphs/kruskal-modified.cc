/*
 * kruskal-modified.cc
 *
 *  Created on: Sep 19, 2016
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

	edge(const edge &e){
		x = e.x;
		y = e.y;
		cost = e.cost;
	}
};

struct ufind{
	vector<int> M;
	vector<int> count;

	ufind(int n){
		M.resize(n);
		count.resize(n);
		for(int i = 0; i < n; i++){
			M[i] = i;
			count[i] = 1;
		}
	}

	int subset(int x){
		while(M[x] != x) x = M[x];
		return x;
	}

	bool sameSubset(int x, int y){
		if(subset(x) == subset(y))
			return true;
		else
			return false;
	}

	void un(int A, int B){
		if(count[A] >= count[B]){
			M[B] = A;
			count[A] = count[A] + count[B];
			count[B] = 0;
		}else{
			M[A] = B;
			count[B] = count[A] + count[B];
			count[A] = 0;
		}
	}
};

bool operator<(const edge &e1, const edge &e2){
	if(e1.cost != e2.cost) return e1.cost > e2.cost;
	else if(e1.x != e2.x) return e1.x > e2.x;
	else if(e1.y != e2.y) return e1.y > e2.y;
	else return false;
}

void kruskal(Graph G){
	priority_queue<edge> pq;

	ufind U(G.adj.size());
	vector<edge> E;
	int cost = 0;


	for(int i = 0; i < G.adj.size(); i++)
		for(int j = 0; j < G.adj[i].size(); j++)
			pq.push(edge(i,G.adj[i][j].first, G.adj[i][j].second));

	while(!pq.empty()){
		edge e = pq.top();
		pq.pop();

		if(!U.sameSubset(e.x,e.y)){
			U.un(U.subset(e.x),U.subset(e.y));
			E.push_back(e);
			cost+=e.cost;
		}
	}


	for(int i = 0; i < E.size(); i++)
		cout << E[i].x << " " << E[i].y << " " << E[i].cost << endl;
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

	kruskal(G);
	return 0;

}





