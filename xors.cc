#include <iostream>

using namespace std;

int xorseries(int x){
	int xt[4] = {x, 1, x+1, 0};
	return xt[x % 4];
}


int main(){

	int x;

	x = 1^2^3^4;
	cout << x << " " << xorseries(4) << endl;
	x = 1^2^3^4^5;
	cout << x << " " << xorseries(5) << endl;
	x = 1^2^3^4^5^6^7^8;
	cout << x << " " << xorseries(8) << endl;
	x = 1^2^3^4^5^6^7^8^9^10;
	cout << x << " " << xorseries(10) << endl;
	cout << 0 << " " << xorseries(0) << endl;

	x = 0;
	for(int i = 0; i <= 1234567898; i++)
		x = x^i;
	cout << x << " " << xorseries(1234567898) << endl;

	return 0;
}
 



