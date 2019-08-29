#include<iostream>
#include<cstring>
using namespace std;
int k,n,ans[35][35],t;
int shudu[35][35],flag;
int b[35][35],c[35][35],d[35][35],e[35][35];
int bb(int x,int y)
{
	int zuo=0;
	if(((x==1||x==4||x==5)&&y==1)||((x==2||x==3)&&y==2)) zuo=1;
	if(((x==1||x==4||x==5)&&y==2)||((x==2||x==3)&&y==3)||(x==6&&y==1)) zuo=2;
	if(((x==4||x==5)&&y==3)||((x==2||x==3)&&y==4)||(x==6&&y==2)) zuo=3;
	if(((x==4||x==5)&&y==4)||((x==2||x==3)&&y==5)||(x==7&&y==1)||(x==6&&y==3)) zuo=4;
	if(((x==4||x==5)&&y==5)||(x==3&&y==6)||(x==6&&y==4)||(x==7&&y==2)) zuo=5;
	return zuo;
}
int cc(int x,int y)
{
	int you=0;
	if(((x==3||x==4||x==7)&&y==1)||((x==5||x==6)&&y==2)) you=5;
	if(((x==3||x==4||x==7)&&y==2)||((x==5||x==6)&&y==3)||(x==2&&y==1)) you=4;
	if(((x==3||x==4)&&y==3)||((x==5||x==6)&&y==4)||(x==2&&y==2)) you=3;
	if(((x==3||x==4)&&y==4)||((x==5||x==6)&&y==5)||(x==1&&y==1)||(x==2&&y==3)) you=2;
	if(((x==3||x==4)&&y==5)||(x==5&&y==6)||(x==2&&y==4)||(x==1&&y==2)) you=1;
	return you;
}
void dfs(int x,int y)
{
	if(flag==1) return;
	if(x==8&&y==1)
	{
		t++;
		if(t==n)
		{
			cout<<"Found"<<endl;
			for(int i=1;i<=2;i++) cout<<shudu[1][i]<<" ";
			for(int i=1;i<=5;i++) cout<<shudu[2][i]<<" ";
			for(int i=1;i<=6;i++) cout<<shudu[3][i]<<" ";
			for(int i=1;i<=5;i++) cout<<shudu[4][i]<<" ";
			for(int i=1;i<=6;i++) cout<<shudu[5][i]<<" ";
			for(int i=1;i<=5;i++) cout<<shudu[6][i]<<" ";
			for(int i=1;i<=2;i++) cout<<shudu[7][i]<<" ";
			cout<<endl;
			flag=1;
		}
		return;
	}
	for(int i=1;i<=k&&flag==0;i++)
	{
		int gong[10];
		//cout<<"x:"<<x<<" y:"<<y<<endl;
		int zuo=0,you=0;
		memset(gong,0,sizeof(gong));
		zuo=bb(x,y),you=cc(x,y);
		if((x==1&&(y==1||y==2))||(x==2&&(y==2||y==3||y==4))||(x==3&&(y==3||y==4))) gong[1]=1;
		if((x==2&&(y==1||y==2))||(x==3&&(y==1||y==2||y==3))||(x==4&&(y==1||y==2))) gong[2]=1;
		if((x==2&&(y==4||y==5))||(x==3&&(y==4||y==5||y==6))||(x==4&&(y==4||y==5))) gong[3]=1;
		if((x==3&&(y==3||y==4))||(x==4&&(y==2||y==3||y==4))||(x==5&&(y==3||y==4))) gong[4]=1;
		if((x==4&&(y==1||y==2))||(x==5&&(y==1||y==2||y==3))||(x==6&&(y==1||y==2))) gong[5]=1;
		if((x==4&&(y==4||y==5))||(x==5&&(y==4||y==5||y==6))||(x==6&&(y==4||y==5))) gong[6]=1;
		if((x==5&&(y==3||y==4))||(x==6&&(y==2||y==3||y==4))||(x==7&&(y==1||y==2))) gong[7]=1;
		//cout<<"zuo:"<<zuo<<" you:"<<you<<" i:"<<i<<" b:"<<b[x][i]<<" c,zuo:"<<c[zuo][i]<<" d,you:"<<d[you][i]<<endl;
		int flag1=0;
		if(b[x][i]==1||(c[zuo][i]==1&&zuo!=0)||(d[you][i]==1&&you!=0)) continue;
		for(int j=1;j<=7;j++)
		{
			if(gong[j]==1&&e[j][i]==1)
			{
				flag1=1;
				break;
			}
		}
		if(flag1==1) continue;
		if(ans[x][y]==0)
		{
			b[x][i]=1;
			c[zuo][i]=1;
			d[you][i]=1;
			for(int j=1;j<=7;j++)
			{
				if(gong[j]==1) e[j][i]=1;
			}
			shudu[x][y]=i;
			if(((x==1||x==7)&&y==2)||((x==2||x==4||x==6)&&y==5)||(x==3||x==5)&&y==6) dfs(x+1,1);
			else dfs(x,y+1);
			b[x][i]=0;
			c[zuo][i]=0;
			d[you][i]=0;
			for(int j=1;j<=7;j++)
			{
				if(gong[j]==1) e[j][i]=0;
			}
		}
		if(ans[x][y]>0)
		{
			if(y==9) dfs(x+1,1);
			else dfs(x,y+1);
		}
	}
}
int main()
{
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	cin>>k>>n;
	for(int i=1;i<=2;i++) cin>>ans[1][i];
	for(int i=1;i<=5;i++) cin>>ans[2][i];
	for(int i=1;i<=6;i++) cin>>ans[3][i];
	for(int i=1;i<=5;i++) cin>>ans[4][i];
	for(int i=1;i<=6;i++) cin>>ans[5][i];
	for(int i=1;i<=5;i++) cin>>ans[6][i];
	for(int i=1;i<=2;i++) cin>>ans[7][i];
	for(int x=1;x<=7;x++)
	{
		for(int y=1;y<=6;y++)
		{
			if(ans[x][y]==0) continue;
			int zuo=0,you=0,gong[10];
			memset(gong,0,sizeof(gong));
			zuo=bb(x,y),you=cc(x,y);
			if((x==1&&(y==1||y==2))||(x==2&&(y==2||y==3||y==4))||(x==3&&(y==3||y==4))) gong[1]=1;
			if((x==2&&(y==1||y==2))||(x==3&&(y==1||y==2||y==3))||(x==4&&(y==1||y==2))) gong[2]=1;
			if((x==2&&(y==4||y==5))||(x==3&&(y==4||y==5||y==6))||(x==4&&(y==4||y==5))) gong[3]=1;
			if((x==3&&(y==3||y==4))||(x==4&&(y==2||y==3||y==4))||(x==5&&(y==3||y==4))) gong[4]=1;
			if((x==4&&(y==1||y==2))||(x==5&&(y==1||y==2||y==3))||(x==6&&(y==1||y==2))) gong[5]=1;
			if((x==4&&(y==4||y==5))||(x==5&&(y==4||y==5||y==6))||(x==6&&(y==4||y==5))) gong[6]=1;
			if((x==5&&(y==3||y==4))||(x==6&&(y==2||y==3||y==4))||(x==7&&(y==1||y==2))) gong[7]=1;
			b[x][ans[x][y]]=1;
			c[zuo][ans[x][y]]=1;
			d[you][ans[x][y]]=1;
			for(int k=1;k<=7;k++)
			{
				if(gong[k]==1) e[k][ans[x][y]]=1;
			}
		}
	}
	dfs(1,1);
	if(t!=n) cout<<"No way"<<endl;
	return 0;
}
/*
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
*/
