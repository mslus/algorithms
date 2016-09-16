/*
 * buildbalanced.cc
 *
 *  Created on: Sep 10, 2016
 *      Author: maciek
 */
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>

using namespace std;

struct node{
	int info;
	node *left;
	node *right;
	node *parent;
};

struct nodeL{
	node *n;
	int level;

	nodeL(node *x, int l){
		n = x;
		level = l;
	}
};

struct hb{
	int height;
	bool balanced;

	hb(){
		height = 0;
		balanced = true;
	}

	hb(int x, bool y){
		height = x;
		balanced = y;
	}

	hb(const hb &b){
		height = b.height;
		balanced = b.balanced;
	}
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

vector< vector<int> > findLevels(bst &b){
	queue<nodeL> q;
	int max;

	vector< vector<int> > result(10, vector<int>(0) );

	q.push( nodeL(b.root, 1) );

	result[0].push_back(b.root->info);

	while(!q.empty()){
		nodeL x = q.front();
		q.pop();

		result[x.level].push_back(x.n->info);
		max = x.level;

		if(x.n->left != nullptr){
			q.push(nodeL(x.n->left, x.level+1));
		}
		if(x.n->right != nullptr){
			q.push(nodeL(x.n->right, x.level+1));
		}
	}

	result.resize(max+1);
	return result;
}


int computeheight(node *n){
	int leftsub = 0;
	int rightsub = 0;
	if(n->right != nullptr)
		rightsub = computeheight(n->right);
	if(n->left != nullptr)
		leftsub = computeheight(n->left);

	return max(leftsub,rightsub)+1;
}

int computetreeheight(bst &b){
	if(b.root == nullptr)
		return 0;
	else
		return computeheight(b.root);
}

hb checkbalanced(node *n){
	hb hb_right;
	hb hb_left;
	hb res;

	if(n->right != nullptr)
		hb_right = checkbalanced(n->right);
	if(n->left != nullptr)
		hb_left = checkbalanced(n->left);

	if(!hb_right.balanced || !hb_left.balanced || abs(hb_right.height-hb_left.height) > 1 )
		res.balanced = false;
	else
		res.balanced = true;

	res.height = max(hb_right.height,hb_left.height)+1;

	return res;
}

bool checktreebalanced(bst &b){
	if(b.root == nullptr)
		return true;
	else
		return checkbalanced(b.root).balanced;
}

node* findsuccessor(node *n){
	if(n->parent != nullptr && n->parent->info > n->info){
		return n->parent;
	}else if(n->right != nullptr){
		node *m = n->right;
		while(m->left != nullptr) m = m->left;
		return m;
	}else{
		return nullptr;
	}
}

node* findnode(int x, bst &b){
	node* n = b.root;

	while(n != nullptr){
		if(n->info == x) return n;
		if(n->info < x)
			n = n->right;
		else
			n = n->left;
	}
	return nullptr;
}

node* findcommonancestor(node* current, node* n1, node* n2){
	node *nl, *nr;	

	if(current == n1 || current == n2)
		 return current;
	

	if(current->left != nullptr) 
		nl = findcommonancestor(current->left,n1,n2);
	else	
		nl = nullptr;
	if(current->right != nullptr) 
		nr = findcommonancestor(current->right,n1,n2);
	else
		nr = nullptr;

	if((nl == n1 && nr == n2) || (nl == n2 && nr == n1))
		return current;
	else if((nl == n1 && nr == nullptr) || (nl == nullptr && n2 == n1))
		return n1;
	else if((nl == n2 && nr == nullptr) || (nl == nullptr && nr == n2))
		return n2;
	else if(nl != nullptr)
		return nl;
	else if(nr != nullptr)
		return nr;
	else
		return nullptr;
} 



int main(){

	bst b;

	vector<int> v = {1,2,4,6,8,9,10,23};

	buildBalanced(v,0,v.size()-1,b);

	printtree(b.root);

	cout << "Find levels of the tree" << endl;
	vector<vector<int> > vv = findLevels(b);
	for(int i = 0; i < vv.size(); i++){
		cout << i << ": ";
		for(int j = 0; j < vv[i].size(); j++)
			cout << vv[i][j] << " ";
		cout << endl;
	}


	cout << "next 1: " << findsuccessor(findnode(1,b))->info << endl;
 	cout << "next 6: " << findsuccessor(findnode(6,b))->info << endl;
	cout << "next 9: " << findsuccessor(findnode(9,b))->info << endl;
	cout << "next 10: " << findsuccessor(findnode(10,b))->info << endl;

	cout << "common ancestor test: " << endl;
	cout << "nodes 8 10: " << findcommonancestor(b.root, findnode(8,b), findnode(10,b))->info << endl;
	cout << "nodes 1 23: " << findcommonancestor(b.root, findnode(1,b), findnode(23,b))->info << endl;
	cout << "nodes 1 4: " << findcommonancestor(b.root, findnode(4,b), findnode(1,b))->info << endl;

	cout << "Tree height: " << computetreeheight(b) << endl;
	cout << "Balanced tree: " << checktreebalanced(b) << endl;
	b.del(1);
	b.del(4);
	cout << "Balanced tree: " << checktreebalanced(b) << endl;

	return 0;
}



