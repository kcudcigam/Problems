#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{   int f=1;
  char c=getchar();
  x=0;
  while (!isdigit(c))
  {  if (c=='-') f=-1;
	c=getchar();}
while (isdigit(c))
{ x=(x<<3)+(x<<1)+(c^48);
  c=getchar();}
x*=f;
}
struct node{
	int x[5];
}l,dd[1000005];
int n,a[20],co[17][17][17][17],bo[17][17][17][17],bol[17][17][17][17],ans;
void dfs(int i)
{
	if(i==5)
	{
			if(bo[l.x[1]][l.x[2]][l.x[3]][l.x[4]]==0&&co[l.x[1]][l.x[2]][l.x[3]][l.x[4]]==0)
		{
			memset(bol,0,sizeof(bol));
			int ss=1;
			queue <node> q;
			q.push(l);
			while(!q.empty())
			{
				node y=q.front();q.pop();
				dd[ss]=y;
				if((y.x[1]==0&&y.x[2]==0&&y.x[3]==0&&y.x[4]==0)||(co[l.x[1]][l.x[2]][l.x[3]][l.x[4]]==1))
				{
					for(int pp=1;pp<=ss;pp++)
					{
						co[dd[pp].x[1]][dd[pp].x[2]][dd[pp].x[3]][dd[pp].x[4]]=1;
					}
					break;
				}
				if(bo[y.x[1]][y.x[2]][y.x[3]][y.x[4]]==1||bol[y.x[1]][y.x[2]][y.x[3]][y.x[4]]==1)
				{
					for(int pp=1;pp<=ss;pp++)
					{
						bo[dd[pp].x[1]][dd[pp].x[2]][dd[pp].x[3]][dd[pp].x[4]]=1;
					}
					ans++;
					break;
				}
				bol[y.x[1]][y.x[2]][y.x[3]][y.x[4]]=1;
				for(int k=1;k<=4;k++)
				{
					if(y.x[k]>1)
					{
						y.x[k]--;
						for(int k1=1;k1<=4;k1++)
						{
							if(y.x[k1]==0)
							{
								y.x[k1]=a[y.x[k]];
							}
						}
					}
					else if(y.x[k]==1)
					{
						y.x[k]=0;
					}
					else {continue;}
				}
				ss++;
			}
		}
		//cout<<l.x[1]<<' '<<l.x[2]<<' '<<l.x[3]<<' '<<l.x[4]<<endl;
		return;
	}
	for(int j=0;j<=n;j++)
	{
		l.x[i]=j;
		dfs(i+1);
	}
}
int main(){
	freopen("bob.in","r",stdin);
	freopen("bob.out","w",stdout);
	read(n);
	for(int i=1;i<n;i++)
		read(a[i]);
	dfs(1);
	cout<<ans<<endl;
	return 0;
}

