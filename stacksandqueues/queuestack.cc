/*
 * queuestack.cc
 *
 *  Created on: Sep 8, 2016
 *      Author: maciek
 */
#include <iostream>
#include <stack>

using namespace std;

template <class T>
class queueStack{
	stack<T> S;
	stack<T> Saux;

public:

	void push(T a){
		while(!S.empty()){
			Saux.push(S.top());
			S.pop();
		}
		S.push(a);
		while(!Saux.empty()){
			S.push(Saux.top());
			Saux.pop();
		}
	}

	T top(){
		return S.top();
	}

	bool empty(){
		return S.empty();
	}

	void pop(){
		S.pop();
	}

};

int main(){

	queueStack<int> qs;
	queueStack<string> qss;

	qs.push(1);
	qs.push(3);
	qs.push(5);
	qs.push(-1);

	while(!qs.empty()){
		cout << qs.top() << endl;
		qs.pop();
	}

	qss.push("aaabb");
	qss.push("ala");
	qss.push("ma");
	qss.push("kota");

	while(!qss.empty()){
		cout << qss.top() << endl;
		qss.pop();
	}
	return 0;
}



