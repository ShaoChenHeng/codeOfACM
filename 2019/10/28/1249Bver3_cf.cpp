#include <cmath>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <string>
#include <set>
#include <vector>
#define _for( i, a, b ) for( int i = (a); i < (b); i++ )
#define _rep(i, a, b) for (int i = (a); i <= (b); i++)
#define _show_arr(array, begin, len) _for(i, begin, len ) { printf("%d ",array[i]); } printf("\n");
#define _show_XY(XY,x,y) _for( i, 0, x ){ _for( j, 0, y ) { printf("%d ",XY[i][j]); } printf("\n");}
#define INF 10000000

using namespace std;

int par[200010];
int n,T;
vector<int> ans,appear;

void my_find(int n, int dep, int beg)
 {
    if ( appear[n] ) return;
	if ( par[n] == beg ) { ans[beg] = dep; return;}
	dep ++;
	appear[n] = beg;
    my_find( par[n], dep, beg);	
    printf("%d hello\n",n);
}

int main()
{
	scanf("%d",&T);
	while( T -- )
	{
		scanf("%d",&n);
        printf("hello");
		for( int i = 1; i <= n; i++ ) scanf("%d",&par[i]);
		//printf("ans = ");
    	for ( int i = 1; i <= n; i++ ) 
        {
            my_find(i,1,i);
        }
        for ( int i = 1; i <= n; i++ ) printf("%d ",ans[i]);
	}

    return 0;
}
