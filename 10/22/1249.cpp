#include<iostream>
using namespace std;

int main()
{
	int k, n;
	cin >> k;
	while (k --)
	{
		cin >> n;
		cout << 3 * n * (n - 1) + 2 << endl;
	}
	return 0;
}
