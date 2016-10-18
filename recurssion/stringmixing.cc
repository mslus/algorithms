/*
 * stringmixing.cc
 *
 *  Created on: Oct 17, 2016
 *      Author: mslus
 */
#include <string>
#include <vector>
#include <iostream>

using namespace std;


vector<string> mixings(string s1, string s2){

	vector<string> res;

	if(s1.length() == 0){
		res.push_back(s2);
		return res;
	}else if(s2.length() == 0){
		res.push_back(s1);
		return res;
	}else if(s1.length() == 0 && s2.length() == 0){
		return res;
	}

	vector<string> r1 = mixings(s1.substr(1,s1.length()-1),s2);
	vector<string> r2 = mixings(s1,s2.substr(1,s2.length()-1));

	for(string s : r1) res.push_back(s1.substr(0,1) + s);
	for(string s : r2) res.push_back(s2.substr(0,1) + s);

	return res;


}

int main(){

	vector<string> R = mixings("abcde","123456");

	for(string s : R) cout << s << endl;

}



