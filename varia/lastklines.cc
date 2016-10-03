/*
 * lastklines.cc
 *
 *  Created on: Oct 1, 2016
 *      Author: maciek
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printklines(int k){
	vector<string> V(k);
	string s;
	int i = 0;

	while(!cin.eof()){
		getline(cin, s);
		V[i] = s;
		i = (i+1) % k;
	}

	for(int j = 0; j < k; j++){
		cout << V[i] << endl;
		i = (i+1) % k;
	}

}

int main(){
	printklines(20);
	return 0;
}



