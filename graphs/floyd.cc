/*
 * floyd.cc
 *
 *  Created on: Sep 20, 2016
 *      Author: mslus
 */
#include <iostream>
#include <vector>

#define MAXINT 1E+9

using namespace std;


struct Graph{
	vector< vector<int> > D;

	Graph(int n){
		D.resize(n);
		for(int i = 0; i < n; i++)
			D[i].resize(n);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(i == j) D[i][j] = 0;
				else D[i][j] = MAXINT;
	}
};


void floyd(Graph &G){

	int n = G.D.size();

	for(int k = 0; k < n; k++)
		for(int i = 0; i < n ; i++)
			for(int j = 0; j < n ; j++)
				if(G.D[i][j] > (G.D[i][k] + G.D[k][j]))
					G.D[i][j] = G.D[i][k] + G.D[k][j];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cout << i << " " << j << " " << G.D[i][j] << endl;
}


int main(){

	int n,m;
	int x,y,z;
	cin >> n >> m;

	Graph G(n);
	for(int i = 0; i < m; i++){
		cin >> x >> y >> z;
		G.D[x][y] = z;
		G.D[y][x] = z;
	}

	floyd(G);

	return 0;

}




