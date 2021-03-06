// Generic implementation of DFS on graph represented by neighbouring lists
// Graph edges and not weigted
// Graph is undirected - edges go from x->y and y->x
// For now it does not do anything other then printing visited vertices 
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int start, const vector<vector<int> > &nb) {

	vector<bool> visited(nb.size(), false);
	stack<int> st;

	st.push(start);
	while (!st.empty()) {
		int node = st.top();
		st.pop();

		if (!visited[node]) {
			cout << node << endl;
			for (vector<int>::const_iterator it = nb[node].begin();
					it != nb[node].end(); it++)
				st.push(*it);
		}
		visited[node] = true;
	}
}

void dfs_rec(int start, const vector<vector<int> > &nb, vector<bool> &visited) {
	if (!visited[start]) {
		cout << start << endl;
		visited[start] = true;
		for (vector<int>::const_iterator it = nb[start].begin();
				it != nb[start].end(); it++)
			dfs_rec(*it, nb, visited);
	}
}

int main() {
	int n, k;
	int x, y;

	cin >> n >> k;
	vector < vector<int> > nb(n);

	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		nb[x].push_back(y);
		nb[y].push_back(x);
	}

	cout << "stack based: " << endl;
	dfs(0, nb);
	cout << "recursive:" << endl;
	vector<bool> visited(nb.size(), false);
	dfs_rec(0, nb, visited);

	return 0;
}
