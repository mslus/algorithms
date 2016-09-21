/*
 * changes.cc
 *
 *  Created on: Sep 21, 2016
 *      Author: mslus
 */
#include <iostream>
#include <vector>

using namespace std;

int calculateChange(int sum, vector<int> coins){
	if(sum == 1 || sum == 0 || coins.size() == 1) return 1;

	int maxcoin = coins[coins.size()-1];
	vector<int> newcoins;
	for(int i = 0; i < coins.size()-1; i++)
		newcoins.push_back(coins[i]);
	if(sum >= maxcoin)
		return calculateChange(sum, newcoins) + calculateChange(sum - maxcoin, coins);
	else
		return calculateChange(sum, newcoins);
}


int main(){

	vector<int> v({1,5,10,25});
	cout << calculateChange(3,v) << endl;
	cout << calculateChange(5,v) << endl;
	cout << calculateChange(6,v) << endl;
	cout << calculateChange(20,v) << endl; // (10,10), (5,5,5,5), (5,5,5,1..), (5,5,1..), (5,1..), (10,5,5), (10,5,1..), (10,1...), (1...)
	cout << calculateChange(25,v) << endl;
	cout << calculateChange(30,v) << endl;

	return 0;
}



