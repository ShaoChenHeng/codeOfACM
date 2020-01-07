#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;
const int N = 105;
int a[N] ;
int n;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i] ;
    sort(a + 1, a + n + 1) ;
    int cnt = 0;
    for(int i = 1; i <= n; i++) if(a[i] != a[i - 1]) cnt++;
    if(cnt > 3) {
        cout << -1;
        return 0 ;
    }
    if(cnt == 1) {
        cout << 0;
        return 0;
    }
    if(cnt == 2) {
        int mn = a[1], mx = a[n] ;
        if((mx - mn) & 1) cout << mx - mn ;
        else cout << (mx - mn) / 2;
    } else {
        int d = -1;
        for(int i = 2; i <= n; i++) {
            if(a[i] != a[i - 1]) {
                if(d == -1) d = a[i] - a[i - 1];
                else if(a[i] - a[i - 1] != d) d = -1;
            }
        }
        cout << d;
    }
    return 0;
}
