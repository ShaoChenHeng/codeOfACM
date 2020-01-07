#include <iostream>
using namespace std;
int a[100];
int sum_aver(int* begin, int m)
{
    int ans = 0;
    for(int i=0; i<m; i++)
        ans += begin[i];
    return ans/m;
}
int main()
{
    int n, m, n0, m0;
    for(int i=1; i<=100; i++)//生成有序递增偶数列
        a[i-1]=2*i;
    while(cin>>n>>m)
    {
        n0 = n/m;
        m0 = n-n0*m;
        for(int j=0; j<n0; j++)
        {
            if(j!=0) cout<<" ";
            cout<<sum_aver(a+j*m, m);
        }
        if(m0!=0)
            cout<<" "<<sum_aver(a+n0*m, m0)<<endl;
        else
            cout<<endl;
    }
    return 0;
}

