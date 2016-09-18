/*
 * kruskal.cc
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

	edge(const edge &e){
		x = e.x;
		y = e.y;
		cost = e.cost;
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
	set< set<int> > S;
	vector<edge> E;
	int cost = 0;

	for(int i = 0; i < G.adj.size(); i++){
		set<int> si;
		si.insert(i);
		S.insert(si);
	}

	for(int i = 0; i < G.adj.size(); i++)
		for(int j = 0; j < G.adj[i].size(); j++)
			pq.push(edge(i,G.adj[i][j].first, G.adj[i][j].second));



	while(!pq.empty()){

		set< set<int> >::iterator it,it1,it2;
		for(it = S.begin(); it != S.end(); it++){
			if(it->find(pq.top().x) != it->end()) it1 = it;
			if(it->find(pq.top().y) != it->end()) it2 = it;
		}

		if(it1 != it2){
			set<int> uni;
			set_union(it1->begin(), it1->end(), it2->begin(), it2->end(), inserter(uni, uni.begin()));
			S.insert(uni);
			S.erase(it1);
			S.erase(it2);

			E.push_back(pq.top());
			cost+=pq.top().cost;
		}
		pq.pop();

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





