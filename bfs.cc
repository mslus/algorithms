// Generic implementation of BFS on graph represented by neighbouring lists
// Graph edges and not weigted
// Graph is undirected - edges go from x->y and y->x
// For now it does not do anything other then printing visited vertices 
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int start, const vector<vector<int> > &nb) {

	vector<bool> visited(nb.size(), false);
	queue<int> st;

	st.push(start);
	visited[start] = true;

	while (!st.empty()) {
		int node = st.front();
		st.pop();

		cout << node << endl;

		for (vector<int>::const_iterator it = nb[node].begin();
				it != nb[node].end(); it++) {
			if (!visited[*it]) {
				st.push(*it);
				visited[*it] = true;
			}
		}
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

	bfs(0, nb);

	return 0;
}
