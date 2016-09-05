/*
 * palindromepermut1_3.cc
 *
 *  Created on: Aug 28, 2016
 *      Author: maciek
 */
#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool ispalindrome(string s) {
	vector<int> m(256, 0);

	for (int i = 0; i < s.length(); i++)
		m[s[i]]++;

	bool flag = false;
	for (int i = 0; i < m.size(); i++)
		if (m[i] % 2 != 0) {
			if (!flag)
				flag = true;
			else
				return false;
		}
	return true;
}

int main() {

	cout << ispalindrome("abab") << endl;
	cout << ispalindrome("ababc") << endl;
	cout << ispalindrome("abaaba") << endl;
	cout << ispalindrome("ababcc") << endl;
	cout << ispalindrome("abbe") << endl;
	cout << ispalindrome("abcdefg") << endl;

	return 0;
}

