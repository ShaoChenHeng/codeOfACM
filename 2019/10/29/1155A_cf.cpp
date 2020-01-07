#include <bits/stdc++.h>

using namespace std;

string ss;
int n;

int main()
{
    //scanf("%d %s",&n,ss);
    cin >> n >> ss;
    int l = 0,r = 0;
    bool flag = false;



    for ( int i = 1; i < ss.length(); i++ )
    {
        if ( ss[i] < ss[i-1] )
        {
            flag = true;
            int j;
            //printf("i = %d sj = %c sj-1 = %c\n",i,ss[j],ss[j-1]);
            //printf("j = %d sj = %c sj-1 = %c\n",j,ss[j],ss[j-1]);
            for ( j = i + 1; ss[j] < ss[j-1] && j < ss.length(); j++ );
            
            l = i, r = j;
            //printf("l = %d, r = %d\n",l,r);
            break;
        
        }
    } 
    if ( flag ) printf("YES\n%d %d\n",l,r);
    else printf("NO");
    
    return 0;
}


/* int n;
string s;
int main()
{
    cin >> n >> s;
    int l, r;
    bool flag = false;
    for(int i = 1; i < s.length(); i++){
        if(s[i]<s[i-1]){
            flag = true;
            int j;
            for(j = i+1; s[j]<s[j-1] && j<s.length(); j++);
            l = i, r = j;
            break;
        }
    }
    if(flag)
        cout << "YES" << " " <<  l << " " << r << endl;
    else
        cout << "NO" << endl;

	return 0;//
}
 */
