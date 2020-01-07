#include <iostream>

using namespace std;

int main()
{
	int n, m;
	int T;
	cin >> T;
	while ( T-- )
	{
		cin >> n>>m;
		cout << n * m * (n + 1) * (m + 1) / 4 << endl;
	}
	return 0;
}
