#include <bits/stdc++.h>

using namespace std;

int n;
char ss[100];

int main()
{
    scanf("%d",&n);
    scanf("%s",ss);
    for ( int i = 0; i < n; i ++ ) {
        if ( ss[i] == '1' ) ss[i] = '0';
        else if ( ss[i] == '0' ) ss[i] = '1';
    }
    printf("%s\n",ss);
    return 0;
}
