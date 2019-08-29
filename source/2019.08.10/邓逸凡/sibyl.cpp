#include<bits/stdc++.h>
using namespace std;
int read();
void inp3000();
void sb3();
void sbt2();
struct edge{
	int to_,next_;
} e[600005];
int head[300005],du[300005];
int tot;
void  Add(int x,int y)
{
	e[++tot].to_=y;
	e[tot].next_=head[x];
	head[x]=tot;
	du[x]++;
}
int N,M,Q;
int now[300005],ltag[300005];
int cnt[300005];
int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	N=read(),M=read(),Q=read();
	bool sb1=true;
	for  (int i=1;i<=M;i++)
		{
			int xx=read(),yy=read();
			Add(xx,yy),Add(yy,xx);
			if  ((xx!=1&&du[xx]>10)||(yy!=1&&du[yy]>10))  sb1=false;
		}
	
	if  (sb1)
		{
			sb3();
		}
	if  (N<=3000&&M<=3000&&Q<=3000)
		{
			inp3000();
		}		
	bool sb2=true;
	for  (int i=1;i<=N;i++)
		if  (du[i]==1)
			cnt[e[head[i]].to_]++;
	
	for  (int i=1;i<=N;i++)
		if  (du[i]!=1&&cnt[i]!=du[i])
			{		
				sb2=false;	
				break;
			}
	if  (sb2)
		sbt2();
	inp3000();
	return 0;
}
int read()
{
	int a=0; char c=getchar();
	for  (;!isdigit(c);c=getchar());
	for  (;isdigit(c);a=a*10+c-48,c=getchar());
	return a;
}
void inp3000()
{
	for  (int i=1;i<=Q;i++)
		{
			int ob=read();
			if  (ob==0)
				{
					int x=read();
					printf("%d\n",now[x]);
				}
			else
				{
					int x=read(),y=read();
					now[x]+=y;
					for  (int j=head[x];j;j=e[j].next_)
						{
							int z=e[j].to_;
							now[z]+=y;
						}
				}
		}
	exit(0);
}
void sb3()
{
	for  (int i=1;i<=Q;i++)
		{
			int ob=read();
			if  (ob==0)
				{
					int x=read();
					if  (x==1)
						printf("%d\n",now[x]);
					else
						{
							int ans=now[x];
							for  (int j=head[x];j;j=e[j].next_)
								{
									int z=e[j].to_;
									ans+=ltag[z];
								}
							printf("%d\n",ans);
						}
				}
			else
				{
					int x=read(),y=read();
					if  (x==1)
						ltag[x]+=y;
					else
						{
							now[x]+=y;	
							for  (int j=head[x];j;j=e[j].next_)
								{
									int z=e[j].to_;
									now[z]+=y;
								}
						}		
				}
		}
	exit(0);
}
void sbt2()
{
	for  (int i=1;i<=Q;i++)
		{
			int ob=read();
			if  (ob==0)
				{
					int xx=read();
					if  (du[xx]==1)
						{
							int yy=e[head[xx]].to_;
							int ans=now[xx]+ltag[yy];
							printf("%d\n",ans);
						}
					else
						{
							int ans=now[xx]+ltag[xx];
							printf("%d\n",ans);
						}
				}
			else
				{
					int xx=read(),zz=read();
					if  (du[xx]==1)
						{
							now[xx]+=zz;
							int yy=e[head[xx]].to_;
							now[yy]+=zz;
						}
					else
						ltag[xx]++;
				}
		}
	exit(0);
}
