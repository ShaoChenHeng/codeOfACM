#include <bits/stdc++.h>

using namespace std;

int n,q;
int pos[1010];

struct meizi
{
    int a;
    int b;
    char name[100];
    int rank;
}m[1010];

int cmp( meizi a, meizi b )
{
  if ( a.a != b.a ) return a.a > b.a;
  else
  {
    if ( a.b != b.b ) return a.b > b.b;
    else return a.name < b.name;
  }
}

int main()
{
    scanf("%d",&q);
    while ( q-- )
    {
        scanf("%d",&n);
        for ( int i = 1; i <= n; i ++ )
        {
            scanf("%s",m[i].name);
            scanf("%d %d",&m[i].a, &m[i].b);
            m[i].rank = i;
        }
        sort(m + 1, m + n + 1, cmp);

        for ( int i = 1; i <= n; i ++  ) pos[m[i].rank] = i;
        for ( int i = 1; i <= n; i ++ ) printf("%d ",pos[i]);
        printf("\n");
    }
    return 0;
}
