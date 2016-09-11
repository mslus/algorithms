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

void inorder(node *n, vector<int> &result){

	if(n->left != nullptr) inorder(n->left, result);
	result.push_back(n->info);
	if(n->right != nullptr) inorder(n->right, result);
}

bool checkifbst(bst &T){

	vector<int> nodes;
	inorder(T.root, nodes);
	for(int i = 0; i < nodes.size()-1; i++)
		if(nodes[i+1] <= nodes[i]) return false;

	return true;
}


void findLeaves(vector<int> &v, node *n){
	if(n != nullptr){
		if(n->left == nullptr && n->right == nullptr)
			v.push_back(n->info);
		else{
			findLeaves(v, n->left);
			findLeaves(v, n->right);
		}
	}
}

vector<int> findLeaves(bst &T){
	vector<int> result;
	if(T.root != nullptr)
		findLeaves(result, T.root);
	return result;
}



int main(){

	bst b;

	b.add(4);
	b.add(2);
	b.add(6);
	b.add(7);
	b.add(5);
	b.add(10);
	b.add(8);
	printtree(b.root);

	cout << "Find leaves of the tree" << endl;
	vector<int> r = findLeaves(b);
	for(int i = 0; i < r.size(); i++)
		cout << r[i] << " ";
	cout << endl;

	cout << "Test copy-constructor" << endl;
	bst c = b;
	printtree(c.root);

	cout << "test if the tree is a valid BST" << endl;
	cout << checkifbst(b) << endl;
	node *n = new node();
	n->info = 10;
	n->left = nullptr;
	n->right = nullptr;
	b.root->left->right = n;
        n->parent = b.root->left;
	cout << checkifbst(b) << endl;

	b.root->left->right = nullptr;
	delete n;

	cout << "********* delete 4" << endl;
	b.del(4);
	printtree(b.root);
	cout << "********* delete 6" << endl;
	b.del(6);
	printtree(b.root);


}
