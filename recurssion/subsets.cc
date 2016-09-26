/*
 * subsets.cc
 *
 *  Created on: Sep 26, 2016
 *      Author: mslus
 */
#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

set< set<int> > generatesubsets(set<int> &S){

	//for(int x : S) cout << x << " ";
	//cout << endl;

	set< set<int> > result;
	if(S.size() == 1){
		set<int> s1 = S;
		result.insert(s1);
		return result;
	}

	for(int x : S){
		set<int> S_small = S;
		S_small.erase(x);
		set< set<int> > subp = generatesubsets(S_small);
		set< set<int> >::iterator it;
		for(it = subp.begin(); it != subp.end(); it++){
			set<int> s1 = *it;
			result.insert(s1);
			s1.insert(x);
			result.insert(s1);
		}
	}

	return result;
}

//for fun - the same with bitmask
set< set<int> > generatesubsets_bitmask(vector<int> &S){

	set< set<int> > result;
	int mask = (1 << S.size()) - 1;

	for(int i = 1; i < mask; i++){
		set<int> s1;
		for(int k = 0; k < S.size(); k++){
			if((i >> k) & 1 == 1) s1.insert(S[k]);
		}
		/*for(int x : s1) cout << x << " ";
		cout << endl;*/
		result.insert(s1);
	}

	return result;

}


int main(){

	vector<int> V({1,2,4,10});
	set<int> S(V.begin(), V.end());

	set< set<int> > SS = generatesubsets(S);

	for(set<int> si : SS){
		for(int i : si)
			cout << i << " ";
		cout << endl;
	}


	cout << endl;
	set< set<int> > SSS = generatesubsets_bitmask(V);


	for(set<int> si : SSS){
		for(int i : si)
			cout << i << " ";
		cout << endl;
	}

	return 0;
}



