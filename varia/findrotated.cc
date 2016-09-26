/*
 * findrotated.cc
 *
 *  Created on: Sep 25, 2016
 *      Author: mslus
 */
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

using namespace std;


int findrotated(const vector<int> &tab, int x){

	int low = 0;
	int high = tab.size()-1;
	int mid;

	while(low <= high){
		mid = (high+low)/2;
		if(tab[low] <= x && tab[mid] > x){
			high = mid-1;
		}else if(tab[mid] < x && tab[high] >= x){
			low = mid+1;
		}else if(tab[low] >= x && tab[mid] > x && tab[low] > tab[mid]){
			high = mid-1;
		}else if(tab[mid] > x && tab[high] >= x && tab[mid] > tab[high]){
			low = mid+1;
		}else if(tab[low] <= x && tab[mid] < x && tab[low] > tab[mid]){
			high = mid-1;
		}else if(tab[mid] < x && tab[high] <= x && tab[mid] > tab[high]){
			low = mid+1;
		}else if(tab[mid] == x){
			return mid;
		}
	}

	return -1;

}


TEST(vectorrotatetest, test1){
      vector<int> v1({10,12,15,2,5,6,8,9});
      EXPECT_EQ(1, findrotated(v1,12));	
}

TEST(vectorrotatetest, test2){
      vector<int> v1({9,10,12,15,2,5,6,8});
      EXPECT_EQ(2, findrotated(v1,12));	
}

TEST(vectorrotatetest, test3){
      vector<int> v1({8,9,10,12,15,2,5,6});
      EXPECT_EQ(3, findrotated(v1,12));	
}

TEST(vectorrotatetest, test4){
      vector<int> v1({6,8,9,10,12,15,2,5});
      EXPECT_EQ(4, findrotated(v1,12));	
}

TEST(vectorrotatetest, test5){
      vector<int> v1({12,15,2,5,6,8,9,10});
      EXPECT_EQ(0, findrotated(v1,12));	
}

TEST(vectorrotatetest, test6){
      vector<int> v1({15,2,5,6,8,9,10,12});
      EXPECT_EQ(7, findrotated(v1,12));	
}


int main(int ac, char *av[]){

	testing::InitGoogleTest(&ac, av);
	return RUN_ALL_TESTS();
}



