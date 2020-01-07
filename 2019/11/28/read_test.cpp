#include <bits/stdc++.h>

using namespace std;

int n,m;

int main()
{
    scanf( "%d %d", &n, &m );
    char ch;
    int num;
    for ( int i = 1; i <= n; i++ )
    {
        scanf("%s", ch);
        //getchar();
        scanf("%d", &num);
        if ( ch == 'A' )
        {
            printf("hello\n");
        }
        if ( ch == 'Q' )
        {
            printf("hi\n");
        }
    }


    return 0;
}
