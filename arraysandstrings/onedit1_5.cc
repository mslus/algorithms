/*
 * onedit1_5.cc
 *
 *  Created on: Aug 28, 2016
 *      Author: maciek
 */
#include <string>
#include <iostream>


using namespace std;

bool oneaway(string s1, string s2){

	//for debug only
	cout << s1 << " " << s2 << " ";

	if(abs((int) (s1.length()-s2.length())) > 1) return false;

	bool flag = false;
	int i = 0;
	int j = 0;
	while(i < s1.length() && j < s1.length()){
		if(s1[i] != s2[j]){
			if(flag) return false;
			else{
				flag = true;
				if((s1.length() > s2.length()) && (s2[j] == s1[i+1]))
					i++;
				else if((s2.length() > s1.length()) && (s1[i] == s2[j+1]))
					j++;
				else if ((s1.length() == s2.length()) && (s1[i+1] == s2[j+1])){
					i++; j++;
				}else{
					return false;
				}
			}
		}else{
			i++; j++;
		}
	}
	return true;
}

int main(){
	cout << oneaway("pale","ple") << endl;
	cout << oneaway("pales","pale") << endl;
	cout << oneaway("pale","ple") << endl;
	cout << oneaway("pale","bale") << endl;
	cout << oneaway("pale","bake") << endl;
	cout << oneaway("bacabaca","bacabca") << endl;
	cout << oneaway("b","a") << endl;
	cout << oneaway("","a") << endl;
	cout << oneaway("asdfgh","aaaaaaaaaaaaa") << endl;

	return 0;


}



