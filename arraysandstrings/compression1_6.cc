/*
 * compression1_6.cc
 *
 *  Created on: Aug 30, 2016
 *      Author: maciek
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string compress(string s) {
	int i = 0;
	int k;
	string result;
	stringstream ss;

	while (i < s.length()) {
		k = i;
		while (s[k] == s[i])
			k++;
		ss << s[i] << (k - i);
		i = k;
	}

	result = ss.str();

	if (result.length() < s.length())
		return result;
	else
		return s;
}

int main() {

	cout << compress("aabccccaddd") << endl;
	cout << compress("aabccZZZdd") << endl;
	cout << compress("abcd") << endl;
	cout << compress("zxxcss") << endl;
	cout << compress("aabccccaaaaaBBBbbb") << endl;

	return 0;
}

