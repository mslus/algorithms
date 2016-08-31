/*
 * substring1_9.cc
 *
 *  Created on: Aug 31, 2016
 *      Author: maciek
 */
#include <iostream>
#include <string>

using namespace std;

bool isRotated(string s,string s1){

	string ss = s1 + s1;
	if(ss.find(s) != string::npos)
		return true;
	else
		return false;
}

int main(){
	cout << isRotated("Rotated","tedRota") << endl;
	cout << isRotated("ABBA","ABAB") << endl;
	cout << isRotated("ABBA","BBAA") << endl;
	cout << isRotated("World","ldWor") << endl;
	cout << isRotated("ete","tet") << endl;

	return 0;
}



