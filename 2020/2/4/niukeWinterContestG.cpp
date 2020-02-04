#include <bits/stdc++.h>

using namespace std;

map< char, int > m;
int n, k;
int pos[200010];
string ss;

struct dequeue
{
    deque<int> q;

} que[30];

int main()
{
    scanf("%d %d",&n, &k);
    cin >> ss;
    int len, ans;
    ans = 200010;
    for ( int i = 0; i < n; i ++  )
    {
        pos[i] = i;
        m[ss[i]] ++;
        (que[ss[i]-97].q).push_back(i);
        if ( m[ss[i]] == k )
        {
            len = i - ( que[ss[i]-97].q ).front() + 1;
            ans = min( ans, len );
            m[ss[i]] --;
            ( que[ss[i]-97].q ).pop_front();
        }
    }
    if ( ans == 200010 ) printf("-1\n");
    else printf("%d\n",ans);
    return 0;
}
