#include <cstdio>

using namespace std;


int main()
{
	char ch;
	int T,num;
	
	while( scanf("%d",&T) != EOF )
	{
		while ( T -- )
		{
			scanf( "%c %d",&ch,&num );
			if ( 'A' <= ch && ch <= 'Z'  ) printf("%d\n",ch-'A'+num + 1 );
			else  printf("%d\n",num - (ch-'a'+1) );
		}
		
	}

	return 0; 
}

/*#include <iostream>

using namespace std;

int main()
{
	int T;
	int x;char y;int yn;
	cin>>T;
	while(T--)
	{
		cin>>y>>x;
		if(y<='z'&&y>='a') yn=-(y-'a'+1);
		if(y<='Z'&&y>='A') yn=y-'A'+1;
		cout<<yn+x<<endl; 	
	}
}
*/