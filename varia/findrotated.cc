/*
 * findrotated.cc
 *
 *  Created on: Sep 25, 2016
 *      Author: mslus
 */
#include <iostream>
#include <vector>

using namespace std;


int findrotated(const vector<int> &tab, int x){

	int low = 0;
	int high = tab.size()-1;
	int mid;

	while(low <= high){
		mid = (high+low)/2;
		if(tab[low] <= x && tab[mid] > x){
			high = mid-1;
		}else if(tab[mid] < x && tab[high] >= x){
			low = mid+1;
		}else if(tab[low] >= x && tab[mid] > x && tab[low] > tab[mid]){
			high = mid-1;
		}else if(tab[mid] > x && tab[high] >= x && tab[mid] > tab[high]){
			low = mid+1;
		}else if(tab[low] <= x && tab[mid] < x && tab[low] > tab[mid]){
			high = mid-1;
		}else if(tab[mid] < x && tab[high] <= x && tab[mid] > tab[high]){
			low = mid+1;
		}else if(tab[mid] == x){
			return mid;
		}
	}

	return -1;

}



int main(){

	vector<int> v1({10,12,15,2,5,6,8,9});
	vector<int> v2({9,10,12,15,2,5,6,8});
	vector<int> v3({8,9,10,12,15,2,5,6});
	vector<int> v4({6,8,9,10,12,15,2,5});
	vector<int> v5({12,15,2,5,6,8,9,10});
	vector<int> v6({15,2,5,6,8,9,10,12});
	vector<int> v7({2,5,6,8,9,10,12,15});

	cout << findrotated(v1,12) << endl;
	cout << findrotated(v2,12) << endl;
	cout << findrotated(v3,12) << endl;
	cout << findrotated(v4,12) << endl;
	cout << findrotated(v5,12) << endl;
	cout << findrotated(v6,12) << endl;
	cout << findrotated(v7,12) << endl;

	return 0;
}



