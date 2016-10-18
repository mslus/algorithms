/*
 * longestgrowing.cc
 *
 *  Created on: Oct 18, 2016
 *      Author: mslus
 */
#include <iostream>
#include <vector>

using namespace std;


int longestsequence(const vector<int> &T, int &a, int &b){
	int sum = 0;
	int maxsum = 0;
	int j = 0;

	for(int i = 0; i < T.size(); i++ ){
		sum += T[i];
		j++;
		if(sum < 0){
			sum = 0;
			j = 0;
		}
		if(sum > maxsum){
			maxsum = sum;
			b = i;
			a = i - j + 1;
		}
	}

	return maxsum;
}


int main(){

	vector<int> T({-1,2,-2,4,6,-1,2});
	int a,b;

	cout << longestsequence(T,a,b) << endl;
	cout << a << "  " << b << endl;

	return 0;
}



