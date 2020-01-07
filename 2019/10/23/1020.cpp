#include<stdio.h>
#include<string.h>
char str[10010];

int main()
{
	int n,len,count;
	scanf("%d",&n);
	while( n-- )
	{
		scanf("%s",str);
		len = strlen(str);
		for(int i = 0;i < len;i ++)
		{
			if(str[i]!=str[i+1]) printf("%c",str[i]);
			else
		    {   
		        count = 1;
		    	for(;i < len;i ++)
		    	{
		    		if(str[i] != str[i+1])
		    		{
		    			printf("%d%c",count,str[i]);
		    			break;
		    		}
		    		count ++;
		    	}
		    }
		}
		printf("\n");
	}
	return 0;
}
