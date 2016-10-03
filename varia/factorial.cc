/*
 * factorial.cc
 *
 *  Created on: Oct 3, 2016
 *      Author: maciek
 */
#include <iostream>

using namespace std;

unsigned long long f(unsigned long long n){
	if(n == 1)
		return 1;
	else
		return n*f(n-1);
}


int fzeros(int n){

	if(n <= 9) return 0;
	int count = 0;
	for(int i = 5; i <= n; i+=5){
		int k = i;
		while(k % 5  == 0) {  k = k/5; count++; }
	}

	return count;

}

int main(){

	cout << f(20) << " " << fzeros(20) <<  endl;
	return 0;
}



