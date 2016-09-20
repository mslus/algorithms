/*
 * dijkstra.cc
 *
 *  Created on: Sep 19, 2016
 *      Author: maciek
 */
// This is really modified implementation of Prim's algorithm
// Differences commented in the code below

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
	int parent;
	int cost;

	edge(int a, int b, int c){
		x = a; parent = b; cost = c;
	}
};

bool operator<(const edge &e1, const edge &e2){
	if(e1.cost != e2.cost) return e1.cost > e2.cost;
	else if(e1.x != e2.x) return e1.x > e2.x;
	else if(e1.parent != e2.parent) return e1.parent > e2.parent;
	else return false;
}

void dijkstra(Graph G, int start){
	priority_queue<edge> pq;
	vector<int> parent(G.adj.size(), -1);
	vector<bool> visited(G.adj.size(), false);
	//vector of cost instead of single value
	vector<int> cost(G.adj.size(), 0);

	pq.push(edge(start,-1, 0));

	while(!pq.empty()){
		edge e = pq.top();
		pq.pop();

		if(!visited[e.x]){
			parent[e.x] = e.parent;
			visited[e.x] = true;
			//populate table of costs
			cost[e.x] = e.cost;

			for(int i = 0; i < G.adj[e.x].size(); i++)
				// add to cost that have been tracked
				pq.push(edge(G.adj[e.x][i].first, e.x, e.cost+G.adj[e.x][i].second ));
		}
	}

	for(int i = 0; i < G.adj.size(); i++)
		cout << i << " " << parent[i] << " " << cost[i] << endl;

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

	dijkstra(G, 0);
	return 0;

}





