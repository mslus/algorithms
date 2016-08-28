/*
 * uniquechars_prim1.1.cc
 *
 *  Created on: Aug 28, 2016
 *      Author: maciek
 */
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


bool uniquechars(string s){

	//for reference only
	cout << s << " ";
	sort(s.begin(),s.end());

	for(int i = 0; i < s.length()-1; i++)
		if(s[i] == s[i+1])
			return false;

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










