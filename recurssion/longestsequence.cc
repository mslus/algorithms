/*
 * longestsequence.cc
 *
 *  Created on: Sep 25, 2016
 *      Author: mslus
 */
#include <iostream>
#include <vector>

using namespace std;



int longestsequence(const vector<int> &tab){

	vector<int> seq(tab.size(),1);

	for(int i = 1; i < seq.size(); i++)
		for(int j = 0; j<i; j++ )
			if(seq[j] >= seq[i] && tab[i] > tab[j])
				seq[i] = seq[j]+1;

	int longest = 1;
	for(int i = 0; i < tab.size(); i++){
		if(seq[i] > longest) longest = seq[i];
	}

	return longest;
}

int main(){

	vector<int> A({1,5,3,2,6,1,8,10,23});

	cout << longestsequence(A) << endl;
}



