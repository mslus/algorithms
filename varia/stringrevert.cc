/*
 * stringrevert.cc
 *
 *  Created on: Oct 1, 2016
 *      Author: maciek
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void revert(char* s){

	int k = 0;
	while(s[k] != 0) k++;

	int j = 0;
	char c;
	while(j < k/2){
		c = s[j];
		s[j] = s[k-j-1];
		s[k-j-1] = c;
		j++;
	}
}

int main(){
	char s[12] = "Ala ma kota";
	revert(s);
	cout << s << endl;
	return 0;
}


