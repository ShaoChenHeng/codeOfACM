#include<cstdio>
#include<cstring>

using namespace std;

int num[1000];
int n,cnt;

void fun( int n, int sum , int cur, int pos)
{
	if ( sum == n )
	{
		cnt ++;
		if ( cnt > 1  ) printf(";");
		printf("%d=",n);
		for( int i = 1; i < pos; i++  ) 
		{
			printf("%d", num[i]);
			if ( i != pos - 1 ) printf("+");
		}
		if ( cnt == 4 ) 
		{
			printf("\n");	
			cnt = 0;
		}

	}
	for ( int i = cur; i <= n; i ++  )
	{

		if ( i + sum <= n )
		{
			num[pos] = i;
			fun( n, sum + i , i, pos + 1);
			num[pos] = 0;
		}
	}
}

int main()
{
	scanf("%d",&n);
	cnt = 0;
	for ( int i = 1; i <= n; i++ )
	{
		memset(num,0,sizeof(num));
		num[1] = i;
		fun(n,i,i,2);
	}
	return 0;
}
