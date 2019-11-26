#include <bits/stdc++.h>

using namespace std;

int brain, T, N, fangan = 0, _max = 0;
int y[20000] = {0}, z[20000];

void dfs(int k, int t, int b, int cnt)
{
	if ( k == N )
    {
		if( cnt > _max )
        {
			fangan = 1;
			_max = cnt;
		}
		else if( cnt == _max ) fangan ++;
		return;
	}
	if( N - k < _max - cnt ) return;
	if( t + y[k] > T || b + z[k] > brain )
    {
		if( cnt > _max )
        {
			fangan = 1;
			_max = cnt;
		}
		else if( cnt == _max )
        {
			fangan ++;
		}
		dfs( k + 1, t, b, cnt );
		return;
	}
	dfs( k + 1, t + y[k], b + z[k], cnt + 1);
	dfs( k + 1, t, b, cnt );
}

int main()
{
	int g1, g2, i;
	scanf("%d %d %d",&N, &T, &brain);
	for( i = 0; i < N; i ++)
    {
		scanf("%d %d %d",&g1, &z[i], &g2);
		y[i] = g1 + g2;
	}
	dfs(0,0,0,0);
	printf("%d %d", _max, fangan);
	return 0;
}
