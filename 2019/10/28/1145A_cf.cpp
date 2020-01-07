#include<bits/stdc++.h>

using namespace std;

int n,a[20];
int func(int l, int r)
{
	if( is_sorted(a + l, a + r + 1) ) return r - l + 1;
	int mid = l + r >> 1;
	return max( func(l,mid), func(mid + 1,r) );
}
int main()
{		
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) scanf("%d",a + i);
	printf( "%d\n",func(1, n) );
	return 0;
}
