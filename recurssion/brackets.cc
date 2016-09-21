/*
 * brackets.cc
 *
 *  Created on: Sep 21, 2016
 *      Author: mslus
 */
#include <iostream>
#include <string>
#include <set>

using namespace std;


set<string> brackets(int n){

	set<string> result;

	if(n == 1){
		result.insert("()");
		return result;
	}


	set<string> subproblem = brackets(n-1);

	set<string>::iterator it;
	for(it = subproblem.begin(); it != subproblem.end(); it++){
		for(int i = 0; i <= it->length(); i++)
			for(int j = i; j <= it->length(); j++){
				int b = 0;
				bool ok = true;
				for(int k = i; k < j; k++){
					if(it->at(k) == '(')
						b++;
					if(it->at(k) == ')')
						b--;
					if(b < 0){
						ok = false;
						break;
					}
				}
				if(b != 0) ok = false;
				string s = *it;
				if(ok) result.insert(s.insert(i,"(").insert(j+1,")"));
			}
	}

	return result;
}



int main(){

	set<string> s = brackets(5);

	set<string>::iterator it;
	for(it = s.begin(); it != s.end(); it++)
		cout << *it << endl;

	return 0;
}




