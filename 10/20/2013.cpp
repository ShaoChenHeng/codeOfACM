#include <cstdio>

using namespace std;

int m;

int main()
{
	while ( scanf("%d",&m) != EOF)
	{
		int cnt = 1;
		for ( int i = 0; i < m - 1; i ++ )
		{
			cnt ++;
			cnt *= 2;
		}
		printf("%d\n",cnt );
	} 
	return 0;
}
