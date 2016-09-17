/*
 * generic_dfs.cc
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

void dfs(Graph &G, int start, vector<int> &visited, vector<int> &parent, vector<int> &entry, vector<int> &exit, int &time){

	visited[start] = DISCOVERED;
	entry[start] = time;
	time++;
	cout << start << endl;

	//process vertex early

	for(int i = 0; i < G.adj[start].size(); i++){
		if(visited[G.adj[start][i]] == UNDISCOVERED){
			parent[G.adj[start][i]] = start;
			// tree edge, proccess as needed
			dfs(G, G.adj[start][i], visited, parent, entry, exit, time);
		}else if(visited[G.adj[start][i]] == DISCOVERED){
			// back edge, this can be used to discover cycle
			if(parent[start] != G.adj[start][i])
				cout << "Edge " << start << " --> " << G.adj[start][i] << " creates cycle" << endl;
		}
	}

	visited[start] = PROCESSED;
	exit[start] = time;
	time++;
	//	cout << start << endl;

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

	vector<int> visited(G.adj.size(), UNDISCOVERED);
	vector<int> parent(G.adj.size(), -1);

	vector<int> entry(G.adj.size(), 0);
	vector<int> exit(G.adj.size(), 0);
	int time  = 0;

	dfs(G, 1, visited, parent, entry, exit, time);

	for(int i = 1; i < G.adj.size(); i++)
		cout << i << " " << parent[i] << " " << entry[i] << " " << exit[i] << endl;


	return 0;
}

