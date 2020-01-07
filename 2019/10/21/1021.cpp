#include <cstdio>

long long fib[1000010];
int n;

int main()
{
    fib[0] = 7;
    fib[1] = 11;
    for ( int i = 2; i <= 1000000; i++  ) 
    {
        fib[i] = fib[i-1] + fib[i-2];
    }
    while ( scanf("%d",&n) != EOF )
    {
        if ( fib[n] % 3 == 0  ) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
