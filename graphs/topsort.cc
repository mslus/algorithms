/*
 * topsort.cc
 *
 *  Created on: Sep 25, 2016
 *      Author: maciek
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Graph{
	vector< vector<int> > adj;

	Graph(int n){
		adj.resize(n+1);
	}
};

vector<int> topsort(const Graph &G){
	vector<int> result;
	vector<int> nosource(G.adj.size(),0);
	queue<int> Q;

	for(int i = 1; i < G.adj.size(); i++)
		for(int x : G.adj[i])
			nosource[x]++;

	for(int i = 1; i < nosource.size(); i++)
		if(nosource[i] == 0) Q.push(i);

	while(!Q.empty()){
		int v = Q.front();
		Q.pop();
		for(int x : G.adj[v]){
			nosource[x]--;
			if(nosource[x] == 0) Q.push(x);
		}
		result.push_back(v);
	}

	if(result.size() < (G.adj.size()-1)){
		result.clear();
	}

	return result;
}

int main(){
	int n, m;
	int x, y;

	cin >> n >> m;
	Graph G(n);
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		G.adj[x].push_back(y);
	}

	vector<int> ts = topsort(G);
	for(int i = 0; i < ts.size(); i++)
		cout << ts[i] << " ";
	cout << endl;

	return 0;
}

