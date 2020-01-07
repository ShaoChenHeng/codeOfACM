#include <bits/stdc++.h>

using namespace std;

int n;
string ss;
//ss.erase(pos,num_item);

int main()
{
    int ans = 0;
    char ch;
    cin >> n >> ss;
    for ( int i = 0; i < n; i++ )
    {
        ch = ss[i];
        if ( ch == ss[i+1] && i % 2 == 0 )//下表0开始 
        {
            ans ++;
            ss.erase(i,1);
            i --;
            n --;
        }
    }
    if ( ss.length() % 2 == 1 )
    {
        ss.erase( ss.length() - 1, 1);
        ans ++;
    }
    cout << ans<< endl;
    cout << ss<< endl;
    return 0;
}
