#include<iostream>
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<string.h>
#include<vector>
#include<cmath>
#define maxn 200005
using namespace std;
int a[maxn], b[maxn];
 
int main(){
    int n, m;
    int t;
    int cas = 1;
    cin >> t;
    while(t--){
        scanf("%d%d", &n, &m);
        memset(a, 0, sizeof(a));  
        memset(b, 0, sizeof(b));
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < m; i++){
            scanf("%d", &b[i]);
        }
        int i = 0, j = 0;
        printf("Case %d: ", cas++);
        while(i < n && j < m){
            if(a[i] > b[j]) printf("%d", a[i++]);
            else if(a[i] < b[j]) printf("%d", b[j++]);
            else{
                int q = memcmp(a+i, b+j, sizeof(a));
                if(q < 0){
                    while( a[i] == b[j] && j < m ) printf("%d", b[j++]);
                }
                else{
                    while(a[i] == b[j] && i < n) printf("%d", a[i++]);
                }
            }
        }
        while(i < n) printf("%d", a[i++]);
        while(j < m) printf("%d", b[j++]);
        printf("\n");
    }
    return 0;
}
