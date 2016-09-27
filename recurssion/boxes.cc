/*
 * boxes.cc
 *
 *  Created on: Sep 27, 2016
 *      Author: mslus
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct box{
	int width;
	int depth;
	int heigth;
	box(int x, int y, int z){width = x; depth = y; heigth = z;}
};


bool operator<(const box &b1, const box &b2){
	if(b1.heigth != b2.heigth) return b1.heigth < b2.heigth;
	else if(b1.width != b2.width) return b1.width < b2.width;
	else if(b1.depth != b2.depth) return b1.depth < b2.depth;
	else return false;
}

int findmaxheigth(vector<box> &B){

	sort(B.rbegin(), B.rend());
	vector<int> H(B.size(), 0);
	H[0] = B[0].heigth;


	for(int i = 1; i < B.size(); i++)
		for(int j = 0; j < i; j++)
			if(H[j] >= H[i] && B[i].width < B[j].width && B[i].depth < B[j].depth)
				H[i] = H[j]+B[i].heigth;


	int maximum = 0;
	for(int x : H)
		if(x > maximum) maximum = x;

	return maximum;
}


int main(){

	int n;
	int x,y,z;
	cin >> n;
	vector<box> B;
	for(int i = 0; i < n; i++){
		cin >> x >> y >> z;
		B.push_back(box(x,y,z));
	}

	cout << findmaxheigth(B) << endl;
	return 0;
}



