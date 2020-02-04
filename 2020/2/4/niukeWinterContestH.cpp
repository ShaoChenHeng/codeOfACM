#include <bits/stdc++.h>

using namespace std;

int n, k;
string ss;

int main()
{
    scanf("%d %d", &n, &k);
    cin >> ss;
    int left, right;
    int cnt0, cnt1, sum;
    left = right = 0;
    cnt0 = cnt1 = sum = 0;
    int ans = 1, len;
    while ( right <= n - 1 )
    {
        if ( ss[right] == '0' ) cnt0 ++;
        else cnt1 ++;
        sum ++;
        if ( cnt0 <= k || cnt1 <= k )
        {
            len = sum;
            ans = max(len, ans);
        }
        else
        {
            if ( ss[left] == '0' ) cnt0 --;
            else cnt1 --;
            left ++;
            sum --;
            len = sum;
            ans = max(len, ans);
        }
        right ++;
    }
    printf("%d\n", ans);
    return 0;
}
