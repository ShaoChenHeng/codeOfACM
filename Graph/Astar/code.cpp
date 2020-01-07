#include <bits/stdc++.h>

using namespace std;

queue<int> openList;
queue<int> closeList;
int fatherList[1000];
int graph[1000][1000];
// 1 : pass
// 0 : block
// 8 : begin
// 6 : end

int n;

int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++  )
    {
        for ( int j = 1; j <= n; j++ )
        {
            scanf("%d",&graph[i][j]);
        }
    }

    

    return 0;
}
