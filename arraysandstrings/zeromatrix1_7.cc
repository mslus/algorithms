/*
 * zeromatrix1_7.cc
 *
 *  Created on: Aug 30, 2016
 *      Author: maciek
 */
#include <iostream>
#include <vector>
#include <set>

using namespace std;

void zero(vector<vector<int> > &matrix) {

	set<int> rows;
	set<int> columns;

	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < matrix[0].size(); j++)
			if (matrix[i][j] == 0) {
				rows.insert(i);
				columns.insert(j);
			}

	for (set<int>::iterator it = rows.begin(); it != rows.end(); it++)
		for (int j = 0; j < matrix[0].size(); j++)
			matrix[*it][j] = 0;

	for (set<int>::iterator it = columns.begin(); it != columns.end(); it++)
		for (int i = 0; i < matrix.size(); i++)
			matrix[i][*it] = 0;
}

int main() {

	vector < vector<int> > m(5, vector<int>(5));
	m[0][0] = 1;
	m[1][0] = 0;
	m[2][0] = 1;
	m[3][0] = 1;
	m[4][0] = 3;
	m[0][1] = 1;
	m[1][1] = 1;
	m[2][1] = 9;
	m[3][1] = 1;
	m[4][1] = 1;
	m[0][2] = 3;
	m[1][2] = 1;
	m[2][2] = 1;
	m[3][2] = 1;
	m[4][2] = 1;
	m[0][3] = 4;
	m[1][3] = 1;
	m[2][3] = 1;
	m[3][3] = 0;
	m[4][3] = 1;
	m[0][4] = 3;
	m[1][4] = 1;
	m[2][4] = 1;
	m[3][4] = 2;
	m[4][4] = 1;

	zero (m);
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m[0].size(); j++)
			cout << m[i][j] << " ";
		cout << endl;
	}

}

