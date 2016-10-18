/*
 * mindifference.cc
 *
 *  Created on: Oct 18, 2016
 *      Author: mslus
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int mindiff(vector<int> &v1, vector<int> &v2){

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int i = 0;
	int j = 0;
	bool first;
	int last = v2[0];
	int mindf = abs(v1[0] - v2[0]);

	while(i < v1.size() && j < v2.size()){
		if(v1[i] <= v2[j]){
			if(!first && abs(v1[i] - last) < mindf) mindf = abs(v1[i] - last);
			last = v1[i];
			first = true;
			i++;
		}else{
			if(first && abs(v2[j] - last) < mindf) mindf = abs(v2[j] - last);
			last = v2[j];
			first = false;
			j++;
		}
	}

	if(i == v1.size() && first && abs(v2[j] - last) < mindf) mindf = abs(v2[j] - last);
	if(j == v2.size() && !first && abs(v1[i] - last) < mindf) mindf = abs(v1[i] - last);

	return mindf;
}


int main(){

	vector<int> v1({1,4,6,2,7,10,55});
	vector<int> v2({16,15,18,53,22});

	cout << mindiff(v1,v2) << endl;

	return 0;
}



