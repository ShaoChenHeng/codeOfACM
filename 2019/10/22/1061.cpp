#include<iostream>
using namespace std;
 
long long pow(long long n)
{
	long long d,t;
	d = 1;t = n;
	while( n > 0 )
	{
		if( n & 1 )
			d = ( d * t ) % 10;
		n >>= 1;
		t = ( t * t ) % 10;
	}
	return d;
}
 
int main()
{
	long long n,ans;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=pow(n);
		cout<<ans<<endl;
	}
	return 0;
}
