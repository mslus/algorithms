/*
 * randomnode.cc
 *
 *  Created on: Sep 18, 2016
 *      Author: maciek
 */
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <ctime>

using namespace std;

struct node{
	int info;
	node *left;
	node *right;
	node *parent;
};

struct bst{
	node *root;
	bst(){
		root = nullptr;
	}

	bst(const bst& b){

		if(b.root == nullptr){
			root = nullptr;
			return;
		}

		queue<node*> q;
		node* x;

		q.push(b.root);
		while(!q.empty()){
			x = q.front();
			q.pop();

			add(x->info);
			if(x->left != nullptr) q.push(x->left);
			if(x->right != nullptr) q.push(x->right);
		}
	}

	bool add(int x){
		node *next;

		if(root == nullptr){
			next = new node();
			next->info = x;
			next->parent = nullptr;
			next->left = nullptr;
			next->right = nullptr;
			root = next;
			return true;
		}

                node *n = root;
		for(;;){
			if(n->info < x){
				next = n->right;
				if(next == nullptr){
					next = new node();
					next->info = x;
					next->left = nullptr;
					next->right = nullptr;
					next->parent = n;
					n->right = next;
					return true;
				}
				n = next;
			}else if(n->info > x){
				next = n->left;
				if(next == nullptr){
					next = new node();
					next->info = x;
					next->left = nullptr;
					next->right = nullptr;
					next->parent = n;
					n->left = next;
					return true;
				}
				n = next;
			}else{
				return false;
			}
		}
	}

	bool del(int x){
		node *n = root;
		for(;;){
			if(n == nullptr) return false;
			if(n->info == x)
				break;
			else if(x < n->info)
				n = n->left;
			else
				n = n->right;
		}


		if(n->left == nullptr && n->right == nullptr){
			if(n == root){
				root = nullptr;
			}else{
				if(n->parent->left == n)
					n->parent->left = nullptr;
				else
					n->parent->right = nullptr;
				delete n;
			}
		}else if(n->left == nullptr && n->right != nullptr){
			if(n == root){
				root = n->right;
				n->right->parent = nullptr;
				delete n;
			}else{
				if(n->parent->left == n){
					n->parent->left = n->right;
					n->right->parent = n->parent;
				}else{
					n->parent->right = n->right;
					n->right->parent = n->parent;
				}
				delete n;
			}
		}else if(n->left != nullptr && n->right == nullptr){
			if(n == root){
				root = n->left;
				n->left->parent = nullptr;
				delete n;
			}else{
				if(n->parent->left == n){
					n->parent->left = n->left;
					n->left->parent = n->parent;
				}else{
					n->parent->right = n->left;
					n->left->parent = n->parent;
				}
				delete n;
			}
		}else{ // left and right are not null
			node *m = n->right;
			while(m->left != nullptr) m = m->left;
			int temp = m->info;
			del(temp);
			n->info = temp;
		}
		return true;
	}

	node* selectRandom(){
		queue<node*> q;
		int nodecounter = 0;

		q.push(root);
		while(!q.empty()){
			node *n = q.front();
			q.pop();
			nodecounter++;

			if(n->left != nullptr) q.push(n->left);
			if(n->right != nullptr) q.push(n->right);
		}

		srand(time(nullptr));
		int x = rand() % nodecounter + 1;

		q.push(root);
		nodecounter = 0;
		while(!q.empty()){
			node *n = q.front();
			q.pop();
			nodecounter++;
			if(nodecounter == x) return n;

			if(n->left != nullptr) q.push(n->left);
			if(n->right != nullptr) q.push(n->right);
		}

		return nullptr;
	}

};

void printtree(node *n){

	if(n->left != nullptr)
		printtree(n->left);

	if(n->parent != nullptr){
		cout << n->parent->info;
		if(n->parent->left == n)
		cout << " L--> ";
	else
		cout << " R--> ";
	}else
		cout << "NULL --> ";


	cout << n->info << endl;

	if(n->right != nullptr)
		printtree(n->right);

}

void buildBalanced(vector<int> &v, int l, int r, bst &b){
	if(l > r) return;
	b.add(v[(l+r)/2]);
	buildBalanced(v, l, (l+r)/2-1, b);
	buildBalanced(v, (l+r)/2+1, r, b);
}



int main(){

	bst b;

	vector<int> v = {1,2,4,6,8,9,10,23};

	buildBalanced(v,0,v.size()-1,b);

	printtree(b.root);

	cout << "Printing random node: ";
	cout << b.selectRandom()->info << endl;

	return 0;
}
