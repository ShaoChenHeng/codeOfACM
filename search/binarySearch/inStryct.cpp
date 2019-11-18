#include <bits/stdc++.h>

using namespace std;

int n;

struct node
{
	int a,b;
	node () {}
	node (int a,int b) : a(a), b(b) {}
	bool operator<(const node m)const{
        return a < m.a;
    }
}num[1000];

int main()
{
    scanf("%d", &n);
    for ( int i = 0; i < n; i++ )
    {
    	scanf("%d %d",&num[i].a, &num[i].b);
    }
    sort(num, num + n);
    
    printf("/////////////\n");
    for ( int i = 0; i < n; i++ ) printf("%d %d\n",num[i].a, num[i].b);
    printf("/////////////\n");

    int pos1 = lower_bound(num, num + n, node(3, 0)) - num;
    int pos2 = upper_bound(num, num + n, node(3, 0)) - num;
    printf("pos1 = %d\n", pos1);
    printf("pos2 = %d\n", pos2);
    return 0;
}
