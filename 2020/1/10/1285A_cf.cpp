#include <bits/stdc++.h>

using namespace std;

int n;
string ss;
long long int cntl, cntr;

int main()
{
    cntl = 0, cntr = 0;
    scanf("%d",&n);
    cin >> ss;
    for ( int i = 0; i < ss.size();i ++ )
    {
        //cout << ss[i]<<endl;
        if ( ss[i] == 'L' ) cntl ++;
        else cntr ++;
    }
    long long int ans = cntl + cntr + 1;
    printf("%lld\n",ans);

    return 0;
}
