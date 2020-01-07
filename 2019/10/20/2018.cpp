#include <cstdio>
#include <cstring>

using namespace std;

int a[100];
int c(int n)
{
	if(n<=4) return n;
	return c(n-1)+c(n-3);
}

int func(int n)
{
    if ( a[n] == 0 ) return func(n-1) + func(n-3);
    return a[n];
}

int main()
{
	int n;
    memset(a,0,sizeof(a));
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    a[4] = 4;

	while(scanf("%d",&n) != EOF && n)

		printf("%d\n",func(n));

    return 0;
}
