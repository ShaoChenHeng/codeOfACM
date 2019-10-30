#include <bits/stdc++.h>

using namespace std;

int n,l,r;
string ss;

int main()
{

    scanf("%d %d %d",&n,&l,&r);
    getchar() ;
    getline(cin,ss);
    char ch;
    int ans = 0;
    for(int i = 1; i <= l ; ++i)
	{
		ch=ss[n-i];
		if( i != r + 1 )
        {
			if(ch=='1')	++ans;
		}
        else if( i == r + 1 )
        {
			if(ch=='0')	++ans;
		}
	}
    printf("%d\n",ans);
    

    return 0;
}

