#include<iostream>
#include<string>
#include<cstring>
#include <cstdio>
#include <stdio.h>

using namespace std;

int main(){
	char a[101];
	while(gets(a)){
		for(int i = 0; i < strlen(a); i++){
			if((a[i-1] == ' ' || i == 0) && a[i] != ' '){
				a[i] -= 32;
			}
		}
		cout<<a<<endl;
	}
	return 0;
}
