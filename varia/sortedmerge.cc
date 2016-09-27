/*
 * sortedmerge.cc
 *
 *  Created on: Sep 27, 2016
 *      Author: maciek
 */
#include <iostream>
#include <vector>
using namespace std;


void sortmerge(vector<int> &A, vector<int> &B){
	for(int i = A.size()-1; i >= (A.size()-B.size()-1	); i-- )
		A[i] = A[i-(A.size()-B.size()-1	)];


	int i = B.size(); int j = 0;
	int k = 0;
	for(;;){
		if(A[i] < B[j]){
			A[k] = A[i];
			i++;
		}else{
			A[k]=B[j];
			j++;
		}
		k++;
		if((i == A.size()) || (j == B.size())) break;
	}
}

int main(){
	vector<int> B({2,4,6,7,8,12});
	vector<int> A(13);
	A[0] = 1;
	A[1] = 3;
	A[2] = 7;
	A[3] = 8;
	A[4] = 9;
	A[5] = 10;
	A[6] = 21;

	sortmerge(A,B);

	for(int x : A) cout << x << " ";
	cout << endl;

}



