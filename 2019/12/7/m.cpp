#include <bits/stdc++.h>

using namespace std;

char ss[600];
int n;
long long int k;

int main()
{
    scanf("%d %lld",&n,&k);
    scanf("%s",ss);
    //cin >> ss;
    long long int _len = strlen(ss), pos = 0;
    for ( long long int i = _len, j = _len - 1; i <= _len -1 + _len; i ++, j -- )
    {
        ss[i] = ss[j];
    }
    //printf("%s\n",ss);
    //printf("hello");
    _len = strlen(ss);
    if ( k % _len == 0 ) pos = _len - 1;
    else pos =  ( k  % _len ) - 1;
    //printf("%lld\n",_len);
    printf("%c\n",ss[pos]);
 
    return 0;
}
