#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		string a;
		int sum = 0;
		cin >> n >> a;
		for (int i = 0; i < n; i++) 
		{
			sum = sum * 2 + a[i] - '0';
		}
		int ans = 0;
		while (sum--)
		{
			bool f = true;
			bool p = true;
			int i = 1;
			int k;
			if (n % 2 == 0) k = n;
			else k = n - 1;
			int j = k - 1;
			for (; j <= i; j = j - 2, i = i + 2)
			{
				if ((!(sum & (1<<i))) != (!(sum & (1<<j))))
				{
					f = false;
					break;
				}
			}
			i = 0;
			if (n % 2 == 0) k = n - 1;
			else k = n;
			j = k - 1;
			for (; j <= i; j = j - 2, i = i + 2)
			{
				if ((!(sum & (1<<i))) != (!(sum & (1<<j))))
				{
					p = false;
					break;
				}
			}
			if (f || p) ans++;
		}
		cout << ans << endl;
	}
}
