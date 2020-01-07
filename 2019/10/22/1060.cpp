#include<stdio.h>
#include<math.h>

int main()
{
	int t;
	__int64 s,n;
	long double m;
	scanf("%d",&t);
	while(t--){
		scanf("%I64d",&n);
		m=n*log10(n+0.0);
		m-=(__int64)m;
		s=(__int64)pow((long double)10,m);
		printf("%I64d\n",s);
	}
	return 0;
}
