#include <iostream>
#include <algorithm>
using namespace std;

int num[100];

int main(){
	int n;
	scanf("%d",&n);
	for ( int i = 1; i <= n; i++ )
	{
		num[i] = i;
	}

    do{
        for ( int i = 1; i <= n; i ++ ) printf("%d", num[i]);
        printf("\n");
    } while(next_permutation(num+1,num+n+1));
    return 0;
}
