/*
 * multiply.cc
 *
 *  Created on: Sep 21, 2016
 *      Author: mslus
 */
#include <iostream>

using namespace std;



int multiply(int a, int b){
	if(a == 1) return b;
	if(b == 1) return a;

	if(a <= b)
		return b + multiply(a-1,b);
	else
		return a + multiply(a, b-1);
}

int main(){

	cout << multiply(9,9) << endl;
	cout << multiply(2,40) << endl;
	cout << multiply(25,5) << endl;

	return 0;
}



