/*
 * steps.cc
 *
 *  Created on: Sep 21, 2016
 *      Author: mslus
 */
#include <iostream>
#include <vector>

using namespace std;

int calculateSteps(int n){
	vector<int> T(n+1,0);

	T[0] = 1;

	for(int i = 2; i <= n ; i++){
		if(i > 0)
			T[i]+=T[i-1];
		if(i > 1)
			T[i]+=T[i-2];
		if(i > 2)
			T[i]+=T[i-3];
	}

	return T[n];
}


int main(){

	cout << 5 << " " << calculateSteps(5) << endl;
	cout << 10 << " " << calculateSteps(10) << endl;
	cout << 15 << " " << calculateSteps(15) << endl;
	cout << 20 << " " << calculateSteps(20) << endl;
	cout << 100 << " " << calculateSteps(100) << endl;
	return 0;
}


