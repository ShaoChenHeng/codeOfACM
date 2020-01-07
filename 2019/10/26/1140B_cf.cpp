#include <bits/stdc++.h>

using namespace std;

int T;
char s[105];

int main()
{
    scanf("%d",&T);
    int n;
    while( T -- )
    {    
        scanf("%d",&n);
        scanf("%s",s);
        if ( s[0] == '>' ) printf("0\n");
        else if ( s[n-1] == '<' ) printf("0\n");
        else
        {
            int left = 0;
            int right = 0;
            for ( int i = 0; i < n; i ++ ) 
            {
                if ( s[i] == '>' ) {left = i; break;}
            }
            for ( int i = n-1; i >= 0; i -- ) 
            {
                if ( s[i] == '<' ) {right = i;break;}
            }
            printf("%d\n",min( left, n - 1 - right ));
        }
    }
    return 0;
}
