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


class node_parent{
public:
	int n;
	node *left;
	node *right;
	node *parent;
	node *self;
	node_parent(int info, node *nl, node *nr, node* s, node *np) {
		n = info;
		left = nl;
		right = nr;
		parent = np;
		self = s;
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
		int tmp;

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
			}else if(root->left == nullptr && root->right == nullptr){
				delete root;
				root = nullptr;
			}else{ // find smallest node larger than info
				n = root->right;
				while(n->left != nullptr) n = n->left;
				tmp = n->n;
				remove(n->n);
				root->n = tmp;				
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
				if(m == n->left) n->left = m->right;
				else n->right = m->right;
				delete m;
			}else if(m->left != nullptr && m->right == nullptr){
				if(m == n->left) n->left = m->left;
				else n->right = m->left;
				delete m;
			}else if(m->left == nullptr && m->right == nullptr){
				if(m == n->left) n->left = nullptr;
				else n->right = nullptr;
				delete m;
			}else{ // find smallest node larger than info
				o = m->right;
				while(o->left != nullptr) o = o->left;
				tmp = o->n;				
				remove(tmp);
				m->n = tmp;
			}
		}
		return true;
	}

	void printtree(){
		queue<node_parent> q;
		q.push(node_parent(root->n, root->left, root->right, root, nullptr));
		while(!q.empty()){
			node_parent n = q.front();
			q.pop();

			if (n.parent != nullptr)
				cout << n.parent->n << " <----" << n.n << endl;
			if(n.left != nullptr) q.push(node_parent(n.left->n, n.left->left, n.left->right, n.left, n.self));
			if(n.right != nullptr) q.push(node_parent(n.right->n, n.right->left, n.right->right, n.right, n.self));
		}
	}
};



int main(){
	bst B;

	B.add(8);
	B.add(9);
	B.add(4);
	B.add(1);
	B.add(7);
	B.add(6);
	B.add(5);
	B.add(10);
	B.printtree();
	cout << "-----" << endl;

	B.remove(4);
	B.printtree();

	return 0;
}
