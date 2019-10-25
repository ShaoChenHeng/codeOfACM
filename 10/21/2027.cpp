#include <bits/stdc++.h>
using namespace std;
int cnt[1000];
int main(){
    int n;
    cin>>n;
    string lne;
    getline(cin, lne);
    while(n--)
    {
        getline(cin, lne);
        memset(cnt, 0, sizeof(cnt));
        stringstream ss(lne);
        string word;
        while(ss>>word){
            for(int i = 0; i < word.size(); i ++){
                cnt[word[i]] ++;
            }
        }
        cout<<"a:"<<cnt['a']<<endl;
        cout<<"e:"<<cnt['e']<<endl;
        cout<<"i:"<<cnt['i']<<endl;
        cout<<"o:"<<cnt['o']<<endl;
        cout<<"u:"<<cnt['u']<<endl;
        if(n != 0) cout<<endl;
    }
    return 0;
}
