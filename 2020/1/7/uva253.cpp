#include <bits/stdc++.h>

using namespace std;

char a[15];

int main()
{
    //freopen("out", "w", stdout);
    while ( cin >> (a+1) )
    {
        int i,j;
        for ( i = 7; i <= 9; i ++)
        {
            for (j = 1; j <= 6; j ++)
                if( a[j] == a[i] && a[7-j] == a[19-i] )
                {
                    a[7-j] = a[19-i] = '0';
                    break;
                }
            if ( j == 7 ) break;
        }
        i == 10 ? cout<<"TRUE"<<endl : cout<<"FALSE"<<endl;
    }
    //fclose(stdout);
    return 0;
}
