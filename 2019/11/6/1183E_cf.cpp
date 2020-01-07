#include<bits/stdc++.h>
using namespace std;
int n,k;
string ss;
queue<string> que;
set<string> s;


int main() 
{
    scanf("%d %d",&n,&k);
    cin >> ss;
    string cur,news;
    int cost = 0;

    que.push(ss);
    s.insert(ss);
    while ( !que.empty() )
    {
        cur = que.front();
        que.pop();
        for ( int i = 0; i < cur.size(); i ++ )
        {
            news = cur;
            news.erase(i,1);
            //cout << news <<endl;
            if ( s.size() == k ) break;
            if ( s.size() < k && !s.count(news) )
            {
                s.insert(news);
                cost += (n - news.length());
                que.push(news);
            }
        }
    }
    if ( s.size() < k ) printf("-1\n");
    else printf("%d\n",cost);

    return 0;
}
