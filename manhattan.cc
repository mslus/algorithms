/*
 * manhattan.cc
 *
 *  Created on: Aug 27, 2016
 *      Author: maciek
 */
#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

struct CP{
	int x;
	int block;
	bool isLeft;
	CP(int x1,int b, bool left){
		x = x1;
		block = b;
		isLeft = left;
	}
};

bool operator<(const CP &c1, const CP &c2){
	if(c1.x != c2.x) return c1.x < c2.x;
	else if(c1.block != c2.block) return c1.block < c2.block;
	else return false;
}

int main(){
	int n;
	int x1,x2,h;

	cin >> n;
	vector<CP> points;
    vector<int> H(n);

	for(int i = 0; i < n; i++){
		cin >> x1 >> x2 >> h;
		points.push_back(CP(x1,i,true));
		points.push_back(CP(x2,i,false));
		H[i] = h;
	}

	sort(points.begin(),points.end());


}


