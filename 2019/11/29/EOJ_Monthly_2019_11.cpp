#include <bits/stdc++.h>

using namespace std;

int n,m,k,x;
vector<string> str;
int pos[500010], cc[500010];
char ch[500010];

int main()
{
    scanf("%d %d %d %d",&n, &m, &k, &x);
    int cnt = 0, tmp = x;
    cin >> ch ;
    for ( int i = 0; i < n; i++ )
    {
        if ( ch[i] == '#' ) pos[cnt++] = i;
    }
    cnt = 0;
    tmp --;
    while ( tmp > 0 )
    {
        cc[cnt++] = tmp % k; 
        tmp /= k;
    } 
    string line;
    for ( int i = 1; i <= m; i++ )
    {
        cin >> line;
        sort(line.begin(), line.end());
        str.push_back(line);
    }
    for ( int i = 0, j = m - 1; i < m && j >= 0; i ++ , j --)
    {
        ch[pos[i]] = str[i][cc[j]];
    }
    cout << ch <<endl;
    return 0;
}
