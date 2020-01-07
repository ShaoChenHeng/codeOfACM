#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

int T;
int count[27];

int main()
{
    while ( scanf("%d",&T) != EOF)
    {
        while( T -- )
        {
            memset(count,0,sizeof(count));
            string s;
            cin >> s;
            for ( int i = 0, j, x; i < s.length(); i = j )
            {
                //count[s[i]-97] ++;
                j = i,x = 0;
                for ( ; j <= s.length() && s[i] == s[j]; j ++ ) x ++;
                if ( x & 1 ) count[s[i] - 'a'] = 1;
            }
            for( int i = 0; i < 26; i ++ )
            {
                if ( count[i] ) printf("%c",i+'a');
            }
            printf("\n");
        }
    }
    
    return 0;
}
