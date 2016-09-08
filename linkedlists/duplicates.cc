/*
 * duplicates.cc
 *
 *  Created on: Sep 4, 2016
 *      Author: maciek
 */
#include <iostream>

using namespace std;

class node{
public:
	int info;
	node *next;
};

class linkedlist{
public:
	node *head;
	linkedlist(){
		head = nullptr;
	}

	void add(int x){
		node *n = new node();
		n->info = x;
		n->next = head;
		head = n;
	}

	void remove(int x){
		node *n;
		node *m;
		if(head == nullptr) return;
		while(head->info == x){
			m = head;
			head = head->next;
			delete m;
		}
		n = head;
		while(n->next != nullptr){
			if(n->next->info == x){
				m = n->next;
				n->next = n->next->next;
				delete m;
			}else{
				n = n->next;
			}
		}
	}

	void print(){
		node *n = head;
		while(n != nullptr){
			cout << n->info << " --> " ;
			n = n->next;
		}
		cout << "NULL" << endl;

	}
};




void removeduplicates(linkedlist &l){
	node *n = l.head;
	node *m, *o;
	while(n != nullptr){
		m = n;
		while(m->next != nullptr){
			if(m->next->info == n->info){
				o = m->next;
				m->next = m->next->next;
				delete o;
			}else{
				m = m->next;
			}
		}
		n = n->next;
	}
}

node* ktolast(linkedlist &l, int k){
	node *n = l.head;
	node *m = l.head;
	int i = 0;
	while(n != nullptr){
		if(i >= k) m = m->next;
		n = n->next;
		i++;
	}

	return m;
}

void deletemiddle(node *n){
	node *m = n->next;
	n->info = n->next->info;
	n->next = n->next->next;
	delete m;
}

void partition(linkedlist &l, int x){
	node *n = l.head;
	node *m;
	while(n->next != nullptr){
		if(n->next->info <= x){
			m = n->next;
			n->next = n->next->next;
			m->next = l.head;
			l.head = m;
		}else{
			n = n->next;
		}
	}
}

void revert(linkedlist &l){
	linkedlist ret;
	node *prev = nullptr;
	node *curr = l.head;
	node *m;
	while(curr != nullptr){
		m = curr->next;
		curr->next = prev;
		prev = curr;
		curr = m;
	}
	l.head = prev;
}

node* findintersection(linkedlist &l1, linkedlist &l2){

	node *n1;
	node *n2;
	node *m = nullptr;
	int i = 1;
	while(true){
		n1 = ktolast(l1,i);
		n2 = ktolast(l2,i);
		if(n1 == n2) m = n1;
		else if((n1 != n2) && (m == nullptr))
			return nullptr;
		else if((n1 != n2) && (m != nullptr))
			return m;
		i++;
	}
}

node* findcycle(linkedlist &l){
	node *r1 = l.head;
	node *r2 = l.head->next;
	while(r1 != r2){
		r1 = r1->next;
		r2 = r2->next->next;
	}

	cout << r1->info << endl;

	r2 = l.head;
	node *n;
	while(true){
		n = r1;
		do{
			if(n == r2) return n;
			n = n->next;
		}while(n != r1);
		r2 = r2->next;
	}

	return nullptr;

}


int main(){

	linkedlist l;

	l.add(1);
	l.add(2);
	l.add(3);
	l.add(1);
	l.add(1);
	l.add(2);
	l.add(4);
	l.print();
	partition(l,2);
	l.print();
	revert(l);
	l.print();

	cout << ktolast(l,1)->info << endl;
	cout << ktolast(l,2)->info << endl;
	cout << ktolast(l,3)->info << endl;
	cout << ktolast(l,4)->info << endl;
	cout << ktolast(l,5)->info << endl;
	cout << ktolast(l,6)->info << endl;
	cout << ktolast(l,7)->info << endl;

	node *n = l.head->next->next;
	deletemiddle(n);
	l.print();

	removeduplicates(l);
	l.print();

	linkedlist l1;
	l1.add(1);
	l1.add(2);
	l1.add(3);
	l1.add(4);

	linkedlist l2;
	l2.add(10);
	l2.add(20);
	l2.add(30);

	l2.head->next->next->next = l1.head->next->next;

	l1.print();
	l2.print();
	cout << findintersection(l1,l2)->info << endl;

	linkedlist l3;
	l3.add(1);
	l3.add(2);
	l3.add(3);
	l3.add(4);
	l3.add(7);
	l3.add(8);
	l3.add(9);
	l3.add(6);
	l3.head->next->next->next->next->next->next->next->next = l3.head->next->next;
	cout << findcycle(l3)->info << endl;


}



