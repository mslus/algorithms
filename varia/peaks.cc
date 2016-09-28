/*
 * peaks.cc
 *
 *  Created on: Sep 28, 2016
 *      Author: mslus
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void peaksandvalleys(vector<int> &A){
	sort(A.begin(), A.end());

	for(int i = 1; i < A.size()-1; i+=2)
		swap(A[i],A[i+1]);
}


int main(){

	vector<int> A({3,1,6,4,3,2,2,5,6,10,1});
	peaksandvalleys(A);
	for(int x : A) cout << x << " ";
	cout << endl;
	return 0;
}



