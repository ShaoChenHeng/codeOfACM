//P1019_luogu
//DFS
#include <bits/stdc++.h>

using namespace std;

int n, ans = 0;
int use[30];
string ss[30];
string beg;

int canlink( string str1, string str2 )
{
    for ( int i = 1; i < min( str1.length(), str2.length() ); i ++ )
    {
        int flag = 1;
        for ( int j = 0; j < i; j ++ )
        {
            if ( str1[str1.length() - i + j] != str2[j] ) flag = 0;
        }//连续多少位
        if ( flag ) return i;
    }
    return 0;
}

void solve( string strnow, int lengthnow )
{
    ans = max( lengthnow, ans );
    //cout << lengthnow<<endl;
    for ( int i = 0; i < n; i ++ )
    {
        if ( use[i] >= 2 ) continue;
        int c = canlink( strnow, ss[i] );
        if ( c > 0 )
        {
            use[i] ++;
            solve( ss[i], lengthnow + ss[i].length() - c  );
            use[i] --;
        }

    }

}

int main()
{
    scanf("%d", &n);
    for ( int i = 0; i <= n; i ++ ) use[i] = 0, cin >> ss[i];
    solve(' ' + ss[n], 1 );
    printf("%d\n",ans);
    return 0;
}
