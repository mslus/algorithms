/*
 * factorymethod.cc
 *
 *  Created on: Sep 30, 2016
 *      Author: mslus
 */
#include <iostream>
#include <string>

using namespace std;


class BaseProduct{
public:
	virtual void getMessage(string s) = 0;
	virtual ~BaseProduct(){}
};

class ChildProduct1: public BaseProduct{
public:
	void getMessage(string s){
		cout << "Child 1 " << s << endl;
 	}
};

class ChildProduct2: public BaseProduct{
public:
	void getMessage(string s){
		cout << "Child 2 " << s << endl;
 	}
};

class Producer{
public:
	virtual BaseProduct* getProduct() = 0;
	virtual ~Producer(){}
};


class Producer1: public Producer{
public:
	BaseProduct* getProduct(){
		return new ChildProduct1();
	}
};


class Producer2: public Producer{
public:
	BaseProduct* getProduct(){
		return new ChildProduct2();
	}
};



int main(){
	Producer * p1 = new Producer1();
	Producer * p2 = new Producer2();

	p1->getProduct()->getMessage("p1");
	p2->getProduct()->getMessage("p2");

	return 0;
}
