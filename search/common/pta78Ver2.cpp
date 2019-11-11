#include<cstdio>

using namespace std;

int num[10000];
int n;

void yield( int cur, int n )
{   
    if ( cur == n ) 
    {
        for ( int i = 0; i < n; i++ ) printf("%d",num[i]);
        printf("\n");
    }
    else
    {
        for ( int i = 1; i <= n; i ++ )
        {
            int ok = 1;
            for ( int j = 0; j < cur; j ++ )
            {
                if ( num[j] == i ) ok = 0;
            }
            if ( ok )
            {
                num[cur] = i;
                yield(cur+1, n);
            }
        }

    }

}

int main()
{
    scanf("%d",&n);
    yield(0,n);
    return 0;
}
