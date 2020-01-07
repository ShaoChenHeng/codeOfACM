#include <cstdio>

long long int m;

int main()
{
    while(scanf("%lld",&m) != EOF)
    {
        while ( m-- )
        {
            long long int n;
            scanf("%lld",&n);
            printf("%lld %lld\n",n*n*n, (n + 1) * (n + 1)* (n + 1));
        }
    }
    return 0;
}
