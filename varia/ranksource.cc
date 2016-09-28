/*
 * ranksource.cc
 *
 *  Created on: Sep 27, 2016
 *      Author: maciek
 */
#include <iostream>


using namespace std;


struct node{
	int info;
	int left_count;
	int node_count;
	node *left;
	node *right;
	node(int x){
		info = x;
		left_count = 0;
		node_count = 1;
		left = nullptr;
		right = nullptr;
	}
};


struct stream{
	node *root;
	void track(int x);
	int getRankOfNumber(int x);
	stream(){
		root = nullptr;
	}
};

void stream::track(int x){
	if(root == nullptr){
		node *nn = new node(x);
		root = nn;
		return;
	}

	node *nn = root;
	for(;;){
		if(nn->info > x){
			if(nn->left == nullptr){
				node *mm = new node(x);
				nn->left = mm;
				nn->left_count++;
				return;
			}else{
				nn->left_count++;
				nn = nn->left;
			}
		}else if(nn->info < x){
			if(nn->right == nullptr){
				node *mm = new node(x);
				nn->right = mm;
				return;
			}else{
				nn = nn->right;
			}
		}else{
			nn->node_count++;
			return;
		}
	}
}

int stream::getRankOfNumber(int x){
	node *nn = root;

	int ile = 0;
	for(;;){
		if(nn == nullptr) return ile;
		if(nn->info == x) return ile;
		if(nn->info > x){
			nn = nn->left;
		}else{
			ile+=(nn->left_count+nn->node_count);
			nn = nn->right;
		}
	}
	return 0;
}

int main(){

	stream S;

	S.track(4);
	S.track(9);

	cout << S.getRankOfNumber(6) << endl;

	S.track(10);
	S.track(2);

	cout << S.getRankOfNumber(1) << endl;
	cout << S.getRankOfNumber(12) << endl;

	S.track(2);
	cout << S.getRankOfNumber(11) << endl;
	cout << S.getRankOfNumber(10) << endl;
	S.track(9);
	cout << S.getRankOfNumber(10) << endl;

	return 0;
}



