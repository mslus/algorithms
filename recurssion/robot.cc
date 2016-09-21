/*
 * robot.cc
 *
 *  Created on: Sep 21, 2016
 *      Author: mslus
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector< pair<int, int> > findPath(vector <vector<int> > &maze){

	bool flag = true;
	for(int i = 0; i < maze[0].size(); i++)
		if(maze[0][i] == 0 || !flag){
			flag = false;
			maze[0][i] = 0;
		}

	for(int i = 1; i < maze.size(); i++)
		for(int j = 0; j < maze[i].size(); j++){
			if(maze[i][j] == 0) continue;
			if(j > 0 && maze[i][j-1] > 0)
				maze[i][j] = 1;
			else if(maze[i-1][j] > 0)
				maze[i][j] = 2;
			else
				maze[i][j] = 0;
		}

    vector< pair<int, int> > result(0);
    if(maze[maze.size()-1][maze[0].size()-1] == 0) return result;
	stack< pair<int,int> > S;
	int i = maze.size()-1;
	int j = maze[0].size()-1;
	while(i+j > 0){
		S.push( pair<int,int>(i,j) );
		if(maze[i][j] == 1)
			j--;
		else if(maze[i][j] == 2)
			i--;
	}
	S.push( pair<int,int>(i,j) );

	while(!S.empty()){
		pair<int,int> p = S.top();
		S.pop();
		result.push_back(p);
		maze[p.first][p.second] = 9;
	}

	return result;
}


int main(){
	int n,m;
	int x;
	cin >> n >> m;

	vector< vector< int > > maze(n, vector<int>(m));

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> maze[i][j];

	vector< pair<int, int> > solution = findPath(maze);

	cout << "Computed path: " << endl;
	for(int i = 0; i < solution.size(); i++)
		cout << solution[i].first << " " << solution[i].second << endl;
	cout << endl;

	for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << maze[i][j] << " ";
			cout << endl;
	}



	return 0;

}


