/*
 * manhattan.cc
 *
 *  Created on: Aug 27, 2016
 *      Author: maciek
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

struct CP {
	int x;
	int block;
	priority_queue<int> hpq;
	CP(int x1, int b) {
		x = x1;
		block = b;
	}
	CP(int x1, int b, priority_queue<int> h) {
		x = x1;
		block = b;
		hpq = h;
	}
};

bool operator<(const CP &c1, const CP &c2) {
	if (c1.x != c2.x)
		return c1.x < c2.x;
	else if (c1.block != c2.block)
		return c1.block < c2.block;
	else
		return false;
}

int main() {
	int n;
	int x1, x2, h;

	cin >> n;
	vector<CP> points;
	vector<int> H(n);
	vector<int> E(n);

	for (int i = 0; i < n; i++) {
		cin >> x1 >> x2 >> h;
		points.push_back(CP(x1, i));
		points.push_back(CP(x2, i));
		H[i] = h;
		E[i] = x2;
	}

	sort(points.begin(), points.end());

	set<int> s;
	vector<CP>::iterator it;
	set<int>::iterator its;
	for (it = points.begin(); it != points.end(); it++) {
		if (E[it->block] != it->x)
			s.insert(it->block);
		else
			s.erase(it->block);

		priority_queue<int> hpl;
		for (its = s.begin(); its != s.end(); its++)
			if (E[*its] != it->x)
				hpl.push(H[*its]);
		it->hpq = hpl;
	}

	vector<CP> contracted;

	int i = 0;
	int j, k;
	while (i < 2 * n) {
		priority_queue<int> pq;
		pq = points[i].hpq;
		j = i + 1;
		while (points[j].x == points[i].x) {
			while (!points[j].hpq.empty()) {
				k = points[j].hpq.top();
				points[j].hpq.pop();
				pq.push(k);
			}
			j++;
		}
		contracted.push_back(CP(points[i].x, points[i].block, pq));
		i = j;
	}

	int level = 0;
	int current;
	for (it = contracted.begin(); it != contracted.end(); it++) {
		if (!it->hpq.empty())
			current = it->hpq.top();
		else
			current = 0;
		if (current != level) {
			cout << it->x << "  " << level << endl;
			cout << it->x << "  " << current << endl;
			level = current;
		}
	}

	return 0;

}

