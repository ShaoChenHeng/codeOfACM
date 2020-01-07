#include <cstdio>

using namespace std;
int n;

int func(int n)
{
    if ( n == 1 ) return 1;
    return func(n-1) * n;
}

int main()
{
    while ( scanf("%d",&n) != EOF && n )
    {
        printf( "%d\n",func(n) );
    }
    return 0;
}
