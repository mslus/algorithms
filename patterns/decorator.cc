/*
 * decorator.cc
 *
 *  Created on: Sep 30, 2016
 *      Author: mslus
 */
#include <iostream>
#include <string>

using namespace std;

class BaseClass{
public:
	virtual void action(string s) = 0;
	virtual ~BaseClass(){}
};

class BaseDecorator : public BaseClass{
	BaseClass *_bc;

public:
	BaseDecorator(BaseClass *bc) : _bc(bc){}
	void action(string s){
		_bc->action(s);
	}
	~BaseDecorator(){}
};


class Decorator1 : public BaseDecorator{

public:
	Decorator1(BaseClass *bc): BaseDecorator(bc){}
	void action(string s){
		BaseDecorator::action(s);
		cout << "Decorator1 " << s << " " << endl;
	}

};


class Decorator2 : public BaseDecorator{
public:
	Decorator2(BaseClass *bc): BaseDecorator(bc){}
	void action(string s){
		BaseDecorator::action(s);
		cout << "Decorator2 " << s << " " << endl;
	}

};


class ConcreteClass : public BaseClass{

public:
	void action(string s){
		cout << "Concrete " << s << " " << endl;
	}
};


int main(){

	ConcreteClass *cc = new ConcreteClass();
	Decorator1 *dc1 = new Decorator1(cc);
	Decorator2 *dc2 = new Decorator2(new Decorator1(new ConcreteClass()));

	cc->action("cc");
	dc1->action("dc1");
	dc2->action("dc2");


	return 0;
}





