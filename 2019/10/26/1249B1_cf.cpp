#include <cmath>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <string>
#include <set>
#define _for( i, a, b ) for( int i = (a); i < (b); i++ )
#define _rep(i, a, b) for (int i = (a); i <= (b); i++)
#define _show_arr(array, begin, len) _for(i, begin, len ) { printf("%d ",array[i]); } printf("\n");
#define _show_XY(XY,x,y) _for( i, 0, x ){ _for( j, 0, y ) { printf("%d ",XY[i][j]); } printf("\n");}
#define INF 10000000

using namespace std;

int par[200010];
int n,T;


int my_find(int n, int dep, int beg)
 {
	if ( par[n] == beg ) return dep;
	//printf("par = %d",par[n]);
	dep ++;
    //printf("dep = %d",dep);
	return my_find( par[n], dep, beg);	
}

int main()
{
	scanf("%d",&T);
	while( T -- )
	{
		scanf("%d",&n);
		for( int i = 1; i <= n; i++ ) scanf("%d",&par[i]);
		//printf("ans = ");
		for ( int i = 1; i <= n; i++ ) printf("%d ", my_find(i,1,i));
		printf("\n");
	}

    return 0;
}
