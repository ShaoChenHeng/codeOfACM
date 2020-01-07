#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

int T;
int count[27];
int a[1000005];
int b[1000005];

int main()
{
    while ( scanf("%d",&T) != EOF)
    {
        while( T -- )
        {
            string ss;
            int cna = 0,cnb = 0;
            cin >> ss;
            for ( int i = 0, x; i < ss.length(); i ++ )
            {
                x = ss[i] - '0';
                //printf("x = %d ",x);
                if ( x & 1 ) a[++cna] = x;
                else b[++cnb] = x;
            }
            int i = 1, j = 1;
            while ( i <= cna && j <= cnb )
            {
                if ( a[i] < b[j] ) printf("%d",a[i]), ++i;
                else printf("%d",b[j]), ++j;
            }
            while ( i <= cna ) printf("%d",a[i]), ++i;
            while ( j <= cnb ) printf("%d",b[j]), ++j;
            printf("\n");
        }
    }
    
    return 0;
}
