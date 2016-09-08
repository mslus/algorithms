/*
 * dualstack.cc
 *
 *  Created on: Sep 8, 2016
 *      Author: maciek
 */
#include <iostream>
#include <stack>

using namespace std;

class dualStack{
	stack<int> S;
	stack<int> Smin;

public:
	void push(int x){
		S.push(x);
		if(Smin.empty()){
			Smin.push(x);
			return;
		}
		if(x < Smin.top())
			Smin.push(x);
		else
			Smin.push(Smin.top());
	}

	int top(){
		return S.top();
	}

	bool isempty(){
		return S.empty();
	}

	int min(){
		return Smin.top();
	}

	void pop(){
		S.pop();
		Smin.pop();
	}

};

int main(){

	dualStack ds;

	ds.push(5);
	ds.push(3);
	ds.push(6);
	ds.push(2);
	ds.push(4);


	while(!ds.isempty()){
		cout << ds.top() << "  " << ds.min() << endl;
		ds.pop();
	}

	return 0;
}



