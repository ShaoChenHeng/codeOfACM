#include<iostream>
#include<string.h>
#include<cmath>
#include<stdio.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while( n -- )
    {
        int sum = 0;
        char s[10000];
        cin >> s;
        for(int i = 0; i < strlen(s); i++)
        {
            if(s[i] >= 48 && s[i] <= 57) sum++;
        }
        cout << sum <<endl;
    }
    return 0;
}
