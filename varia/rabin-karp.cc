/*
 * rabin-karp.cc
 *
 *  Created on: Sep 21, 2016
 *      Author: mslus
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Hashing{
	static const long long  M = 3779;
	long long alphabet_size;

public:
	Hashing(int n){
		alphabet_size = n;
	}

	long computeHash(string s){
		long long hash = 0;
		for(char c : s){
			hash = ((c - 'a') + hash*alphabet_size) % M;
		}

		return hash;
	}

	int substringMatch(string s, string pattern){

		long long hash = computeHash(s.substr(0,pattern.length()));
		long long patternhash = computeHash(pattern);
		long long n_power = 1;
		for(int i = 0; i < pattern.length()-1; i++)
			n_power*=alphabet_size;
		n_power = n_power % M;
		for(int i = 1; i <= s.length() - pattern.length(); i++){
			hash = ((hash - (n_power*(s.at(i-1) - 'a'))%M)*alphabet_size + (s.at(i+pattern.length()-1) - 'a')) % M;
			hash = (hash + M) % M;
			if(hash == patternhash){
				bool identical = true;
				for(int j = 0; j < pattern.length(); j++)
					if(s.at(i+j) != pattern.at(j)){
						identical = false;
						break;
					}
				if(identical) return i;
			}
		}
		return -1;
	}

};




int main(){

	Hashing h('z' - 'a' + 1);

	cout << h.substringMatch("abahlaasacxdfdgdfg", "aas") << endl;
	cout << h.substringMatch("abahlaasacxdfdgdfg", "sacxdfdgdfg") << endl;
	cout << h.substringMatch("abahlaasacxdfdgdfg", "gdf") << endl;
	cout << h.substringMatch("abahlaasacxdfdgdfg", "zzz") << endl;

	return 0;
}




