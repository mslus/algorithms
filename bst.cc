// BST implementation with examples
#include <iostream>
#include <queue>

using namespace std;

class node {

public:
	int n;
	node* left;
	node* right;

	node(int info, node *nl, node *nr) {
		n = info;
		left = nl;
		right = nr;
	}
};

class bst {
	node *root;

public:
	bst() {
		root = nullptr;
	}

	bool add(int info) {

		if (root == nullptr) {
			root = new node(info, nullptr, nullptr);
			return true;
		}

		node *n = root;
		node *next;

		for (;;) {

			if (n->n > info)
				next = n->left;
			else if (n->n < info)
				next = n->right;
			else
				return false;

			if (next == nullptr)
				break;
			else
				n = next;
		}

		if (n->n > info) {
			next = new node(info, nullptr, nullptr);
			n->left = next;
		} else {
			next = new node(info, nullptr, nullptr);
			n->right = next;
		}
		return true;
	}

	bool isIncluded(int info) {
		node* n = root;
		node* next;

		for (;;) {

			if (n->n > info)
				next = n->left;
			else if (n->n < info)
				next = n->right;
			else
				return true;

			if (next == nullptr)
				return false;
			else
				n = next;
		}
	}

	// note that it will not find parent if the value is at root
	// in such case we will return null
	node* findParent(int info) {
		node* n = root;
		node* next;

		for (;;) {
			if (n->n > info)
				next = n->left;
			else if (n->n < info)
				next = n->right;

			if (next == nullptr)
				return nullptr;
			else if (next->n == info)
				return n;
			else
				n = next;
		}
	}

	bool remove(int info){
		node *n;
		node *m;
		node *o;

		if(root == nullptr) return false;
		if(root->n == info) {
			if(root->left == nullptr && root->right != nullptr){
				n = root;
				root = root->right;
				delete n;
			}else if(root->left != nullptr && root->right == nullptr){
				n = root;
				root = root->left;
				delete n;
			}else{ // find smallest node larger than info
				n = root->right;
				while(n->left != nullptr) n = n->left;
				root->n = n->n;
				delete n;
			}
		}else{
			n = findParent(info);
			if(n == nullptr) return false;
			if(n->n < info ){
				m = n->right;
			}else{
				m = n->left;
			}

			if(m->left == nullptr && m->right != nullptr){
				o = m;
				if(m == n->left) n->left = m->right;
				else n->right = m->right;
				delete o;
			}else if(m->left != nullptr && m->right == nullptr){
				o = m;
				if(m == n->left) n->left = m->left;
				else n->right = m->left;
				delete o;
			}else{ // find smallest node larger than info
				o = m->right;
				while(o->left != nullptr) o = o->left;
				m->n = o->n;
				delete o;
			}
		}
		return true;
	}

	void printtree(){
		queue<node*> q;
		node *n;
		q.push(root);
		while(!q.empty()){
			n = q.front();
			q.pop();

			cout << n->n << endl;
			if(n->left != nullptr) q.push(n->left);
			if(n->right != nullptr) q.push(n->right);
		}
	}
};



int main(){
	bst B;

	B.add(5);
	B.add(6);
	B.add(4);
	B.add(1);
	B.add(10);
	B.printtree();

	B.remove(4);
	B.printtree();

	return 0;
}
