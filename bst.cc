// BST implementation with examples
#include <iostream>

class node{
	
	public:
	int n;
	node* left;
	node* right;

	node(int info, node* nl, node* nr){
		n = info;
		left = nl;
		right = nr;
	}
};

class bst{
	node* root;

	public:
	bst(){
		root = null;
	}


	bool add(int info){
		
		if(root == null){
			root = new node(info,null,null);
			return true;
		}

		node* n = root;
		node* next;		

		for(;;){
	
			if(n->n > info)
				next = n->left;
			else if(n->n < info)
				next = n->right;
			else
				return false;
		
			if(next == null) 
				break;
			else
				n = next;
		}

		if(n->n > info){
			next = new node(info,null,null);
			n->left = next;
		}else{
			next = new node(info,null,null);
			n->right = next;
		}		
		return true;
	}

	bool isIncluded(int info){
		node* n = root;
		node* next;
		
		for(;;){
	
			if(n->n > info)
				next = n->left;
			else if(n->n < info)
				next = n->right;
			else
				return true;
		
			if(next == null) 
				return false;
			else
				n = next;
		}
	}

	// note that it will not find parent if the value is at root
	// in such case we will return null
	node* findParent(int info){
		node* n = root;
		node* next;
		
		for(;;){
			if(n->n > info)
				next = n->left;
			else if(n->n < info)
				next = n->right;
			
			if(next == null) 
				return null;
			else if(next->n == info)
				return n;
			else
				n = next;
		}
	}

	bool delete(int info){
		node* n;
		if(root == null) return false;
		if(root->n == info){
		}
	}
};


