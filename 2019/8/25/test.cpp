#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector> 
using namespace std;
int x1[555],x2[555],y1[555],y2[555];//开始列号结束列号，开始行号，结束行号
int w,h,n,ans;//宽，高，以及横线的个数
int line[555*6][555*6];
int dire[4][2]={-1,0,1,0,0,-1,0,1};
struct node{int x,y;};

int compress(int *xx1,int *xx2,int w)//开始坐标，结束坐标 
{
	vector<int>v;
	
	for(int i=0;i<n;i++)//将横线本身以及附近两横线存储 
	for(int d=-1;d<=1;d++)
	{
		int nx1=xx1[i]+d;int nx2=xx2[i]+d;
		if(nx1>=1&&nx1<=w) v.push_back(nx1);
		if(nx2>=1&&nx2<=w) v.push_back(nx2);
	}
	//去重
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end()); 
	 
	//离散化后的坐标
	for(int i=0;i<n;i++)
	{
		xx1[i]=find(v.begin(),v.end(),xx1[i])-v.begin();
		xx2[i]=find(v.begin(),v.end(),xx2[i])-v.begin();
	 } 
	return v.size();	
}
 
void bfs(int xx,int yy)
{
	queue<node>q;
	q.push(node{xx,yy});
	line[xx][yy]=1;
	
	while(!q.empty())
	{
		node t=q.front();q.pop();
		int x=t.x;int y=t.y;
		
		for(int i=0;i<4;i++)
		{
			int nx=x+dire[i][0];
			int ny=y+dire[i][1];
			if(nx<0||nx>=h||ny<0||ny>=w)continue;
			if(!line[nx][ny])
			{
				line[nx][ny]=1;
				q.push(node{nx,ny});
			}
		}
	}
}
int main()
{
	while(cin>>w>>h>>n)
	{
		ans=0;memset(line,0,sizeof(line)); 
		
		for(int i=0;i<n;i++)cin>>x1[i];
		for(int i=0;i<n;i++)cin>>x2[i];
		for(int i=0;i<n;i++)cin>>y1[i];
		for(int i=0;i<n;i++)cin>>y2[i];
		 
		 w=compress(x1,x2,w);
		 h=compress(y1,y2,h);
		
		//标记上所在横线上的点
		for(int i=0;i<n;i++)//枚举n条横线
		for(int y=y1[i];y<=y2[i];y++)//枚举行
		for(int x=x1[i];x<=x2[i];x++)//枚举列
		{
			line[y][x]=1;
		 } 
		 
		 //打印查看离散化后的图形 
		 
		 for(int i=0;i<h;i++)
		 {
		 	for(int j=0;j<w;j++)
		 	{
		 		if(line[i][j])cout<<1<<" ";
		 		else cout<<0<<" ";
			 }
			 cout<<endl;
		 }
		 cout<<endl<<ans<<endl;
		 
		  //搜索求区域块数 防止爆栈，这里使用广搜 
		 for(int i=0;i<h;i++)
		 for(int j=0;j<w;j++)
		 {
		 	if(!line[i][j]){
		 		ans++;
		 		bfs(i,j);
			 }
		  } 
		  cout<<ans<<endl;
	}
	
	return 0;
 } 
