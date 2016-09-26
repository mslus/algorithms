/*
 * permutations.cc
 *
 *  Created on: Sep 26, 2016
 *      Author: mslus
 */
#include <iostream>
#include <set>
#include <vector>
#include <string>


using namespace std;

vector<string> generatepermutations(string s){

	vector<string> result;
	if(s.length() == 1){
		result.push_back(s);
		return result;
	}

	string ss = s;
	ss.erase(s.length()-1,1);
	vector<string> subp = generatepermutations(ss);
	for( string s1 : subp){
		for(int j = 0; j <= s1.length(); j++){
			string s2 = s1;
			result.push_back(s2.insert(j,s.substr(s.length()-1,1)));
		}
	}

	return result;
}

set<string> generatepermutations_2(string s){

	set<string> result;
	if(s.length() == 1){
		result.insert(s);
		return result;
	}

	string ss = s;
	ss.erase(s.length()-1,1);
	set<string> subp = generatepermutations_2(ss);
	for( string s1 : subp){
		for(int j = 0; j <= s1.length(); j++){
			string s2 = s1;
			result.insert(s2.insert(j,s.substr(s.length()-1,1)));
		}
	}

	return result;
}


int main(){

	vector<string> V = generatepermutations("abc");
	for(string s : V) cout << s << endl;


	cout << endl;
	set<string> SE = generatepermutations_2("aba");
	for(string s : SE) cout << s << endl;


	return 0;
}



