#include<iostream>
#include<string>
#include<cstring>
#include <cstdio>

using namespace std;
char ch[10000];
int n;

int main()
{
    while(scanf("%d",&n) != EOF)
    {
        while( n -- )
        {
            cin >> ch;
            int _len = strlen(ch);
            int flag = 1;
            for ( int i = 0; i <= (_len / 2); i++ )
            {
                if ( ch[i] != ch[_len - i - 1] )
                {
                    flag = 0;
                    break;
                }

            }
            if ( flag ) printf("yes\n");
            else printf("no\n");
        }
        
    }
    return 0;
}
