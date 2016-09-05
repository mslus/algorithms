// Generic implementation od Dijkstra's shortest path algorithm
// Neighbour list used as as graph representation
#include <iostream>
#include <queue>
#include <vector>

#define INF 1E+9

using namespace std;

struct node {
	int n;
	int cost;
	node(int x, int y) {
		n = x;
		cost = y;
	}
};

bool operator<(const node &n1, const node &n2) {
	if (n1.cost != n2.cost)
		return n1.cost > n2.cost;
	else if (n1.n != n2.n)
		return n1.n > n2.n;
	else
		return false;
}

vector<int> dijkstra(int start, const vector<vector<pair<int, int> > > &nb) {

	priority_queue<node> pq;
	vector<bool> visited(nb.size(), false);
	vector<int> result(nb.size(), INF);

	pq.push(node(start, 0));

	while (!pq.empty()) {
		node nd = pq.top();
		pq.pop();

		if (!visited[nd.n]) {
			result[nd.n] = nd.cost;
			visited[nd.n] = true;
		}

		for (vector<pair<int, int> >::const_iterator it = nb[nd.n].begin();
				it != nb[nd.n].end(); it++)
			if (!visited[it->first])
				pq.push(node(it->first, nd.cost + it->second));
	}

	return result;
}

int main() {

	int n, k;
	int x, y, cost;
	cin >> n >> k;
	vector < vector<pair<int, int> > > nb(n);

	for (int i = 0; i < k; i++) {
		cin >> x >> y >> cost;
		nb[x].push_back(pair<int, int>(y, cost));
	}

	vector<int> r = dijkstra(0, nb);
	for (int i = 0; i < n; i++)
		if (r[i] < INF)
			cout << i << " " << r[i] << endl;
		else
			cout << i << " " << "INF" << endl;

	return 0;
}

