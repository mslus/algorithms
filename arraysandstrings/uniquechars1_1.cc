/*
 * uniquechars1.1.cc
 *
 *  Created on: Aug 28, 2016
 *      Author: maciek
 */
#include <string>
#include <vector>
#include <iostream>

using namespace std;


bool uniquechars(string s){
	vector<bool> m(255,false);

	//for reference only
	cout << s << " ";

	for(char c : s){
		if(m[c])
			return false;
		else
			m[c] = true;
	}

	return true;
}

int main(){
	cout <<  uniquechars("abcdfrga") << endl;
	cout <<  uniquechars("abcdefghty") << endl;
	cout <<  uniquechars("aaaaaa") << endl;
	cout <<  uniquechars("") << endl;
	cout <<  uniquechars("abcabc") << endl;
	cout <<  uniquechars("zxcvbnmlkjhgfdsA") << endl;
	cout <<  uniquechars("ABCDEFG") << endl;

	return 0;
}





