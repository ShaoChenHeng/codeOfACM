#include <bits/stdc++.h>

using namespace std;

struct node
{
    int val, pos;
};

stack <node> s;
int n, ans[3000010];

int main()
{
    scanf("%d",&n);
    node num, item2;
    for ( int i = 1; i <= n; i ++ )
    {
        scanf("%d",&num.val);
        num.pos = i;
        if ( s.empty() ) 
        {
            s.push(num);
        }
        else
        {

            item2 = s.top();
            while ( item2.val < num.val )
            {
                //printf("item = %d\n",item);
                ans[item2.pos] = num.pos;
                s.pop();
                if ( s.empty() ) break;
                item2 = s.top();
            }
            s.push(num);
        } 
    }
    item2 = s.top();
    ans[item2.pos] = 0;
    for ( int i = 1; i <= n; i ++ ) printf("%d ",ans[i]);
    return 0;
}

