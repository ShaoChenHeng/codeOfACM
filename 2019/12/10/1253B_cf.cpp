#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
const int WAIT = 0, ENTERED = 1, LEFT = 2;

int n;
vector<int> off;
vector<int> sec;
int state[N];

int solve()
{
    scanf("%d", &n);
    int len = 0;
    int em;
    for (int i = 1; i <= n; ++i)
    {
        cin >> em;
        int guy = abs(em);
        off.push_back(guy);
        if (em > 0)
        {
            if (state[guy] != WAIT)return false;
            state[guy] = ENTERED;
            ++len;
        }
        else 
        {
            if (state[guy] != ENTERED)return false;
            state[guy] = LEFT;
            --len;
        }
        if (len == 0)
        {
            sec.push_back(off.size());
            for (int x : off) state[x] = WAIT;
            off.clear();
        }
    }
 
    if ( !off.empty() )return false;
    int nDays = sec.size();
    cout << nDays << endl;
    for (auto t : sec)
    {
        cout << t << " ";
    }
    return true;
}
 
int main()
{
    if (!solve()) cout << "-1\n";
    return 0;
}
