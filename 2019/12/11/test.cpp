#include <bits/stdc++.h>

using namespace std;

vector<string> v;

bool cmp(string a, string b)
{
    return a < b;
}

int main()
{
    int n;
    string ss;
    scanf("%d",&n);
    for ( int i = 0; i < n; i ++ )
    {
        cin >> ss;
        v.push_back(ss);
    }
    sort(v.begin(), v.end(), cmp);
    for ( int i = 0; i < n; i ++ )
    {
        cout << v[i]<<endl;
    }


    return 0;
}

