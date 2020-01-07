#include <cstdio>

using namespace std;

int m,n;
int M;

int judge(int n)
{
	int sum = 0;
	for ( int i = 1; i <= n / 2; i++ )
	{
		if( n % i == 0 ) sum += i;
		//printf("sum = %d\n",sum);
	}

	return sum;
}

int main()
{
	while( scanf("%d",&M) != EOF )
	{
		while( M -- )
		{
			scanf("%d %d",&n,&m);
			/*printf("%d\n", judge(n));
			printf("////////\n");
			printf("%d\n", judge(m));*/
			if ( judge(n) == m && judge(m) == n ) printf("YES\n");
			else printf("NO\n");
		}
		
	}

	return 0;
}