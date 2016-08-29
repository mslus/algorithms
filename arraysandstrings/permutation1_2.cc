/*
 * permutation1_2.cc
 *
 *  Created on: Aug 28, 2016
 *      Author: maciek
 */
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool permutation(string s1,string s2){
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());

	if(s1 == s2)
		return true;
	return false;
}

bool permutation_nosort(string s1, string s2){
	vector<int> m(255,0);

	if(s1.length() != s2.length()) return false;

	for(char c : s1)
		m[c]++;

	for(char c : s2)
		m[c]--;

	for(int i = 0; i < m.size(); i++)
		if(m[i] != 0) return false;
	return true;
}

int main(){
	cout << permutation("abba","acab") << endl;
	cout << permutation_nosort("abba","acab") << endl;

	cout << permutation("abac","bcaa") << endl;
	cout << permutation_nosort("abac","bcaa") << endl;

	cout << permutation("","b") << endl;
	cout << permutation_nosort("","b") << endl;

	cout << permutation("zxcv","vcxz") << endl;
	cout << permutation_nosort("zxcv","vcxz") << endl;

	return 0;

}



