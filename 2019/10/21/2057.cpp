#include <bits/stdc++.h>
using namespace std;

int main()
{
	__int64 a,b,sum;
	while(scanf("%I64X %I64X",&a,&b)!=EOF)
	{
		sum=a+b;
		if(sum>=0)
			printf("%I64X\n",sum);
		else
			printf("-%I64X\n",-sum);
	}
	return 0;
} 
