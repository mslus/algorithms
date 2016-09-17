/*
 * generic_bfs.cc
 *
 *  Created on: Sep 17, 2016
 *      Author: maciek
 */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define UNDISCOVERED 0
#define DISCOVERED 1
#define PROCESSED 2

using namespace std;

struct Graph{
	vector< vector<int> > adj;

	Graph(int n){
		adj.resize(n+1);
	}
};


vector<int> bfs(Graph G, int start){

	queue<int> q;
	vector<int> visited(G.adj.size(), UNDISCOVERED);
	vector<int> parent(G.adj.size(), -1);
	vector<int> distance(G.adj.size(), 0);

	q.push(start);
	visited[start] = DISCOVERED;
	while(!q.empty()){
		int x = q.front();
		q.pop();

		// processing node early - for now just print it
		cout << x << endl;

		for(int i = 0; i < G.adj[x].size(); i++){
			if(visited[G.adj[x][i]] == UNDISCOVERED){
				//node not discovered
				cout << "Tree edge " << x << "-->" << G.adj[x][i] << endl;
				parent[G.adj[x][i]] = x;
				q.push(G.adj[x][i]);
				visited[G.adj[x][i]] = DISCOVERED;
				distance[G.adj[x][i]] = distance[x]+1;
			}else if(visited[G.adj[x][i]] == DISCOVERED){
				//this is non-tree edge
				cout << "Non-tree edge " << x << "-->" << G.adj[x][i] << endl;
			}
		}

		//processing after adding all edges
		visited[x] = PROCESSED;
	}

	for(int i = 1; i < G.adj.size(); i++)
		cout << i << " " << distance[i] << endl;

	return parent;
}


void path(int x, int y, vector<int> &parent){
	if(x == y)
		cout << x << " ";
	else{
		path(x, parent[y], parent);
		cout << y << " ";
	}
}

void path_explicit(int x, int y, vector<int> &parent){
	int a = y;
	stack<int> S;
	S.push(a);
	while(a != x){
		a = parent[a];
		S.push(a);
	}

	while(!S.empty()){
		cout << S.top() << " ";
		S.pop();
	}
	cout << endl;
}


int main(){
	int n, m;
	int x, y;

	cin >> n >> m;
	Graph G(n);
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		G.adj[x].push_back(y);
		G.adj[y].push_back(x);
	}

	vector<int> parent = bfs(G, 1);

	cout << "Testing path from node" << endl;
	path(1,10,parent);
	cout << endl;

	path_explicit(1,6,parent);
	return 0;
}



