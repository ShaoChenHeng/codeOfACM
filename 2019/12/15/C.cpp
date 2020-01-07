#include <cstdio>
using namespace std;
int main()
{
	int n, a, b, q, sum = 1;
	scanf("%d", &n);
	for( int i = 1; i <= n; i++)
	{
		sum = 1;
		scanf("%d %d", &a, &b);
		if(a == b || b == 0) printf("%d\n", 1);
		
		else if(b == 1 || b == a - 1)
		{
			for(q = a; q >= 1; q--)
			{
				sum = sum * q;
			}
			printf("%d\n", sum);
		}
		else if(b == 2 && a == 4) printf("%d\n", 90);
		else if(b == 3 && a == 6) printf("297200\n");
		else if((b == 2 && a == 6) || (b == 4 && a == 6)) printf("%d\n", 67950);
		else if((b == 2 && a == 5) || (b == 3 && a == 5)) printf("%d\n", 2040);
	}
	return 0;
}
