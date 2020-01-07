#include <bits/stdc++.h>

using namespace std;

string ss[1000];

bool cmp( string a, string b )
{
    return a.length() < b.length();
}

int main()
{
    string s;
    int i = 0;

    while ( cin >> s )
    {

        if ( s[0] > 'z' || s[0] < 'a' ) break;
        else ss[i++] = s;
    }
    stable_sort( ss, ss + i, cmp);
    for ( int j = 0; j < i; j ++ ) cout << ss[j] << ' ';
    printf("\n");

    return 0;
}
