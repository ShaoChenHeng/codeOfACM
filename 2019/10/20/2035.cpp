#include <iostream>
using namespace std;

int main(){
	int A, B;
	while (cin >> A >> B && (A != 0 || B != 0)) {
		int da = 1;
		while (B != 0) {
			if (B % 2 == 1) da = da * A % 1000;
			A = A * A % 1000;
			B = B / 2;
		}
		cout << da << endl;
	}
}
