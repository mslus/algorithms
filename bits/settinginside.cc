/*
 * settinginside.cc
 *
 *  Created on: Sep 18, 2016
 *      Author: maciek
 */
#include <iostream>

using namespace std;

int setBits(int N, int M, int i, int j){

	int mask = ~(((1 << (j-i+1)) - 1) << i);
	return (mask & N)  | (M << i);
}

int longestSequence(int x){
	int current = 0;
	int previous = 0;
	int maximum = 1;

	while(x > 0){
		if((x & 1) == 1)
			current++;
		if((x & 1) == 0){
			previous = ((x & 2) == 0 ? 0 : current);
			current = 0;
		}
		maximum = max(previous + current + 1, maximum);
		x >>= 1;
	}

	return maximum;
}

int nextSmallest(int x){

	int temp = x;
	int i = 0;
	while((x & 1) == 0){
		x >>= 1;
		i++;
	}
	while((x & 1) != 0){
		x >>= 1;
		i++;
	}

	return (temp | (1 << i)) & ~(1 << (i-1));
}

int nextBiggest(int x){
	int temp = 0;
	int count = 0;
	while(x != 0){
		if((x & 1) == 1) count++;
		x >>= 1;
	}

	for(int i = 0; i < count; i++)
		temp = temp | (1 << (30-i));
	return temp;
}

int conversion(int x, int y){
	int temp = x ^ y;
	int count = 0;

	while(temp != 0){
		if((temp & 1) != 0) count++;
		temp >>= 1;
	}

	return count;
}

int main(){
	cout << setBits(1024, 19, 2, 6) << endl;
	cout << longestSequence(1248) << endl;

	cout << "1248 " << nextSmallest(1248) << " " << nextBiggest(1248) << endl;
	cout << "567 " << nextSmallest(567) << " " << nextBiggest(567) << endl;
	cout << "2345678 " << nextSmallest(2345678) << " " << nextBiggest(2345678) << endl;

	cout << conversion(29,15) << endl;

	return 0;
}



