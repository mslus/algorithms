#include <iostream>


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


int main(){

	bst b;

	b.add(4);
	b.add(2);
	b.add(6);
	b.add(7);
	b.add(5);
	printtree(b.root);
	cout << "*********" << endl;
	b.del(4);
	printtree(b.root);
	cout << "*********" << endl;
	b.del(6);
	printtree(b.root);

}

